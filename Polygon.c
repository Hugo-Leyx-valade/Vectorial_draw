//
// Created by hugol on 24/03/2023.
//

#include "Polygon.h"

Polygon* create_polygone(int nbpoints){
    Polygon* polygon = (Polygon*) malloc(sizeof(Polygon));
    Point* tabpoints = (Point*) malloc(nbpoints*(sizeof(polygon)));
    for(int i=0;i<nbpoints;i++){
        int x,y;
        printf("point %d\n",i+1);
        scanf("%d %d",&x,&y);
        tabpoints[i]=*(create_point(x,y));
        fflush(stdin);
    }
    polygon->array_of_point=tabpoints;
    return polygon;
}

void display_polygon(Polygon* polygon){
    printf("polygon :" );
    for(int i=0;i<3;i++){
        printf("point %d : x=%d y=%d",i,polygon->array_of_point[i].x1,polygon->array_of_point[i].y1);
    }
}