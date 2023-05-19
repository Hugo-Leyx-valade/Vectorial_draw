//
// Created by hugol on 24/03/2023.
//

#include "Circle.h"


Circle* create_circle(Point* center, int radius){
    Circle *circle = (Circle *) malloc(sizeof (Circle*));
    circle -> center = center;
    circle -> radius = radius;
    return circle;
}

void display_circle(Circle *circle) {
    if (circle != NULL) {
        printf("Circle : Center : %d %d |  Radius : %d", circle->center->x1, circle->center->y1, circle->radius);
    }
}


void delete_circle(Circle** circle){
    delete_point(&((*circle)->center));
    free(*circle);
    *circle=NULL;
}

