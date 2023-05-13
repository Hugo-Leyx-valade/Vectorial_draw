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
        area->mat[i] = (Bool*) calloc(width,sizeof (Bool));
    }
    area->shapes = (LlcShape*)malloc(sizeof (LlcShape));
    area->shapes = create_empty_llc();
    area->nb_shape = 0;
    return area;
}
void draw_area(AREA* area){
    for(int i = 0 ; i<area->height ; i++){
        for(int j = 0 ; j<area->width ; j++){
            printf("%d   ", area->mat[i][j]);
        }
        printf("\n");
    }
}


void clear_area(AREA* area){
    for(int i = 0 ; i<area->height ; i++){
        for(int j = 0 ; j<area->width ; j++){
            area->mat[i][j] = 0;
        }
    }
}


void erase_area(AREA* area){
    for(int i = 0 ; i<area->nb_shape ; i++){
        deleteShapeFromLlc(area->shapes,i);
    }
}


void delete_area(AREA* area){
    erase_area(area);
    for(int i = 0 ; i<area->height ; i++){
            free(area+i);
    }
    free(area);
}

void add_shape_to_area(AREA* area, Shape* shape){
    area->shapes  = add_to_llc(area->shapes,shape);
    Pixel** pixel_tab= create_shape_to_pixel(shape,nb_pixel);

}

