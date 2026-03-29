#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main()
{
    char* h1 = sha256file("src/main.c");
    char* h2 = sha256file("src/main.c");

    printf("hash1 = %s\n",h1);
    printf("hash2 = %s\n",h2);

    free(h1);
    free(h2);

    return 0;
}