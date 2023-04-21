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



Shape *create_point_shape(int* coord) {
    Shape *shp = create_empty_shape(POINT);
    shp->realShape = create_point(coord[0], coord[1]);
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
    shp->realShape = create_rectangle(create_point(px, py), width, height);
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius) {
    Shape *shp = create_empty_shape(CIRCLE);;
    shp->realShape = create_circle(create_point(px, py), radius);
    return shp;
}

Shape *create_polygon_shape(int lst[], int n) {
    Shape *shp = create_empty_shape(POLYGON);;
    shp->realShape = create_polygone(n);
    return shp;
}


void delete_shape(Shape *shape) {
    free(shape->realShape);
    free(shape);
}


void print_shape(unsigned int id_shape) {

}

