#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Shapes.h"
#include "LLCShape.h"
#include "time.h"
int main() {
    printf("create a point with 5 | 10 coordinates\n");
    Shape* point = create_point_shape(5,10);
    printf("test display function\n");
    display_shape(point);
    printf("\n");
    printf("test delete function and try to display point after\n");
    delete_shape(point);
    display_shape(point);
    printf("\n\n");
    printf("create empty list\n");
    LlcShape* List = create_empty_llc();
    printf("create rectangle with 7 | 6 top left coordinates , 3 width and 4 height\n");
    Shape* rectangle = create_rectangle_shape(7,6,3,4);
    printf("add rectangle to list and display list\n");
    List = add_to_llc(List,rectangle);
    display_llc(List);
    printf("\n");
    printf("create circle with 9 | 3 center coordinates and 4 radius\n");
    Shape* Circle = create_circle_shape(9,3,4);
    printf("add circle to list and display list\n");
    List= add_to_llc(List,Circle);
    display_llc(List);
    printf("\n");
    printf("show shape with id 2\n");
    display_shape(getShapeById(List,2));
    printf("\n");
    printf("\n");
    printf("delete shape with id 3 and show list\n");
    deleteShapeFromLlc(List,3);
    display_llc(List);
    while(TRUE);






    return 0;
}
