//
// Created by hugol on 24/03/2023.
//

#include "include.h"


Line *create_line(Point *point_1, Point *point_2) {
    Line *createdLine = (Line *) malloc(sizeof(Line));
    createdLine->point_1 = point_1;
    createdLine->point_2 = point_2;
    return createdLine;
}


void display_line(Line* line){
    if(line != NULL){
        printf("LINE : POINT1: %d %d | POINT2: %d %d",line->point_1->x1,line->point_1->y1,line->point_2->x1,line->point_2->y1);
    }
}


void delete_line(Line** line){
    delete_point(&((*line)->point_1));
    delete_point(&((*line)->point_2));
    free(*line);
    *line = NULL;
}