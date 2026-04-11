
#ifndef list_H
#define list_H

typedef struct cell {
char* data;
struct cell* next;
} Cell;
typedef Cell* List;
List* initList();
Cell* buildCell(char* ch);
void insertFirst(List *l, Cell* C);
char* ctos(Cell* c);
char* ltos(List* l );
Cell* listGet(List* L, int i);
Cell* searchList(List* l, char* str);
List* stol(char* s);
void ltof(List* L, char* path);
List* ftol(char*path);
#endif
