#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "list.h"
#include "file.h"
#include "hash.h"
#include "work.h"


int main()
{
    // char* path="src/main.c    314badfa8a8dd6ebac6a7a101912d80e3f077f83d7e02dca3eb4b50cc717b901    0";
    // WorkFile* work= stwf(path);
    // printf("le nom = %s \n le hash est = %s \n le mode est = %d \n",work->name,work->hash ,work->mode);
    
    WorkTree* wt=initWorkTree();

    appendWorkTree(wt,"a","h1",644);
    appendWorkTree(wt,"b","h2",644);
    appendWorkTree(wt,"dir",NULL,0);

    wttf(wt,"test");
    WorkTree* wt2=ftwt("test");
    char* str =wtts(wt2);
    printf("ena wt2= %s\n", str);

    return 0;
}