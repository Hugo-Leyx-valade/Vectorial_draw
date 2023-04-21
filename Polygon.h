//
// Created by hugol on 24/03/2023.
//

#include "Point.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef VECTORIAL_DRAW_POLYGON_H
#define VECTORIAL_DRAW_POLYGON_H

typedef struct {
    Point *array_of_point;
} Polygon;

Polygon *create_polygone(int nbpoints);

void delete_polygon(Polygon *polygon);

void display_polygon(Polygon *polygon);


#endif //VECTORIAL_DRAW_POLYGON_H

