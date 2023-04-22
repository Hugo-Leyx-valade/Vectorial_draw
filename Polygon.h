//
// Created by hugol on 24/03/2023.
//

#include "Point.h"
#include "stringToArray.h"
#include " CharToInt.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef VECTORIAL_DRAW_POLYGON_H
#define VECTORIAL_DRAW_POLYGON_H

typedef struct{
    Point** array_of_point;
    unsigned int size;
}Polygon;

Polygon* create_polygone(CoordTab* coord_tab);
void delete_polygon(Polygon** polygon);
void display_polygon(Polygon* polygon);


#endif //VECTORIAL_DRAW_POLYGON_H

