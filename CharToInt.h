//
// Created by maloc on 22/04/2023.
//
#include "stringToArray.h"
#include "Bool.h"
#ifndef VECTORIAL_DRAW_CHARTOINT_H
#define VECTORIAL_DRAW_CHARTOINT_H

typedef struct CoordTab{
    int* coords;
    unsigned int size;
}CoordTab;

Bool isnumber(StringArray* stringArray);
CoordTab* StringArrayToCoordTab(StringArray* stringArray);








#endif //VECTORIAL_DRAW_CHARTOINT_H
