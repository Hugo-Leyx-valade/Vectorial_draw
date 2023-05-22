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
void print_area(AREA* area){
    for(int i = 0 ; i<area->height ; i++){
        for(int j = 0 ; j<area->width ; j++){
            if(area->mat[i][j]==0){
                printf(". ");
            }else{
                printf("# ");
            }

        }
        printf("\n");
    }
}

void draw_area(AREA* area){
    Pixel** pixel_tab = NULL;
    int nb_pixels=0;
    LlcShape* tempLlc = area->shapes;
    for(int counter=0;counter<area->nb_shape;counter++){
        create_shape_to_pixel(tempLlc->value,&pixel_tab,&nb_pixels);
        tempLlc=tempLlc->next;
    }

    for(int pix=0;pix<nb_pixels;pix++){
        if(pixel_tab[pix]->py<area->width+1 && pixel_tab[pix]->px < area->height+1){
            area->mat[(pixel_tab[pix]->py)-1][(pixel_tab[pix]->px)-1] = TRUE;
        }

    }
}

void clear_area(AREA* area){
    for(int i = 0 ; i<area->height ; i++){
        for(int j = 0 ; j<area->width ; j++){
            area->mat[i][j] = FALSE;
        }
    }
}


void erase_area(AREA* area){
    LlcShape* templlc = area->shapes;
    for(int i = 1 ; i<area->nb_shape ; i++){
        deleteShapeFromLlc(area->shapes,templlc->value->id_shape);
        templlc=templlc->next;
    }
    area->nb_shape=0;
    area->shapes=NULL;
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
    area->nb_shape++;
}

void delete_shape_from_area(AREA* area, unsigned int id_shape){
    clear_area(area);
    deleteShapeFromLlc(&area->shapes,id_shape);
    area->nb_shape--;
}