#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "Point.h"
//#include "Line.h"
//#include "Polygon.h"
//#include "Circle.h"
//#include "Square.h"
#include "Shapes.h"
//#include "Rect.h"
//#include "Forms.h"
#include "LLCShape.h"

int main() {
    //Test Point's functions
    Point* testpoint = create_point(5,8);
    display_point(testpoint);
    delete_point(&testpoint);
    delete_point(testpoint);
    printf("\n\n\n");


    //Test Line's Functions
    Point* Linepoint1 = create_point(15,18);
    Point* Linepoint2 = create_point(13,110);
    Line* testline = create_line(Linepoint1,Linepoint2);
    display_line(testline);
    delete_line(&testline);
    display_line(testline);

    //Test




    Circle* circ = create_circle(point1,15);
    Rectangle* rect = create_rect(point1,10,10);
    CoordTab* coordinate= (CoordTab*) malloc(sizeof(CoordTab));
    coordinate->coords = (int*) malloc(sizeof(int)*4);
    coordinate->coords[0] = 5;
    coordinate->coords[1] = 6;
    coordinate->coords[2] = 8;
    coordinate->coords[3] = 2;
    coordinate->size = 4;

    Polygon* polygon= create_polygone(coordinate);
    display_polygon(polygon);
    delete_polygon(&polygon);
    display_polygon(polygon);



    return 0;
}
