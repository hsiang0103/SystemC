#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    int i = 0;
    for (i = 1; argv[i] != NULL; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return (0);
}

