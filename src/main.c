#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "list.h"

int main()
{
    List* l =ftol("tests/test1.txt");
    Cell* c =*l;
    while(c){
        printf("%s->",c->data);
        c=c->next;
    }
    printf("null");
    return 0;
}