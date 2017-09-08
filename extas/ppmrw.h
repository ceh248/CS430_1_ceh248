#ifdef PPMRW_H
#define PPMRW_H

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

#endif
