#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "Commands.h"

int main() {
    int exit_status=0;
    AREA* area = create_area(20,20);
    while(exit_status==0){
        printf("Choisissez une action:\n");
        printf("    A : Ajouter une forme\n");
        printf("    B : Supprimer une forme\n");
        printf("    C : Afficher la lise des formes\n");
        printf("    D : Ajoute les formes sur l'ecran\n");
        printf("    E : Affiche l'ecran\n");
        printf("    F : Effacer l'ecran\n");
        printf("    G : Effacer toute les formes\n");
        printf("    H : Afficher l'aide\n");
        printf("    I : Arreter le programe\n\n");
        printf("    >>");
        action(&exit_status,area);
    }







    return 0;
}
