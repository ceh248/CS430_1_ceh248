#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *ppmFormat = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    int errorNum;
    FILE *ppmFile;

    if (argc != 4)
    {
        perror("Incorrect amout of arguments\n");
        return 1;
    }

    if (ppmFormat == 3)
    {
        ppmWriterp3();
    }
    else if (*ppmFormat == 6)
    {
        ppmWritep6();
    }
    else
    {
        fprintf(stderr, "Error: Incorrect conversion number type %s\n");
    }
    return 0;
}
