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
#include "LLC_Shape.h"
#include "Menu.h"

int main() {
    LlcShape* ShapeList = NULL;
    start();
    char choice ;
    choice = choose_action();
    switch_case_action(choice,ShapeList);
    show_full_llc(ShapeList);
    return 0;
}
