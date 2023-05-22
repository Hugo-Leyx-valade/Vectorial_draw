//
// Created by maloc on 18/05/2023.
//

#include "Commands.h"

void action(int* exit_status,AREA* area) {
    char input;
    int nb;
    scanf("%c",&input);
    fflush(stdin);
    switch (input) {
        case 'A':
            printf("        1 : Point\n");
            printf("        2 : Ligne\n");
            printf("        3 : Carre\n");
            printf("        4 : Rectangle\n");
            printf("        5 : Cercle\n");
            printf("        6 : Polygone\n");
            printf("        7 : Retour\n\n");
            printf("        >>");
            action_add_form(area);
            break;
        case 'B':
            printf("Saisir l'id de la forme: ");
            scanf("%d",&nb);
            fflush(stdin);
            delete_shape_from_area(area,nb);
            break;
        case 'C':
            display_llc(area->shapes);
            break;
        case 'D':
            draw_area(area);
            break;
        case 'E':
            print_area(area);
            break;
        case 'F':
            clear_area(area);
            break;
        case 'G':
            erase_area(area);
            break;
        case 'H':
            print_help();
            break;
        case 'I':
            *exit_status=1;
            printf("A bientot !");
            break;
        default:
            printf("commande non reconnu\n");
            break;

    }
}

void action_add_form(AREA* area ) {
    char input;
    scanf("%c", &input);
    fflush(stdin);
    switch (input) {
        case '1':
            printf("Saisir: x y: ");
            char coords_point[3];
            StringArray reelcoords_point;
            gets(coords_point);
            reelcoords_point = splitStringToArray(coords_point," ");
            Shape* point = create_point_shape(atoi(reelcoords_point.array[0]),atoi(reelcoords_point.array[1]));
            add_shape_to_area(area,point);
            break;
        case '2':
            printf("Saisir: x1 y1 x2 y2: ");
            char coords_line[7];
            StringArray reelcoords_line;
            gets(coords_line);
            reelcoords_line = splitStringToArray(coords_line," ");
            Shape* line = create_line_shape(atoi(reelcoords_line.array[0]),atoi(reelcoords_line.array[1]),atoi(reelcoords_line.array[2]),atoi(reelcoords_line.array[3]));
            add_shape_to_area(area,line);
            break;
        case '3':
            printf("Saisir: x x coté: ");
            char coords_square[5];
            StringArray reelcoords_square;
            gets(coords_square);
            reelcoords_square = splitStringToArray(coords_square," ");
            Shape* square = create_square_shape(atoi(reelcoords_square.array[0]),atoi(reelcoords_square.array[1]),atoi(reelcoords_square.array[2]));
            add_shape_to_area(area,square);
            break;
        case '4':
            printf("Saisir: x x largeur longueur: ");
            char coords_rect[7];
            StringArray reelcoords_rect;
            gets(coords_rect);
            reelcoords_rect = splitStringToArray(coords_rect," ");
            Shape* rectangle = create_rectangle_shape(atoi(reelcoords_rect.array[0]),atoi(reelcoords_rect.array[1]),atoi(reelcoords_rect.array[2]),atoi(reelcoords_rect.array[3]));
            add_shape_to_area(area,rectangle);
            break;
        case '5':
            printf("Saisir: x y rayon: ");
            char coords_circle[5];
            StringArray reelcoords_circle;
            gets(coords_circle);
            reelcoords_circle = splitStringToArray(coords_circle," ");
            Shape* circle = create_circle_shape(atoi(reelcoords_circle.array[0]),atoi(reelcoords_circle.array[1]),atoi(reelcoords_circle.array[2]));
            add_shape_to_area(area,circle);
            break;
        case '6':
            printf("Saisir le nombre de points: ");
            int nb_points;
            scanf("%d",&nb_points);
            fflush(stdin);
            char* coords_polygon = (char*) malloc(((nb_points*2)-1)*sizeof(char));
            StringArray reelcoords_polygon;
            printf("Saisir les points: x1 y1 x2 y1...: ");
            gets(coords_polygon);
            reelcoords_polygon = splitStringToArray(coords_polygon," ");
            CoordTab* coords = StringArrayToCoordTab(&reelcoords_polygon);
            Shape* polygon = create_polygon_shape(coords);
            add_shape_to_area(area,polygon);
            break;
        case '7':
            break;
        default:
            printf("commande non reconnu\n");
            break;

    }
}

void print_help(){
    printf("A - Ajouter forme :"
           "\tPoint x y , : permet de creer une point de coordonnees (x,y) ou x et y sont des entier compris dans la taille de la zone de dessin. \n"
           "\n"
           "\tLigne x1 y1 x2 y2 : creer une ligne entre les deux points renseigner par l'utilisateur. \n"
           "\n"
           "\tCarre x y length : creer un carre partant du point en haut a gauche de coordonnees (x,y) \n\tet dont la taille de chaque cote est length, tous les parametre doivent etre des entier compris dans la taille de la zone de dessin. \n"
           "\n"
           "\tRectangle x y width heigth : creer un rectangle partant du point en haut a gauche de coordonnees (x,y) \n\tet dont la longueur est de width et la hauteur de heigth, tous les parametre doivent etre des entier compris dans la taille de la zone de dessin. \n"
           "\n"
           "\tCercle x y radius : creer un cercle de centre (x,y) et de rayon radius tous les parametre doivent etre des entier compris dans la taille de la zone de dessin. \n"
           "\n"
           "\tPolygon x1 y1 x2 y2 x3 y3. . .xn yn : creer un polygone de n points de coordonnees (xi,yi ; avec 0<i<=n).  \n\tIci il faut simplement renseigner les coordonnees des points car  le polygone est un ensembles de Line entre deux points.   \n"
           "\n"
           "B - Supprimer une forme : permet de supprimer une forme grace a sont id. Chaque forme a un id qui lui est propre comme la « key » en SQL. \nCet id permet de retrouver la forme que l utilisateur veut supprimer et ainsi elle ne s affichera plus ni lors du Liste ni lors du Plot . \n"
           "\n"
           "C - Afficher la liste des formes : permet de lister toutes les formes que l'utilisateur a cree et qui n on pas ete supprimer, \nc'est-a-dire l'ensembles des formes qui se dessinerons au prochain Plot.\n"
           "\n"
           "D - Ajoute les formes sur l'ecran : permet d'ajouter les formes non ajouter au tableau."
           "\n"
           "E - Affiche l'ecran : affiche la grille de dessin ainsi que les formes renseigner par l'utilisateur, \nc est a partir de maintenant que l'utilisateur a un retour visuel de ce qu il a cree.\n"
           "\n"
           "F - Effacer l'ecran : permet d'enlever les formes du tableau sans les supprimer." "\n"
           "G - Effacer toute les formes : bien plus radical que Delete id cette commande permet d'effacer toutes les formes et de tout recommencer à zero."
           "\n"
           "I - Arreter le programme : cette commande permet simplement à l'utilisateur de quitter l'executable en cours.\n"
           "\n");
}