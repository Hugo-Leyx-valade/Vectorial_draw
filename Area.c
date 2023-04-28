//
// Created by hugol on 28/04/2023.
//

#include "Area.h"

AREA* create_area(unsigned int width, unsigned int height){
    AREA* area = (AREA*) malloc(sizeof (AREA));
    area->height = height;
    area->width = width ;
    area->mat = (Bool**) malloc(area->height*sizeof(Bool*));
    for(int i = 0 ; i<area->height ; i++){
        area->mat[i] = (Bool*) malloc(width*sizeof (Bool));
    }
    area->shapes = (LlcShape*)malloc(sizeof (LlcShape));
    area->shapes = create_empty_llc();

}



void add_shape_to_area(AREA* area, Shape* shape);
void clear_area(AREA* area);
void erase_area(AREA* area);
void delete_area(AREA* area);
void draw_area(AREA* area);
void print_area(AREA* area);