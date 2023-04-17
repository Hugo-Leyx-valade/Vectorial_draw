#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "Circle.h"
#include "Square.h"
#include "Shapes.h"
#include "Rect.h"
#include "Forms.h"

int main() {
    Point* center = create_point(5,5);
    Circle* cercle = create_circle(center,15);
    display_circle(cercle);
    return 0;
}
