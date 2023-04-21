//
// Created by hugol on 24/03/2023.
//

#include "Point.h"

Point *create_point(int x1, int y1) {
    Point *createdPoint = (Point *) malloc(sizeof(Point));
    createdPoint->x1 = x1;
    createdPoint->y1 = y1;
    return createdPoint;
}

void display_point(Point *point) {
    printf("POINT : %d %d", point->x1, point->y1);
}

void delete_point(Point *point) {
    free(point);
    point = NULL;
}