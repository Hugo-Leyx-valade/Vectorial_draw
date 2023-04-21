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
    char* char_type_form;
    TypeForm type_form;
    switch(chara){
        case('A'):
            printf("Choose form between : POINT, LINE, SQUARE, RECT, CIRCLE, POLYGON :");
            scanf("%s",char_type_form);
            type_form = StringToTypeForm(char_type_form);
            switch()
            break;

        case('B'):

    }
}