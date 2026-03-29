#include<stdio.h>
#include<stdlib.h>
#include "list.h"
List* initList()
{
    List* L = (List*)malloc(sizeof(List));
    *L = NULL;
    return L;
}
Cell* buildCell(char* ch){
    Cell* c = (Cell*)malloc(sizeof(Cell));
    c->data = ch;
    c->next = NULL;
    return c;
}
void insertFirst(List *L, Cell* C)
{
    C->next = *L;
    *L = C;
}
