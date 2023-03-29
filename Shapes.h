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


#define maxShapes 100
typedef struct {
    unsigned int id_shape;
    TypeForm type;
    void* realShape;
}SHAPE;

void createShape(SHAPE* shape,TypeForm type,void* realshape);
void displayShape(SHAPE* shape);
unsigned int getNewIdAnimal();
SHAPE* getAnimalById(SHAPE* shapes, unsigned int id);

#endif //VECTORIAL_DRAW_SHAPES_H
