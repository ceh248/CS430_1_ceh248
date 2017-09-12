/*******************************************
 * Author: Colter Hooker
 * CS 430 - Computer Graphic for NAU
 * Project 1 images
 ******************************************/

#include <stdlib.h>
#include <stdio.h>

// structs decoration
typedef struct ppmRGBpixel
{
    unsigned char r,g,b;
} ppmRGBpixel;

typedef struct ppmImage
{
    int magicNumber, width, heigth, maxColorInten;
    unsigned char *data;
} ppmImage;

// function decoration
int writeP3toP3(char *inputFile, char *outputFile, char *buffer, long numOfBytes);
int writeP6toP6(char *inputFile, char *outputFile, char *buffer, long numOfBytes);
int writeP3FromP6(char *inputFile, char *outputFile,char *buffer, long numOfBytes);
int writeP6FromP3(char *inputFile, char *outputFile,char *buffer, long numOfBytes);
int readFile(int ppmFormat, char *inputFile,char *outputFile, ppmImage inputImage);

// ppmImage *buffer;
//writer the file in P3
int writeP3toP3(char *inputFile, char *outputFile,char *buffer, long numOfBytes)
{
    FILE* write = fopen(outputFile,"w");
    fwrite(buffer, sizeof(buffer),numOfBytes,write);
    fclose(write);
    printf("Wrote to %c in P3 format\n", *outputFile);
    free(buffer);
    return 0;
}

// write the file in P6
int writeP6toP6(char *inputFile, char *outputFile, char * buffer, long numOfBytes)
{
    FILE* write = fopen(outputFile,"w");
    fwrite(buffer, sizeof(buffer),numOfBytes,write);
    fclose(write);
    printf("Wrote to %c in P6 format\n", *outputFile);
    free(buffer);
    return 0;
}

//write to a file in P3 format from a P6 format
int writeP3FromP6(char *inputFile, char *outputFile,char *buffer, long numOfBytes)
{
    //
    printf("Write to %c in P3 from P6\n", *outputFile);
    return 0;
}
//write to a file in P6 format from a P3 format
int writeP6FromP3(char *inputFile, char *outputFile,char *buffer, long numOfBytes)
{
    //
    printf("Write to %c in P6 from P3\n", *outputFile);
    return 0;
}

// read in the input file to be stored to memory and then determine
// what writing porcess to do
int readFile(int ppmFormat, char *inputFile, char *outputFile, ppmImage inputImage)
{
    // temp Variable for the image
    int tempMagicNumber, tempWidth,tempHeight,tempMaxColorValue, red, green, blue, alpha;
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
    printf("%s was read and contants:\n%s", inputFile, buffer);

    /*
     * want to write to the file in the correct way
     */
    FILE *readAgain = fopen(inputFile, "rb");
    int ppmVal = fgetc(readAgain);
    if (ppmVal != 'P')
    {
        fprintf(stderr, "Error: Missing the magic number\n");
        return 1;
    }
    //tempMagicNumber = fscanf(readAgain, "%d", &inputImage.magicNumber);
    //printf("%d\n", inputImage.magicNumber);
    ppmVal = fgetc(readAgain);

    if (ppmVal != '3' && ppmVal != '6')
    {
        fprintf(stderr, "Error: Incorrect ppm file number\n");
        return 1;
    }
    tempWidth = fscanf(readAgain, "%d %d", &inputImage.width, &inputImage.heigth);
    printf("%d\n%d\n", inputImage.width, inputImage.heigth);

    /*
     * to determine where to write the file too
     */
    if (ppmVal == '3' && ppmFormat == 3)
    {
        writeP3toP3(inputFile, outputFile, buffer, numOfBytes);
    }
    if (ppmVal == '6' && ppmFormat == 6)
    {
        writeP6toP6(inputFile, outputFile, buffer, numOfBytes);
    }
    fclose(readAgain);
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

    // Variable to used to see if the file exist
    FILE *fileExist;

    if (argc != 4)
    {
        fprintf(stderr, "Error: Incorrect amount of arguments\n");
        return 1;
    }
    // check to see if correct format number
    if (ppmFormat != 3 && ppmFormat != 6)
    {
        fprintf(stderr, "Error: Incorrect conversion number type \n");
        return 1;
    }
    // check to see if input file exites
    if (!(fileExist = fopen(inputFile,"r")))
    {
        // file not found
        fprintf(stderr, "Error: Input file %s was not found\n", inputFile);
        return 1;
    }
    // read the file into the ppm Image struct
    ppmImage *inputImage = malloc(sizeof(ppmImage));
    // go to the read file
    readFile(ppmFormat,inputFile,outputFile, *inputImage);
    fclose(fileExist);
    return 0;
}
