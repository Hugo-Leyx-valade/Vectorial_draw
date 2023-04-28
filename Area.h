//
// Created by hugol on 28/04/2023.
//
#include "Shapes.h"
#include "LLCShape.h"
#define SHAPE_MAX 100 // Nombre maximum de formes
#define BOOL int


typedef struct area {
    unsigned int width; // Nombre de pixels en largeur ou nombre de colonnes (axe y)
    unsigned int height; // Nombre de pixels en hauteur ou nombre de lignes (axe x)
    BOOL** mat; // Matrice des pixels de taille (width * height)
    LlcShape* shapes; // Tableau des formes;
    int nb_shape; // Nombre de formes dans le tableau shapes (taille logique)
}AREA;

AREA* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(AREA* area, Shape* shape);
void clear_area(AREA* area);
void erase_area(AREA* area);
void delete_area(AREA* area);
void draw_area(AREA* area);
void print_area(AREA* area);