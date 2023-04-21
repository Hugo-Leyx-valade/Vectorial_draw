//
// Created by hugol on 17/04/2023.
//

#include "include.h"

void start() {
    printf("Please choose your action  :\n");
    printf("    A- Add a shape \n");
    printf("    B- Print shape's list \n");
    printf("    C- Delete a shape \n");
    printf("    D- Draw a shape \n");
    printf("    E- Help \n");
}

char* choose_action() {
    char choice;
    printf("Your choice : ");
    scanf("%c", &choice);
}

void switch_case_action(char *chara){
    TypeForm type_form;
    switch(*chara){
        case('A'):
            printf("Choose form between : POINT, LINE, SQUARE, RECT, CIRCLE, POLYGON .");
            scanf("%s",type_form);
            create_empty_shape(type_form);
            break;

        case('B'):

    }
}