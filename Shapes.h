//
// Created by hugol on 28/03/2023.
//

#ifndef VECTORIAL_DRAW_SHAPES_H
#define VECTORIAL_DRAW_SHAPES_H

#include "Forms.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Point.h"
#include "Line.h"
#include "Rect.h"
#include "Square.h"
#include "Circle.h"
#include "Polygon.h"
#include "include.h"


#define maxShapes 100
typedef struct {
    unsigned int id_shape;
    TypeForm type;
    void *realShape;
} Shape;


Shape *create_empty_shape(TypeForm shape_type);

Shape *create_point_shape(int px, int py);

Shape *create_line_shape(int px1, int py1, int px2, int py2);

Shape *create_square_shape(int px, int py, int length);

Shape *create_rectangle_shape(int px, int py, int width, int height);

Shape *create_circle_shape(int px, int py, int radius);

Shape *create_polygon_shape(int lst[], int n);

void delete_shape(Shape *shape);

void print_shape(Shape *shape);

unsigned int get_next_id();

#endif //VECTORIAL_DRAW_SHAPES_H
