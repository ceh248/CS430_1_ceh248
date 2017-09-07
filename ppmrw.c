/*******************************************
 * Author: Colter Hooker
 * CS 430 - Computer Graphic for NAU
 * Project 1 images
 ******************************************/

#include <stdlib.h>
#include <stdio.h>

// function decoration
int writeP3(char *inputFile, char *outputFile);
int writeP6(char *inputFile, char *outputFile);

// structs
typedef struct ppmRGBpixel
{
    unsigned char r,g,b;
} ppmRGBpixel;

typedef struct ppmImage
{
    int width, heigth, maxColorInten;
    unsigned char *data;
} ppmImage;

//
ppmImage *buffer;
//writer the file in P3
int writeP3(char *inputFile, char *outputFile)
{
    printf("Wrote to %c in P3 format\n", *outputFile);
    return 0;
}

// write the file in P6
int writeP6(char *inputFile, char *outputFile)
{
    printf("Wrote to %c in P6 format\n", *outputFile);
    return 0;
}

ppmImage readFile(int ppmFormat, char *inputFile,char *outputFile)
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
    if (ppmVal == 3)
    {
        writeP3(inputFile, outputFile);
    }
    exit(0);
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
    //
    if (ppmFormat != 3 && ppmFormat != 6)
    {
        fprintf(stderr, "Error: Incorrect conversion number type \n");
        return 1;
    }
    readFile(ppmFormat,inputFile,outputFile);
    return 0;
}
