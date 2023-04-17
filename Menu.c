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

void choose_action() {
    char choice;
    printf("Your choice : ");
    scanf("%c", &choice);
}