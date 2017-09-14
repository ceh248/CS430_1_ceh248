/*******************************************
 * Author: Colter Hooker
 * CS 430 - Computer Graphic for NAU
 * Project 1 images
 ******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 256

// structs decoration
typedef struct ppmRGBpixel
{
    unsigned char r,g,b;
} ppmRGBpixel;

typedef struct ppmImage
{
    unsigned char magicNumber;
    int width, heigth, maxColorInten;
    ppmRGBpixel *data;
} ppmImage;

// function decoration
int writeP3(char *inputFile, char *outputFile, ppmImage inputImage, FILE *inFile, FILE *outFile);
int writeP6(char *inputFile, char *outputFile, ppmImage inputImage, FILE *inFile, FILE *outFile);
int readFile(int ppmFormat, char *inputFile,char *outputFile, ppmImage inputImage, FILE *inFile, FILE *outFile);

//write to a file in P3 format from a P6 format
int writeP3(char *inputFile, char *outputFile, ppmImage inputImage, FILE *inFile, FILE *outFile)
{
    //
    char buffer[256], *fileHeader;
    FILE* write = fopen(outputFile,"w");
    inputImage.data = (ppmRGBpixel *)malloc(sizeof(ppmRGBpixel) * inputImage.width * inputImage.heigth);
    fprintf(write, "P3\n%d %d\n%d\n",inputImage.width, inputImage.heigth, inputImage.maxColorInten);
    fclose(write);
    printf("Wrote to %s in P3 from P%c\n", outputFile, inputImage.magicNumber);
    return 0;
}
//write to a file in P6 format from a P3 format
int writeP6(char *inputFile, char *outputFile, ppmImage inputImage, FILE *inFile, FILE *outFile)
{
    //
    char buffer[SIZE], *fileHeader;
    fileHeader = fgets(buffer,SIZE, inFile);
    FILE* write = fopen(outputFile,"w");
    inputImage.data = (ppmRGBpixel *)malloc(sizeof(ppmRGBpixel) * inputImage.width * inputImage.heigth);
    fprintf(write, "P6\n%d %d\n%d\n",inputImage.width, inputImage.heigth, inputImage.maxColorInten);
    //read the ascii file, convert the characters to int, and store it in our buffer
    /*
    for (int wtxt=0; wtxt <inputImage.width * inputImage.heigth; wtxt++)
    {
        //
        int curVal;

    }
    */
    fclose(write);
    printf("Wrote to %s in P6 from P%c\n", outputFile, inputImage.magicNumber);
    return 0;
}

// read in the input file to be stored to memory and then determine
// what writing porcess to do
int readFile(int ppmFormat, char *inputFile, char *outputFile, ppmImage inputImage, FILE *inFile, FILE *outFile)
{
    // temp Variable for the image
    int tempMagicNumber, tempWidth,tempHeight,tempMaxColorValue, checkwh;

    /*
     * want to write to the file in the correct way
     */
    FILE *read = fopen(inputFile, "rb");
    int ppmVal = fgetc(read);
    if (ppmVal != 'P')
    {
        fprintf(stderr, "Error: Missing the magic number\n");
        return 1;
    }
    ppmVal = fgetc(read);

    if (ppmVal != '3' && ppmVal != '6')
    {
        fprintf(stderr, "Error: Incorrect ppm file number\n");
        return 1;
    }
    tempMagicNumber = ppmVal;
    inputImage.magicNumber = tempMagicNumber;

    while(ppmVal != '\n')
    {
        ppmVal = fgetc(read);
    }
    checkwh = fscanf(read, "%d %d",&tempWidth, &tempHeight);
    if (checkwh < 2)
    {
        fprintf(stderr, "Error: Incorrect file width and height formating\n");
        return 1;
    }
    if (tempWidth < 0)
    {
        fprintf(stderr, "Error: Incorrect file width size, must be greater then Zero\n");
    }
    if (tempHeight < 0)
    {
        fprintf(stderr, "Error: Incorrect file height size, must be greater then Zero\n");
    }
    inputImage.width = tempWidth;
    inputImage.heigth = tempHeight;
    ppmVal = fgetc(read);
    while(ppmVal != '\n')
    {
        ppmVal = fgetc(read);
    }
    fscanf(read, "%d", &tempMaxColorValue);
    if (tempMaxColorValue < 1 || tempMaxColorValue > 255)
    {
        fprintf(stderr, "Error: Incorrect file color intensity, must be 1 to 255\n");
    }
    inputImage.maxColorInten = tempMaxColorValue;

    fclose(read);
    /*
     * to determine where to write the file too
     */
    if (ppmFormat == 3)
    {
        writeP3(inputFile, outputFile, inputImage, inFile, outFile);
    }
    if (ppmFormat == 6)
    {
        writeP6(inputFile, outputFile, inputImage, inFile, outFile);
    }
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
    FILE *inFile = fopen(argv[2], "rb");
    FILE *outFile = fopen(argv[3], "wb");

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
    // check to see if the input and out files are ppm files
    if(strstr(argv[2],".ppm") == NULL)
    {
        fprintf(stderr, "Error: Input file %s is not a .ppm file\n", inputFile);
        return 1;
    }
    if(strstr(argv[3],".ppm") == NULL)
    {
        fprintf(stderr, "Error: Output file %s is not a .ppm file\n", outputFile);
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
    readFile(ppmFormat,inputFile,outputFile, *inputImage,inFile,outFile);
    fclose(fileExist);
    return 0;
}
