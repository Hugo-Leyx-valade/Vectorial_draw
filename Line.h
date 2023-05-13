//
// Created by hugol on 24/03/2023.
//

#ifndef VECTORIAL_DRAW_LINE_H
#define VECTORIAL_DRAW_LINE_H

#include "Point.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    Point *point_1;
    Point *point_2;
} Line;

Line *create_line(Point *point_1, Point *point);

void display_line(Line *line);

void delete_line(Line **line);


#endif //VECTORIAL_DRAW_LINE_H
