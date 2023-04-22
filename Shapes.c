//
// Created by hugol on 28/03/2023.
//

#include "Shapes.h"

unsigned int get_next_id() {
    static unsigned int id = 1;
    return id++;
}

Shape *create_empty_shape(TypeForm shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->realShape = NULL;
    shp->id_shape = get_next_id();
    shp->type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    shp->realShape = create_point(px, py);
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2) {
    Shape *shp = create_empty_shape(LINE);
    shp->realShape = create_line(create_point(px1, py1), create_point(px2, py2));
    return shp;
}

Shape *create_square_shape(int px, int py, int length) {
    Shape *shp = create_empty_shape(SQUARE);
    shp->realShape = create_square(create_point(px, py), length);
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height) {
    Shape *shp = create_empty_shape(RECT);
    shp->realShape = create_rect(create_point(px, py), width, height);
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius) {
    Shape *shp = create_empty_shape(CIRCLE);;
    shp->realShape = create_circle(create_point(px, py), radius);
    return shp;
}

Shape *create_polygon_shape(CoordTab* CoordinateArray) {
    Shape *shp = create_empty_shape(POLYGON);;
    shp->realShape = create_polygone(CoordinateArray);
    return shp;
}


void delete_shape(Shape *shape) {

    switch (shape->type) {
        case POINT:

            delete_point((Point**) &shape->realShape);
            break;
        case LINE:
            delete_line((Line**)&shape->realShape);
            break;
        case SQUARE:
            delete_square((Square**)&shape->realShape);
            break;
        case RECT:
            delete_rect((Rectangle**)&shape->realShape);
            break;
        case POLYGON:
            delete_polygon((Polygon**)&shape->realShape);
            break;
        case CIRCLE:
            delete_circle((Circle**)&shape->realShape);
            break;
        default:
            break;
    }
    free(shape);
}


void display_shape(Shape* shape) {
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


