//
// Created by hugol on 24/03/2023.
//
#include "Point.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef VECTORIAL_DRAW_SQUARE_H
#define VECTORIAL_DRAW_SQUARE_H
typedef struct {
    Point *top_left;
    int length;
} Square;

Square *create_square(Point* top_left, int length);
void delete_square(Square** square);
void display_square(Square* square);

#endif //VECTORIAL_DRAW_SQUARE_H
