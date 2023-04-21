//
// Created by hugol on 24/03/2023.
//
#include "Point.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef VECTORIAL_DRAW_RECT_H
#define VECTORIAL_DRAW_RECT_H
typedef struct {
    Point *top_left;
    int width;
    int height;
} Rectangle;

Rectangle *create_rectangle(Point *top_left, int width, int height);

void delete_rect(Rectangle *rectangle);

void display_rect(Rectangle *rectangle);

#endif //VECTORIAL_DRAW_RECT_H
