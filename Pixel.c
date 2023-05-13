//
// Created by hugol on 09/05/2023.
//

#include "Pixel.h"

//
// Created by hugol on 09/05/2023.
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

void pixel_point(Point * shape, Pixel** pixel, int* nb_pixels){
//    Point* pt = (Point*) shape->realShape;
    *pixel = (Pixel*) malloc(sizeof (Pixel));
//    *nb_pixels = 0;
    pixel[(*nb_pixels)++] = create_pixel(shape->x1 , shape->y1);
}

void pixel_line(Line* shape, Pixel** pixel, int* nb_pixels){
//    Line* line = (Line*) shape->realShape;
    *pixel = (Pixel*) malloc(sizeof (Pixel));
//    *nb_pixels = 0;
    int longx;
    int longy;
    longx = shape->point_2->x1 - shape->point_1->x1;
    longy = shape->point_2->y1 - shape->point_1->y1;
    int longmin;
    int longmax;
    if(longx<(sqrt(longy*longy))){
        longmin=longx;
        longmax=longy;
    }else{
        longmin=longy;
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
    int x = shape->point_1->x1;
    int y = shape->point_1->y1;
    if(longy<0){
        if(longx>0){
            for(int i=0;i<nbseg;i++){
                for(int j=0;j<tabsegs[i];j++){
                    pixel[(*nb_pixels)++] = create_pixel(x , y);
                    x++;
                }
                y++;
            }
        }else{
            for(int i=0;i<nbseg;i++){
                for(int j=0;j<tabsegs[i];j++){
                    pixel[(*nb_pixels)++] = create_pixel(x , y);
                    x--;
                }
                y++;
            }
        }
    }else{
        if(longx>0){
            for(int i=0;i<nbseg;i++){
                for(int j=0;j<tabsegs[i];j++){
                    pixel[(*nb_pixels)++] = create_pixel(x , y);
                    x++;
                }
                y--;
            }
        }else{
            for(int i=0;i<nbseg;i++){
                for(int j=0;j<tabsegs[i];j++){
                    pixel[(*nb_pixels)++] = create_pixel(x , y);
                    x--;
                }
                y--;
            }
        }
    }
}


void pixel_circle(Circle* shape, Pixel** pixel, int* nb_pixels){
    int x = 0;
//    Circle *circle = (Circle*) shape->realShape;
    int y = shape->radius;
    int d = shape->radius - 1 ;
//    nb_pixels = 0;
    Pixel* px = NULL;
    while (y>=x){
        pixel[*nb_pixels++] = create_pixel(shape->center->x1+x , shape->center->y1+y);
        pixel[*nb_pixels++] = create_pixel(shape->center->x1+y , shape->center->y1+x);
        pixel[*nb_pixels++] = create_pixel(shape->center->x1-x , shape->center->y1+y);
        pixel[*nb_pixels++] = create_pixel(shape->center->x1-y , shape->center->y1+x);
        pixel[*nb_pixels++] = create_pixel(shape->center->x1+x , shape->center->y1-y);
        pixel[*nb_pixels++] = create_pixel(shape->center->x1+y , shape->center->y1-x);
        pixel[*nb_pixels++] = create_pixel(shape->center->x1-x , shape->center->y1-y);
        pixel[*nb_pixels++] = create_pixel(shape->center->x1-y , shape->center->y1-x);
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

void pixel_square(Square * shape, Pixel** pixel, int* nb_pixels){
//    Square *square = (Square *) shape->realShape;
//    *nb_pixels = 0 ;
    Point *point_1 =shape->top_left;
    Point *point_2 = create_point(point_1->x1+shape->length,point_1->y1);
    Point *point_3 = create_point(point_2->x1 , point_2->y1+shape->length);
    Point *point_4 = create_point(point_3->x1-shape->length, point_3->y1);
    for(int i = 0 ; i<point_2->x1-point_1->x1 ; i++){
        pixel = realloc(pixel,++*nb_pixels);
        pixel[*nb_pixels++] = create_pixel(point_1->x1+i , point_1->y1);
    }
    for(int i = 0 ; i<point_3->y1-point_2->y1 ; i++){
        pixel = realloc(pixel,++*nb_pixels);
        pixel[*nb_pixels++] = create_pixel(point_2->x1, point_2->y1+i);
    }
    for(int i = 0 ; i<point_4->x1-point_3->x1 ; i++){
        pixel = realloc(pixel,++*nb_pixels);
        pixel[*nb_pixels++] = create_pixel(point_3->x1-i , point_3->y1);
    }
    for(int i = 0 ; i<point_1->y1-point_4->y1 ; i++){
        pixel = realloc(pixel,++*nb_pixels);
        pixel[*nb_pixels++] = create_pixel(point_4->x1 , point_4->y1-i);
    }
}

void pixel_rect(Rectangle * shape, Pixel** pixel, int* nb_pixels){
//    Rectangle* rect = (Rectangle*) shape->realShape;
//    *nb_pixels = 0 ;
    Point *point_1 =shape->top_left;
    Point *point_2 =shape->top_left;
    Point *point_3 =shape->top_left;
    Point *point_4 =shape->top_left;
    point_2->x1 += shape->width;
    point_3->x1 += shape->width;
    point_3->y1 += shape->height;
    point_4->y1 += shape->height;
    for(int i = 0 ; i<point_2->x1-point_1->x1 ; i++){
        pixel[*nb_pixels++] = create_pixel(point_1->x1+i , point_1->y1);
    }
    for(int i = 0 ; i<point_3->y1-point_2->y1 ; i++){
        pixel[*nb_pixels++] = create_pixel(point_2->x1, point_2->y1+i);
    }
    for(int i = 0 ; i<point_4->x1-point_3->x1 ; i++){
        pixel[*nb_pixels++] = create_pixel(point_3->x1-i , point_3->y1);
    }
    for(int i = 0 ; i<point_1->y1-point_4->y1 ; i++){
        pixel[*nb_pixels++] = create_pixel(point_4->x1 , point_4->y1-i);
    }
}


void pixel_polygon(Polygon* shape, Pixel** pixel, int* nb_pixels){
//    Polygon *polygon = (Polygon*) shape->realShape;
//    *nb_pixels = 0 ;
    for(int i = 0 ; i<shape->size-1 ; i++){
        Line* line = create_line(shape->array_of_point[i],shape->array_of_point[i+1]);
        pixel = realloc(pixel,*nb_pixels);
        pixel_line(line,pixel,nb_pixels);
        delete_line(&line);
    }
}

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels){
    Pixel** pixel_tab = (Pixel**) malloc(*nb_pixels*sizeof (Pixel*));

}

void afficher_form_test(Pixel**pixel,int *nb_pixel){
    int** tab = (int**) calloc(10,sizeof (int*));
    for (int i = 0 ; i<10 ; i++){
        *tab = (int*) calloc(1,sizeof (int));
    }
    for(int i = 0 ; i<*nb_pixel ; i++){
        tab[pixel[*nb_pixel]->py][pixel[*nb_pixel]->px] = 1 ;
    }
    for(int i = 0 ; i<30 ; i++){
        for (int j = 0 ; j < 30 ; j++){
            printf("%d" , tab[i][j]);
        }
    }
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels);
