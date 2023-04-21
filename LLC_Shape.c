//
// Created by maloc on 21/04/2023.
//

#include "LLC_Shape.h"
LlcShape* create_cell(Shape* value){
    LlcShape* cell = (LlcShape*) malloc(sizeof (LlcShape));
    cell->value= value;
    cell->next=NULL;
    return cell;
}

Bool llc_empty(LlcShape* cell){
    if ( cell == NULL){
        return TRUE;
    } else {
        return FALSE;
    }
}

LlcShape* add_to_first(LlcShape* cell, Shape* value){
    LlcShape* firstcell= create_cell(value);
    firstcell->next = cell;
    firstcell=cell;
    return firstcell;
}

LlcShape* add_to_last(LlcShape* cell, Shape* value){
    LlcShape* lastcell = create_cell(value);
    if(cell!=NULL){
        LlcShape* temp = cell;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next=lastcell;
    }else{
        return lastcell;
    }
    return cell;
}

int length_llc(LlcShape* cell){
    int i=0;
    LlcShape* temp = cell;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

void show_full_llc(LlcShape* cell){
    LlcShape* temp = cell;
    while(temp != NULL){
        TypeForm type = temp->value->type;
        temp = temp->next;
    }
}