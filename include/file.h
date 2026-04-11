#ifndef file_H
#define file_H
List* listdir(char* path);
int file_exists(char *file);
void cp(char *to, char *from);
char* hashToPath(char* hash);
void blobFile(char* file);

#endif