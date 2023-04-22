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
    // Creates a point then delete it
    Shape* PointShape = create_point_shape(5,10);
    display_shape(PointShape);
    delete_shape(PointShape);
    display_shape(PointShape);
    printf("\n\n\n");


    // Creates a line then delete it
    Shape* LineShape = create_line_shape(5,6,12,13);
    display_shape(LineShape);
    delete_shape(LineShape);
    display_shape(LineShape);


    return 0;
}
