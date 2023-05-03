//
// Created by hugol on 17/04/2023.
//

#include "Menu.h"

void start() {
    printf("Please choose your action  :\n");
    printf("    A- Add a shape \n");
    printf("    B- Print shape's list \n");
    printf("    C- Delete a shape (Coming soon) \n");
    printf("    D- Draw a shape (Coming soon)\n");
    printf("    E- Help (Coming soon) \n");
}

char choose_action() {
    char choice;
    printf("Your choice :");
    scanf("%c", &choice);
    return choice;
}


void switch_case_action(char chara, LlcShape* ShapeList){
    char char_type_form[100];
    char coordform[100];
    int* coordstab;
    StringArray *TAB;
    TypeForm type_form;
    switch(chara){
        case('A'):
            printf("Choose form between : POINT, LINE, SQUARE, RECT, CIRCLE, POLYGON :");
            scanf("%s",char_type_form);
            type_form = StringToTypeForm(char_type_form);
            switch (type_form) {
                case POINT:
                    printf("Enter coords of point:");
                    scanf("%s",coordform);
                    coordstab = splitStringToArray(coordform," ").array;
                    add_to_last(ShapeList,create_point_shape(coordstab));
                    break;
                    /*case LINE:
                        display_line((Line *) shape->realShape);
                        break;
                    case SQUARE:
                        display_square((Square *) shape->realShape);
                        break;
                    case RECT:
                        display_rect((Rectangle *) shape->realShape);
                        break;
                    case POLYGON:
                        display_polygon((Polygon *) shape->realShape);
                        break;
                    case CIRCLE:
                        display_circle((Circle *) shape->realShape);
                        break;*/
                default:
                    break;
            }
        default:
            break;
        case('B'):
    }
}
