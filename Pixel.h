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
#include "Rect.h"

typedef struct pixel {
    int px ;
    int py ;
} Pixel;

Pixel *create_pixel(int px , int py); /* fait */
void delete_pixel(Pixel *pixel); /* fait */
void pixel_point(Point * shape, Pixel** pixel, int* nb_pixels); /* fait */
void pixel_line(Line* shape, Pixel** pixel, int* nb_pixels);  /* fait */
void pixel_square(Square * shape, Pixel** pixel, int* nb_pixels);  /* fait */
void pixel_rect(Rectangle* shape, Pixel** pixel, int* nb_pixels);  /* fait */
void pixel_circle(Circle * shape, Pixel** pixel, int* nb_pixels); /* fait */
void pixel_polygon(Polygon * shape, Pixel** pixel, int* nb_pixels); /* fait */


#endif //VECTORIAL_DRAW1_PIXEL_H
