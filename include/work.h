#ifndef WORK_H
#define WORK_H
typedef struct {
    char* name;
    char* hash;
    int mode;
} WorkFile;
typedef struct {
    WorkFile* tab;
    int size;
    int n;
} WorkTree;
WorkFile* createWorkFile(char* name);
char* wfts(WorkFile* wf);
WorkFile* stwf(char* ch);



#endif