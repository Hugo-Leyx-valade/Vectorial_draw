//
// Created by maloc on 22/04/2023.
//
#include "Shapes.h"
#include "Bool.h"
#include <stdio.h>
#ifndef _LLCSHAPE_H
#define _LLCSHAPE_H


typedef struct LlcShape {
    Shape* value;
    struct LlcShape* next;
}LlcShape;


LlcShape* create_first_cell(Shape* value);
Bool llc_empty(LlcShape* cell);
LlcShape* add_to_first(LlcShape* cell, Shape* value);
LlcShape* add_to_last(LlcShape* cell, Shape* value) ;
int taille_liste(LlcShape* liste);
void afficher_liste(LlcShape* liste);
Shape* getShapeById(LlcShape* cell ,unsigned int id);

#endif //_LLCSHAPE_H
