#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
#include "work.h"
#include "hash.h"
#include "file.h"
WorkFile* createWorkFile(char* name){
    WorkFile* work=malloc(sizeof(WorkFile));

    work->name=strdup(name);
    work->hash=NULL;
    work->mode=0;                                                                               
    return work;


}
char* wfts(WorkFile* wf){

    char* str;

    if(wf->hash != NULL){
        str = malloc(strlen(wf->name) + strlen(wf->hash) + 50);
        sprintf(str,"%s\t%s\t%d", wf->name, wf->hash, wf->mode);
    }
    else{
        str = malloc(strlen(wf->name) + 50);
        sprintf(str,"%s\t%s\t%d", wf->name," ",wf->mode);
    }

    return str;
}
// char* wfts(WorkFile* wf){
//     char* str =(char*)malloc(strlen(wf->name)+sizeof(int)+strlen(wf->hash));
//     str[0]="/0" ; 
//     strcat(str,wf->name);
//     strcat(str,"\t");
//     strcat(str,wf->hash);
//     char mode[100];

//     sprintf(mode, "%d", wf->mode);//int to char
//     strcat(str,"\t");
//     strcat(str,mode);//sprintf(str, "%s\t%s\t%d", wf->name, wf->hash, wf->mode);
//     return str;
// }
// WorkFile* stwf(char* ch){
//     char* str =(char*)malloc(strlen(ch));
//     strcpy(str,ch);
//     char * mot = strtok ( str, "\t" );
//     WorkFile* work=createWorkFile(mot);
//     mot=strtok(NULL,"\t");
//     work->hash=mot;
//     mot=strtok(NULL,"\t");
//     work->mode=atoi(mot);//char* to int 
//     return work;

// }
WorkFile* stwf(char* ch){

    char* str = strdup(ch);
    char* saveptr2;

    char* name = strtok_r(str,"\t",&saveptr2);
    char* hash = strtok_r(NULL,"\t",&saveptr2);
    char* mode = strtok_r(NULL,"\t",&saveptr2);

    WorkFile* work = createWorkFile(name);

    if(hash != NULL && strlen(hash) > 0)
        work->hash = strdup(hash);
    else
        work->hash = NULL;

    if(mode != NULL)
        work->mode = atoi(mode);
    else
        work->mode = 0;

    free(str);

    return work;
}
WorkTree* initWorkTree(){
    WorkTree* wt=malloc(sizeof(WorkTree));
    wt->tab=malloc(100*sizeof(WorkFile));
    wt->size=100;
    wt->n=0;
    return wt;
}
int inWorkTree(WorkTree* wt, char* name){
    int i=0;
    while (i<wt->n){

        if (strcmp(name,wt->tab[i].name)==0 ){
            return i;
            //printf("hethy el i mt fonction =  %d" , i);
        }        
        i++;

    

}
    return -1;
}
// int getChmod(const char *path){
//     struct stat ret;
//     if (stat(path, &ret) == -1) {
//         return -1;
//     }
//     return
//     (ret.st_mode & S_IRUSR)|(ret.st_mode & S_IWUSR)|(ret.st_mode & S_IXUSR)|/*owner*/
//     (ret.st_mode & S_IRGRP)|(ret.st_mode & S_IWGRP)|(ret.st_mode & S_IXGRP)|/*group*/
//     (ret.st_mode & S_IROTH)|(ret.st_mode & S_IWOTH)|(ret.st_mode & S_IXOTH);/*other*/
// }
// void setMode(int mode, char* path){
//     char buff [100];
//     sprintf(buff, "chmod %d %s", mode, path);
//     system(buff);
// }
// int appendWorkTree(WorkTree* wt, char* name, char* hash, int mode){
//     if (inWorkTree(wt,name)==-1 && wt->n !=100){
//         WorkFile* file = createWorkFile(name);
//         file->mode=mode;
//         file->hash= strdup(hash);
//         wt->tab[wt->n]=*file;
//         wt->n+=1;
//         return 1;

//     }
//     printf("le fichier ou la direcrtory  existe deja ");
//     return -1;
// }
int appendWorkTree(WorkTree* wt, char* name, char* hash, int mode){

    if(inWorkTree(wt,name)==-1 && wt->n < wt->size){

        WorkFile* file = createWorkFile(name);

        file->mode = mode;

        if(hash != NULL)
            file->hash = strdup(hash);
        else
            file->hash = NULL;

        wt->tab[wt->n] = *file;
        wt->n++;

        return 1;
    }

    return -1;
}
char* wtts(WorkTree* wt){
    
    int total = 0;
    for(int i=0; i<wt->n; i++){
        total += strlen(wt->tab[i].name);

        if(wt->tab[i].hash != NULL){
            total += strlen(wt->tab[i].hash);
        }
        total += 50;
    }
    char* str = malloc(total + 1);
    str[0] = '\0';
    for(int i=0; i<wt->n; i++){

        char* temp = wfts(&(wt->tab[i]));

        strcat(str, temp);
        strcat(str, "\n");

        free(temp);
    }
    return str;


}

WorkTree* stwt(char* ch){

    char* str = strdup(ch);
    char* saveptr1;
    WorkTree* wt = initWorkTree();
    //printf("ena stwt str = %s\n",str );

    char* chaine = strtok_r(str,"\n", &saveptr1);
    //printf("ena str baad el strtok = %s\n",str );
    //printf("ena star louwel = %s\n",chaine );

    while(chaine != NULL){

        WorkFile* wf = stwf(chaine);

        appendWorkTree(wt,strdup(wf->name),wf->hash ? strdup(wf->hash):NULL, wf->mode);
    
        //printf("ena f  wost el function == %s\n",chaine);
        free(wf);
        chaine = strtok_r(NULL,"\n",&saveptr1);
        //printf("ena star jeya = %s\n",chaine );
    }

    free(str);
    return wt;
}
int wttf(WorkTree* wt, char* file){
    char* str = wtts(wt);
    //printf(" ena f wost f = %s", str);
    FILE* f = fopen(file, "w");
    fprintf(f,"%s",str);
    fclose(f);
    free(str); 
    return 0; 
}

WorkTree* ftwt(char* file){
   FILE* f=fopen(file,"r");
    if(!f){
        printf("error opening file\n");
        return NULL;
    }
    fseek(f,0,SEEK_END);
    long size = ftell(f);
    rewind(f);
    char* str=(char*)malloc(size+1); 
    //fscanf(f,"%s",str);
    
    fread(str,1,size,f);   // ✅ READ FULL FILE

    str[size] = '\0';

    printf("ena str f wsot func = %s\n", str);
    WorkTree* wt=initWorkTree();
    wt=stwt(str);
    return wt;

}






