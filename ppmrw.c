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
int readFile(int ppmFormat, char *inputFile,char *outputFile);

// structs decoration
typedef struct ppmRGBpixel
{
    unsigned char r,g,b;
} ppmRGBpixel;

typedef struct ppmImage
{
    int width, heigth, maxColorInten;
    unsigned char *data;
} ppmImage;

// ppmImage *buffer;
//writer the file in P3
int writeP3(char *inputFile, char *outputFile)
{
    //FILE* write = open(outputFile,"w");
    //fwrite();
    //fclose();
    printf("Wrote to %c in P3 format\n", *outputFile);
    return 0;
}

// write the file in P6
int writeP6(char *inputFile, char *outputFile)
{
    printf("Wrote to %c in P6 format\n", *outputFile);
    return 0;
}

int readFile(int ppmFormat, char *inputFile,char *outputFile)
{
    // convent file in to a ppm3 format
    char *buffer;
    long numOfBytes;
    // open the file
    FILE *read = fopen(inputFile, "rb");
    // check if the file is real
    if (read == NULL)
    {
        fprintf(stderr, "Error: %s doen't not contant any data to be read\n", inputFile);
        return 1;
    }
    // get the number of bytes
    fseek(read, 0L, SEEK_END);
    numOfBytes = ftell(read);

    //reset the pointer to the beginning of the file
    fseek(read, 0L, SEEK_SET);

    //grab sufficient memory for the buffer to hold the file
    buffer = (char*)calloc(numOfBytes, sizeof(char));

    // memory Error
    if (buffer == NULL)
    {
        return 1;
    }

    // copy all the text into the buffer
    fread(buffer, sizeof(char), numOfBytes, read);
    fclose(read);
    printf("%s was read and contants:\n %s", inputFile, buffer);
    free(buffer);

    /*
    int ppmVal = fgetc(read);
    printf("%d\n", ppmVal);

    if (ppmVal != 'P')
    {
        fprintf(stderr, "Error: Missing the magic number\n");
        return 1;
    }
    ppmVal = fgetc(read);
    printf("%c\n", ppmVal);
    if (ppmVal != '3' && ppmVal != '6')
    {
        fprintf(stderr, "Error: Incorrect ppm file number\n");
        return 1;
    }
    if (ppmVal == 3)
    {
        writeP3(inputFile, outputFile);
    }
    */
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
    //
    if (ppmFormat != 3 && ppmFormat != 6)
    {
        fprintf(stderr, "Error: Incorrect conversion number type \n");
        return 1;
    }
    readFile(ppmFormat,inputFile,outputFile);
    return 0;
}
