//
// Created by hugol on 09/05/2023.
//

#ifndef VECTORIAL_DRAW1_PIXEL_H
#define VECTORIAL_DRAW1_PIXEL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.h"
#include "Shapes.h"
#include "Square.h"
#include "Polygon.h"

typedef struct pixel {
    int px ;
    int py ;
} Pixel;

Pixel *create_pixel(int px , int py);
void delete_pixel(Pixel *pixel);
void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_line(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_square(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_rect(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_polygon(Shape* shape, Pixel** pixel, int* nb_pixels);


#endif //VECTORIAL_DRAW1_PIXEL_H
