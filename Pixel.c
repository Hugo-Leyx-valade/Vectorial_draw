//
// Created by maloc on 13/05/2023.
//

#include "Pixel.h"
Pixel *create_pixel(int px , int py){
    Pixel* pixel = (Pixel*) malloc(sizeof (Pixel));
    pixel->px = px ;
    pixel->py = py ;
    return pixel;
}

void delete_pixel(Pixel* pixel){
    free(pixel);
}

void pixel_point(Point* shape, Pixel*** pixel, int* nb_pixels){
    *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
    *pixel[(*nb_pixels)++] = create_pixel(shape->x1 , shape->y1);
}

void pixel_line(Line* shape, Pixel*** pixel, int* nb_pixels){
    int longx=0;
    int longy=0;
    if(shape->point_1->x1 < shape->point_2->x1){
        longx = shape->point_2->x1 - shape->point_1->x1;
        longy = shape->point_2->y1 - shape->point_1->y1;
    }else{
        longx = shape->point_1->x1 - shape->point_2->x1;
        longy = shape->point_1->y1 - shape->point_2->y1;
    }

    int longmin=0;
    int longmax=0;
    if(longx<(sqrt(longy*longy))){
        longmin=longx;
        longmax=(sqrt(longy*longy));
    }else{
        longmin=(sqrt(longy*longy));
        longmax=longx;
    }
    int nbseg = longmin+1;
    int tabsegs[nbseg];
    int longini = (longmax+1)/(longmin+1);
    for(int i=0;i<nbseg;i++){
        tabsegs[i]=longini;
    }
    int rest = (longmax+1)%(longmin+1);
    int cumuls[nbseg];
    cumuls[0]=0;
    for(int i=0;i<nbseg;i++){
        cumuls[i]=((i+1)*rest)%(longmin+1) < ((i*rest)%(longmin+1));
        tabsegs[i]=tabsegs[i]+cumuls[i];
    }
    int x;
    int y;
    if(shape->point_1->x1 < shape->point_2->x1){
        x = shape->point_1->x1;
        y = shape->point_1->y1;
    }else{
        x = shape->point_2->x1;
        y = shape->point_2->y1;
    }
    if(longy<0){
        if(longx>(sqrt(longy*longy))) {
            for (int i = 0; i < nbseg; i++) {
                for (int j = 0; j < tabsegs[i]; j++) {
                    *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
                    *pixel[(*nb_pixels)++] = create_pixel(x, y);
                    x++;
                }
                y--;
            }
        }else{
            for (int i = 0; i < nbseg; i++) {
                for (int j = 0; j < tabsegs[i]; j++) {
                    *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
                    *pixel[(*nb_pixels)++] = create_pixel(x, y);
                    y--;
                }
                x++;
            }
        }
    }else{
        if(longx>(sqrt(longy*longy))){
            for(int i=0;i<nbseg;i++){
                for(int j=0;j<tabsegs[i];j++){
                    *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
                    *pixel[(*nb_pixels)++] = create_pixel(x , y);
                    x++;
                }
                y++;
            }
        }else{
            for(int i=0;i<nbseg;i++){
                for(int j=0;j<tabsegs[i];j++){
                    *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
                    *pixel[(*nb_pixels)++] = create_pixel(x , y);
                    y++;
                }
                x++;
            }
        }
    }
}


void pixel_circle(Circle* shape, Pixel*** pixel, int* nb_pixels){
    int x = 0;
//    Circle *circle = (Circle*) shape->realShape;
    int y = shape->radius;
    int d = shape->radius - 1 ;
//    nb_pixels = 0;
    while (y>=x){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+8)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel((shape->center->x1)+x , (shape->center->y1)+y);
        *pixel[(*nb_pixels)++] = create_pixel((shape->center->x1)+y , (shape->center->y1)+x);
        *pixel[(*nb_pixels)++] = create_pixel((shape->center->x1)-x , (shape->center->y1)+y);
        *pixel[(*nb_pixels)++] = create_pixel((shape->center->x1)-y , (shape->center->y1)+x);
        *pixel[(*nb_pixels)++] = create_pixel((shape->center->x1)+x , (shape->center->y1)-y);
        *pixel[(*nb_pixels)++] = create_pixel((shape->center->x1)+y , (shape->center->y1)-x);
        *pixel[(*nb_pixels)++] = create_pixel((shape->center->x1)-x , (shape->center->y1)-y);
        *pixel[(*nb_pixels)++] = create_pixel((shape->center->x1)-y , (shape->center->y1)-x);
        if(d>=2*x){
            d -= 2*x+1;
            x++;
        } else if(d < 2*(shape->radius-y)){
            d += 2*y-1;
            y-- ;
        }else{
            d+= 2*(y-x-1);
            y--;
            x++;
        }
    }
}

