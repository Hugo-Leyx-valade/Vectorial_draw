//
// Created by hugol on 24/03/2023.
//

#include "Polygon.h"

Polygon* create_polygone(CoordTab* coord_tab){
    int cpt=0;
    int j=0;
    Polygon* polygon = (Polygon*) malloc(sizeof(Polygon));

    Point** tab_points = (Point**) malloc(sizeof(Point*)*coord_tab->size);
    for(int i=0;i<coord_tab->size;i=i+2){
        cpt++;
        int x,y;
        x = coord_tab->coords[i];
        y = coord_tab->coords[i+1];
        Point* point=create_point(x,y);
        *(tab_points+j)=point;
        j++;
    }
    polygon->array_of_point=tab_points;
    polygon->size=cpt;
    return polygon;
}

void display_polygon(Polygon* polygon){
    if(polygon != NULL){
        printf("polygon :" );
        for(int i=0;i<polygon->size;i++){
            printf("point %d : x=%d y=%d    ",i+1,polygon->array_of_point[i]->x1,polygon->array_of_point[i]->y1);
        }
    }
}

void delete_polygon(Polygon** polygon){
    for(int i=0; i<(*polygon)->size;i++){
        delete_point(&(*polygon)->array_of_point[i]);
    }
    *polygon=NULL;
}