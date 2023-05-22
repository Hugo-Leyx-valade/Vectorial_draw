//
// Created by hugol on 24/03/2023.
//

#include "Forms.h"

TypeForm StringToTypeForm(char* form){
    if(strcmp(form,"POINT")==0){
        return POINT;
    }else if(strcmp(form,"LINE")==0){
        return LINE;
    }else if(strcmp(form,"SQUARE")==0){
        return SQUARE;
    }else if(strcmp(form,"RECT")==0){
        return RECT;
    }else if(strcmp(form,"CIRCLE")==0){
        return CIRCLE;
    }else if(strcmp(form,"POLYGON")==0){
        return POLYGON;
    }else{
        return POINT;
    }
}
