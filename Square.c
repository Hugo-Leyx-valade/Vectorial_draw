//
// Created by hugol on 24/03/2023.
//

#include "Square.h"


Square *create_square(Point* top_left, int length){
    Square *square = (Square*) malloc(sizeof (Square*));
    square->top_left = top_left;
    square->length = length;
    return square;
}


void display_square(Square* square){
    printf("SQUARE : %d %d | length %d ",square->top_left->x1,square->top_left->y1,square->length);
}

void delete_square(Square** square){
    delete_point(&((*square)->top_left));
    free(*square);
    *square=NULL;
}
