#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: cp source destination\n");
        return 1;
    }

    // TODO: copy the contents of argv[1] to argv[2]
    FILE *source = fopen(argv[1], "r");
    FILE *destination = fopen(argv[2], "a");
    int x;
    while ((x = fgetc(source)) != EOF)
    {
        fputc(x, destination);
    }
    fclose(source);
    fclose(destination);
    
    return 0;
}

