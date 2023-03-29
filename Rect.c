//
// Created by hugol on 24/03/2023.
//

#include "Rect.h"

Rectangle *create_rectangle(Point* top_left, int width, int height){
    Rectangle *createdRect= (Rectangle*) malloc(sizeof(Rectangle));
    createdRect->top_left=top_left;
    createdRect->width=width;
    createdRect->height=height;
    return createdRect;
}
void display_rect(Rectangle* rectangle){
    printf("SQUARE : %d %d : width %d : heigth ",rectangle->top_left->x1,rectangle->top_left->y1);
}

void delete_rect(Rectangle * rectangle){
    delete_point(rectangle->top_left);
    free(rectangle);
}
