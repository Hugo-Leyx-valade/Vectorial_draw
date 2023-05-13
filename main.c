#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Shapes.h"
#include "LLCShape.h"
#include "time.h"
//#include "Area.h"
#include "Pixel.h"
int main() {

//    printf("create a point with 5 | 10 coordinates\n");
//    Shape* point = create_point_shape(5,10);
//    printf("test display function\n");
//    display_shape(point);
//    printf("\n");
//    printf("test delete function and try to display point after\n");
//    delete_shape(point);
//    display_shape(point);
//    printf("\n\n");
//    printf("create empty list\n");
//    LlcShape* List = create_empty_llc();
//    printf("create rectangle with 7 | 6 top left coordinates , 3 width and 4 height\n");
//    Shape* rectangle = create_rectangle_shape(7,6,3,4);
//    printf("add rectangle to list and display list\n");
//    List = add_to_llc(List,rectangle);
//    display_llc(List);
//    printf("\n");
//    printf("create circle with 9 | 3 center coordinates and 4 radius\n");
//    Shape* Circle = create_circle_shape(9,3,4);
//    printf("add circle to list and display list\n");
//    List= add_to_llc(List,Circle);
//    display_llc(List);
//    printf("\n");
//    printf("show shape with id 2\n");
//    display_shape(getShapeById(List,2));
//    printf("\n");
//    printf("\n");
//    printf("delete shape with id 3 and show list\n");
//    deleteShapeFromLlc(List,3);
//    display_llc(List);

    AREA* area = create_area(10,10);

    Pixel** pixel_tab = (Pixel**) malloc(5*sizeof (Pixel*));
    Shape* point = create_point_shape(5,6);
    Shape* point2 = create_point_shape(7,6);
    int nb = 0 ;
    pixel_point(point->realShape,pixel_tab,&nb);
    pixel_point(point2->realShape,pixel_tab,&nb);
    afficher_form_test(area,pixel_tab,&nb);
    draw_area(area);








    return 0;
}
