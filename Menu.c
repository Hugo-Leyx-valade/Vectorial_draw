//
// Created by hugol on 17/04/2023.
//

#include "include.h"

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

void switch_case_action(char chara){
    char* type_form;
    switch(chara){
        case('A'):
            printf("Choose form between : POINT, LINE, SQUARE, RECT, CIRCLE, POLYGON :");
            scanf("%s",type_form);
            create_empty_shape(type_form);
            break;

        case('B'):

    }
}