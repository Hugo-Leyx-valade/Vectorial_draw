//
// Created by hugol on 24/03/2023.
//
#include <string.h>


#ifndef VECTORIAL_DRAW_FORMS_H
#define VECTORIAL_DRAW_FORMS_H

typedef enum {
    POINT, LINE, SQUARE, RECT, CIRCLE, POLYGON
} TypeForm;

TypeForm StringToTypeForm(char* form);
#endif //VECTORIAL_DRAW_FORMS_H
