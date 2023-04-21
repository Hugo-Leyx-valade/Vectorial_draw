//
// Created by maloc on 21/04/2023.
//

#include "Shapes.h"
#include "Bool.h"
#include <stdio.h>

#ifndef VECTORIAL_DRAW1_LLC_SHAPE_H
#define VECTORIAL_DRAW1_LLC_SHAPE_H


typedef struct LlcShape {
    Shape* value;
    struct LlcShape* next;
}LlcShape;


LlcShape* create_cell(Shape* value);
Bool llc_empty(LlcShape* cell);
LlcShape* add_to_first(LlcShape* cell, Shape* value);
LlcShape* add_to_last(LlcShape* cell, Shape* value) ;
int length_llc(LlcShape* cell);
void show_full_llc(LlcShape* cell);



#endif //VECTORIAL_DRAW1_LLC_SHAPE_H
