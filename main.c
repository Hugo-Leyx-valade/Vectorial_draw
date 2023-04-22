#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Shapes.h"
#include "LLCShape.h"

int main() {
    // Creates a point then delete it
    Shape* PointShape = create_point_shape(5,10);
    /*display_shape(PointShape);
    delete_shape(PointShape);
    display_shape(PointShape);
    printf("\n\n\n");*/


    // Creates a line then delete it
    Shape* LineShape = create_line_shape(5,6,12,13);
    /*display_shape(LineShape);
    delete_shape(LineShape);
    display_shape(LineShape);*/

    LlcShape* test = create_empty_llc();
    test=add_to_llc(test,PointShape);
    test=add_to_llc(test,LineShape);
    printf("%d",length_llc(test));
    printf("\n");
    display_llc(test);
    printf("\n\n\n");
    display_shape(getShapeById(test,1));

    return 0;
}
