#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
List* initList()
{
    List* p = (List*)malloc(sizeof(List));
    *p = NULL;
    return p;
}
Cell* buildCell(char* ch){
    Cell* c = (Cell*)malloc(sizeof(Cell));
    c->data = ch;
    c->next = NULL;
    return c;
}
void insertFirst(List *l, Cell* C)
{

    C->next = *l;
    *l = C;
}
char* ctos(Cell* c){
   
    if (c == NULL || c->data == NULL)
        return NULL;
    char* str = (char*) malloc(strlen(c->data) + 1);
    if (!str)
        return NULL;
    strcpy(str, c->data);

    return str;

}
char* ltos(List* l ){
    
    if (l == NULL || *l == NULL)
        return NULL;

    Cell* c= *l;
    int count=0; 
    while (c){
        count+=strlen(c->data)+1;
        c=c->next;
    }
    c=*l;
    char* str=(char*)malloc(count+1);
    str[0] = '\0';
    while (c){
        char* next= ctos(c);
        strcat(str,next);
        c=c->next;
        strcat(str,"|");
        free(next);
        
        
    }
    return str;

}
Cell* listGet(List* l, int i){
    Cell* c=*l;
    for (int k=1 ; k<i;k++){
        c=c->next;
    }
    return c;

}
Cell* searchList(List* l, char* str){
    Cell* c=*l;
    while(c){
        if (strcmp(str,c->data)==0){
            return c;
        }else{
            c=c->next;
        }

    }
    return NULL;

}
List* stol(char* s){
    List* l = initList();

    char* scpy = (char*)malloc(strlen(s)+1);

    strcpy(scpy,s);

    char* str = strtok(scpy,"|");

    while(str != NULL){

        char* word = (char*)malloc(strlen(str)+1);
        strcpy(word, str);
        Cell* c = buildCell(word);
        insertFirst(l,c);

        str = strtok(NULL,"|");
    }

    free(scpy);
    return l;
}
void ltof(List* L, char* path){
    char* str = ltos(L);
    FILE* f = fopen(path, "w");
    fprintf(f,"%s",str);
    fclose(f);
    free(str); 
}
List* ftol(char*path){
    FILE* f=fopen(path,"r");
    if(!f){
        printf("error opening file\n");
        return NULL;
    }
    fseek(f,0,SEEK_END);
    long size = ftell(f);
    rewind(f);
    char* str=(char*)malloc(size+1); 
    fscanf(f,"%s",str);

    List *l=stol(str);
    free(str);
    return l;

}
