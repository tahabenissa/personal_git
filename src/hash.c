#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int hashFile(char* source, char* dest)
{
    char command[500];

    sprintf(command,
            "sha256sum %s | cut -d ' ' -f1 > %s",
            source,
            dest);

    return system(command);
}
char* sha256file(char* file)
{
    static char template[] = "/tmp/myfileXXXXXX";
    char fname [1000];
    strcpy(fname , template);
    int fd = mkstemp(fname);  
    hashFile(file, fname);
    FILE* f = fopen(fname, "r");
    char* hash = malloc(65);
    fscanf(f, "%s", hash);
    fclose(f);
    unlink(fname);
    return hash;
}
