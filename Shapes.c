//
// Created by hugol on 28/03/2023.
//

#include "Shapes.h"

void createShape(SHAPE* shape,TypeForm type,void* realshape){
    shape->id_shape = getNewIdAnimal();
    shape->type = type;
    shape->realShape = realshape;
}


void displayShape(SHAPE* shape) {
    switch (shape->type) {
        case POINT:
            display_point((Point*) shape->realShape);
            break;
        case LINE:
            display_line((Line*)shape->realShape);
            break;
        case SQUARE:
            display_square((Square*)shape->realShape);
            break;
        case RECT:
            display_rect((Rectangle*)shape->realShape);
            break;
        case POLYGON:
            display_polygon((Polygon*)shape->realShape);
            break;
        case CIRCLE:
            display_circle((Circle*)shape->realShape);
            break;
        default:
            break;
    }
}


unsigned int getNewIdAnimal(){
    static unsigned int id = 0;
    return ++id;
}

SHAPE* getAnimalById(SHAPE* shapes, unsigned int id){
    for (int i = 0; i < maxShapes; i++) {
        if (shapes[i].id_shape == id) {
            return &shapes[i];
        }
    }
    return NULL;
}
