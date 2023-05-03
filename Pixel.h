//
// Created by hugol on 03/05/2023.
//

#ifndef VECTORIAL_DRAW2_PIXEL_H
#define VECTORIAL_DRAW2_PIXEL_H
#include <stdio.h>
#include <stdlib.h>

typedef struct pixel {
    int px ;
    int py ;
} Pixel;

Pixel *create_pixel(int px , int py);
void delete_pixel(Pixel *pixel);



#endif //VECTORIAL_DRAW2_PIXEL_H
