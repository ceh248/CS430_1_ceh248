#ifndef READFILE_C
#define READFILE_C

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
ppmImage readFile(int ppmFormat, char *inputFile,char *output)
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
        writerP3();
    }
    exit(0);
}
#endif
