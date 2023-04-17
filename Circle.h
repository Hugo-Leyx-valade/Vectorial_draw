//
// Created by hugol on 24/03/2023.
//
#include "Point.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef VECTORIAL_DRAW_CIRCLE_H
#define VECTORIAL_DRAW_CIRCLE_H

typedef struct {
    Point *center;
    int radius;
} Circle;

Circle *create_circle(Point *center, int radius);

void delete_circle(Circle *circle);

void display_circle(Circle *circle);


#endif //VECTORIAL_DRAW_CIRCLE_H
