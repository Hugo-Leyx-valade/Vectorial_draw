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



    Polygon* hugo = NULL;
    hugo = create_polygone(3);
    display_polygon(hugo);

    start();
    char choice ;
    choice = choose_action();
    switch_case_action(choice);
    return 0;
}
