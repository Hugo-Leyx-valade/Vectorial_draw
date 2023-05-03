//
// Created by hugol on 03/05/2023.
//

#include "Pixel.h"

Pixel *create_pixel(int px , int py){
    Pixel* pixel = (Pixel*) malloc(sizeof (Pixel));
    return pixel;
}

void delete_pixel(Pixel* pixel){
    free(pixel);
}

