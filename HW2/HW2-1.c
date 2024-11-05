#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/*
0        1         2         3         4         5         6         7         8
12345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

int CHAR_COUNT(char filename[])
{
    FILE *fp;
    char buffer[1024];
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("%s Open failure\n", filename);
        return 0;
    }
    else
    {
        printf("%s Open success\n\n", filename);
    }
    int characters = 0, uppercase = 0, words = 0, lines = 0, inword = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (isalnum(buffer[i]))
            {
                characters++;
            }
            if (isupper(buffer[i]))
            {
                uppercase++;
            }
            if (buffer[i] == '\n' || buffer[i] == EOF)
            {
                lines++;
            }
            if ((buffer[i] == '\n' || buffer[i] == ' ') && inword)
            {
                words++;
                inword = 0;
            }
            else
            {
                inword = 1;
            }
        }
    }
    lines++;
    printf("There are\nLines     :%-4d\n", lines);
    printf("Characters:%-4d\n", characters);
    printf("Uppercases:%-4d\n", uppercase);
    printf("Words     :%-4d\n", words);
    fclose(fp);
    return 0;
}

int UPPER_WRITE(char filename[])
{
    FILE *fp;
    char buf[1024];
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("%s Open failure\n", filename);
        return 0;
    }
    else
    {
        printf("%s Open success\n\n", filename);
    }
    FILE *fp2;
    fp2 = fopen("UPPER.txt", "w");
    if (fp2 == NULL)
    {
        printf("UPPER.txt Open failure\n");
        return 0;
    }
    else
    {
        printf("UPPER.txt Open success\n");
    }

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        char UPPER[1024] = "";
        for (int i = 0; i < strlen(buf); i++)
        {
            UPPER[i] = toupper(buf[i]);
        }
        fprintf(fp2, "%s", UPPER);
    }
    printf("UPPER.txt Write success\n");
    fclose(fp);
    fclose(fp2);
    return 0;
}

int main(int argc, char *argv[])
{
    char filename[100];
    strcpy(filename, argv[1]);
    strcat(filename, ".txt");
    CHAR_COUNT(filename);
    printf("\n");
    UPPER_WRITE(filename);
    return (0);
}