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

void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels){
    Point* pt = (Point*) shape->realShape;
    *pixel = (Pixel*) malloc(sizeof (Pixel));
    *nb_pixels = 0;
    pixel[(*nb_pixels)++] = create_pixel(pt->x1 , pt->y1);
}

void pixel_line(Shape* shape, Pixel** pixel, int* nb_pixels){
    Line* line = (Line*) shape->realShape;
    *pixel = (Pixel*) malloc(sizeof (Pixel));
    *nb_pixels = 0;
    int longx;
    int longy;
    longx = line->point_2->x1 - line->point_1->x1;
    longy = line->point_2->y1 - line->point_1->y1;
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
    int x = line->point_1->x1;
    int y = line->point_1->y1;
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


void pixel_circle(Shape* shape, Pixel** pixel, int* nb_pixels){
    int x = 0;
    Circle *circle = (Circle*) shape->realShape;
    int y = circle->radius;
    int d = circle->radius - 1 ;
    nb_pixels = 0;
    Pixel* px = NULL;
    while (y>=x){
        pixel[*nb_pixels++] = create_pixel(circle->center->x1+x , circle->center->y1+y);
        pixel[*nb_pixels++] = create_pixel(circle->center->x1+y , circle->center->y1+x);
        pixel[*nb_pixels++] = create_pixel(circle->center->x1-x , circle->center->y1+y);
        pixel[*nb_pixels++] = create_pixel(circle->center->x1-y , circle->center->y1+x);
        pixel[*nb_pixels++] = create_pixel(circle->center->x1+x , circle->center->y1-y);
        pixel[*nb_pixels++] = create_pixel(circle->center->x1+y , circle->center->y1-x);
        pixel[*nb_pixels++] = create_pixel(circle->center->x1-x , circle->center->y1-y);
        pixel[*nb_pixels++] = create_pixel(circle->center->x1-y , circle->center->y1-x);
        if(d>=2*x){
            d -= 2*x+1;
            x++;
        } else if(d < 2*(circle->radius-y)){
            d += 2*y-1;
            y-- ;
        }else{
            d+= 2*(y-x-1);
            y--;
            x++;
        }
    }
}

void pixel_square(Shape* shape, Pixel** pixel, int* nb_pixels){
    Square* square = (Square*) shape->realShape;
    *nb_pixels = 0 ;
    Point *point_1 = square->top_left;
    Point *point_2 = square->top_left;
    Point *point_3 = square->top_left;
    Point *point_4 = square->top_left;
    point_2->x1 += square->length;
    point_3->x1 += square->length;
    point_3->y1 += square->length;
    point_4->y1 = square->length;
    for(int i = 0 ; i<)
}