void pixel_square(Square * shape, Pixel*** pixel, int* nb_pixels){
    Point *point_1 =shape->top_left;
    Point *point_2 = create_point(point_1->x1+shape->length,point_1->y1);
    Point *point_3 = create_point(point_2->x1 , point_2->y1+shape->length);
    Point *point_4 = create_point(point_3->x1-shape->length, point_3->y1);
    for(int i = 0 ; i<point_2->x1-point_1->x1 ; i++){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel(point_1->x1+i , point_1->y1);
    }
    for(int i = 0 ; i<point_3->y1-point_2->y1 ; i++){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel(point_2->x1, point_2->y1+i);
    }
    for(int i = 0 ; i<point_3->x1-point_4->x1 ; i++){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel(point_3->x1-i , point_3->y1);
    }
    for(int i = 0 ; i<point_4->y1-point_1->y1 ; i++){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel(point_4->x1 , point_4->y1-i);
    }
}

void pixel_rect(Rectangle * shape, Pixel*** pixel, int* nb_pixels){
    Point *point_1 =shape->top_left;
    Point *point_2 =shape->top_left;
    Point *point_3 =shape->top_left;
    Point *point_4 =shape->top_left;
    point_2->x1 += shape->width;
    point_3->x1 += shape->width;
    point_3->y1 += shape->height;
    point_4->y1 += shape->height;
    for(int i = 0 ; i<point_2->x1-point_1->x1 ; i++){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel(point_1->x1+i , point_1->y1);
    }
    for(int i = 0 ; i<point_3->y1-point_2->y1 ; i++){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel(point_2->x1, point_2->y1+i);
    }
    for(int i = 0 ; i<point_3->x1-point_4->x1 ; i++){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel(point_3->x1-i , point_3->y1);
    }
    for(int i = 0 ; i<point_4->y1-point_1->y1 ; i++){
        *pixel = (Pixel**) realloc(*pixel,((*nb_pixels)+1)*sizeof(Pixel*));
        *pixel[(*nb_pixels)++] = create_pixel(point_4->x1 , point_4->y1-i);
    }
}


void pixel_polygon(Polygon* shape, Pixel*** pixel, int* nb_pixels){
    for(int i = 0 ; i<shape->size-1 ; i++){
        Line* line = create_line(shape->array_of_point[i],shape->array_of_point[i+1]);
        *pixel = realloc(pixel,*nb_pixels);
        pixel_line(line,pixel,nb_pixels);
        delete_line(&line);
    }
}

Pixel** create_shape_to_pixel(Shape* shape, int* nb_pixels,Pixel*** pixel_tab){
    switch (shape->type) {
        case POINT:
            pixel_point(shape->realShape, pixel_tab, nb_pixels);
            break;
        case LINE:
            pixel_line(shape->realShape, pixel_tab, nb_pixels);
            break;
        case SQUARE:
            pixel_square(shape->realShape, pixel_tab, nb_pixels);
            break;
        case RECT:
            pixel_rect(shape->realShape, pixel_tab, nb_pixels);
            break;
        case POLYGON:
            pixel_polygon(shape->realShape, pixel_tab, nb_pixels);
            break;
        case CIRCLE:
            pixel_circle(shape->realShape, pixel_tab, nb_pixels);
            break;
        default:
            break;
    }
}

void afficher_form_test(AREA* area, Pixel** pixel,int *nb_pixel){
    int pix=0;
    for(pix;pix<*nb_pixel;pix++){
        area->mat[pixel[pix]->py-1][pixel[pix]->px-1] = TRUE;
    }
}


void delete_pixel_shape(Pixel** pixel, int nb_pixels);