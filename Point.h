//
// Created by hugol on 24/03/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef VECTORIAL_DRAW_POINT_H
#define VECTORIAL_DRAW_POINT_H

typedef struct{
    int x1;
    int y1;
}Point;

Point* create_point(int x1, int y1);
void display_point(Point* point);
void delete_point(Point* point);


#endif //VECTORIAL_DRAW_POINT_H
