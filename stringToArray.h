//
// Created by hugol on 28/03/2023.
//
#include <string.h>
#include <stdlib.h>
#ifndef VECTORIAL_DRAW_STRINGTOARRAY_H
#define VECTORIAL_DRAW_STRINGTOARRAY_H

typedef struct {
    char **array;
    unsigned int size;
} StringArray;

StringArray splitStringToArray(const char *stringToSplit, const char *delimiter);


#endif //VECTORIAL_DRAW_STRINGTOARRAY_H
