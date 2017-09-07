/*******************************************
 * Author: Colter Hooker
 * CS 430 - Computer Graphic for NAU
 * Project 1 images
 ******************************************/

#include <stdlib.h>
#include <stdio.h>

// tpye def decoration
typedef struct ppmRGBpixel
{
    unsigned char r,g,b;
} ppmRGBpixel;

typedef struct ppmImage
{
    int width, heigth, maxColorInten;
    unsigned char *data;
} ppmImage;

ppmImage *buffer;
// function decoration

// ppm writer p3
ppmImage ppmRead(int ppmFormat, char *inputFile,char *output)
{
    // convent file in to a ppm3 format
    buffer = (ppmImage*)malloc(sizeof(ppmImage));
    FILE *data = fopen(inputFile, "rb");
    int ppmVal = fgetc(data);
    printf("%d\n", ppmVal);
    if (data == NULL)
    {
        fprintf(stderr, "%s doen't not contant any data to be read\n", inputFile);
        exit(1);
    }
    if (ppmVal != 'P')
    {
        fprintf(stderr, "Error: Missing the magic number\n");
        exit(1);
    }
    ppmVal = fgetc(data);
    printf("%c\n", ppmVal);
    if (ppmVal != '3' && ppmVal != '6')
    {
        fprintf(stderr, "Error: Incorrect ppm file number\n");
        exit(1);
    }

    printf("Wrote to %s in P3 format\n", output);
    exit(0);
}

// pp writer p3
int ppmWriterp3(char *input, char *output)
{
    printf("Wrote to %s in p3 format\n", *output);
    return 0;
}
// ppm writer p6
int ppmWritep6(char *input,char *output)
{
    // convet file in to a ppm6 format
    printf("Wrote to %s in P6 format\n", output);
    return 0;
}

/*
 * main function to run a conversion of a ppm file
 */
int main(int argc, char *argv[])
{
    int ppmFormat = atoi(argv[1]); // need fixing
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    if (argc != 4)
    {
        fprintf(stderr, "Error: Incorrect amount of arguments\n");
        return 1;
    }
    if (ppmFormat == 3)
    {
        ppmRead(ppmFormat,inputFile,outputFile);
    }
    else if (ppmFormat == 6)
    {
        ppmWritep6(inputFile,outputFile);
    }
    else
    {
        fprintf(stderr, "Error: Incorrect conversion number type \n");
    }
    return 0;
}
