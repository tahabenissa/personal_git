#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
#include "work.h"
#include "hash.h"
#include "file.h"
WorkFile* createWorkFile(char* name){
    WorkFile* work=malloc(sizeof(WorkFile));

    work->name=name;
    work->hash=NULL;
    work->mode=0;                                                                               
    return work;


}
char* wfts(WorkFile* wf){
    char* str =(char*)malloc(strlen(wf->name)+sizeof(int)+strlen(wf->hash));
    //str="/0";
    strcat(str,wf->name);
    strcat(str,"\t");
    strcat(str,wf->hash);
    char mode[100];

    sprintf(mode, "%d", wf->mode);
    strcat(str,"\t");
    strcat(str,mode);//sprintf(str, "%s\t%s\t%d", wf->name, wf->hash, wf->mode);
    return str;
}
WorkFile* stwf(char* ch){
    char* str =(char*)malloc(strlen(ch));
    strcpy(str,ch);
    char * mot = strtok ( str, " " );
    WorkFile* work=createWorkFile(mot);
    mot=strtok(NULL," ");
    work->hash=mot;
    mot=strtok(NULL," ");
    work->mode=atoi(mot);
    return work;

}
WorkTree* initWorkTree(){
    

}

