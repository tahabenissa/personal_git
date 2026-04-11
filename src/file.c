#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"hash.h"
List* listdir(char* path){

    DIR * dp = opendir (path);
    struct dirent *ep;
    List* l = initList();
    if (dp != NULL)

    {
        while ((ep = readdir (dp)) != NULL)
        {
            Cell* c = buildCell(ep->d_name);
            insertFirst(l,c);
        }
    }
    return l;


}
int file_exists(char *file)
{
    List *l = listdir(".");  
    
    if (!l)
        return 0;

    Cell *c = *l;

    while (c)
    {
        if (strcmp(file, c->data) == 0)
        {
            return 1;
        }
        c = c->next;
    }
    return 0;
}
void cp(char *to, char *from){
    if(file_exists(to)==0 || file_exists(from)==0){
        printf("le fichier n existe pas ");
    }else{  
        char* cmd;

        sprintf(cmd, "cp %s %s", from, to); //mahyech securisee lzmni nrj3 nriglha 5tr shell injection
        system(cmd);


    }

}
char* hashToPath(char* hash){
    char* str=(char*)malloc(strlen(hash)+1);
    str[0]= hash[0];
    str[1]= hash[1];
    str[2]= '/';
    strcpy(str+3,hash+2);
    return str ;      
}
#include <stdio.h>
#include <stdlib.h>

void blobFile(char* file)
{

    char* hash = sha256file(file);
    char cmd1[256];
    snprintf(cmd1, sizeof(cmd1),
             "mkdir -p .mine/objects/%.2s", hash);

    system(cmd1);

    char* path = hashToPath(hash);
    char cmd2[512];
    snprintf(cmd2, sizeof(cmd2),
             "cp '%s' '.mine/objects/%s'", file, path);

    system(cmd2);
    free(hash);
    free(path);
}