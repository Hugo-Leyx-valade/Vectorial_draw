//
// Created by maloc on 22/04/2023.
//

#include "LLCShape.h"
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
    LlcShape* temp = cell;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=lastcell;
    return cell;
}

int taille_liste(LlcShape* cell){
    int i=0;
    LlcShape* temp = cell;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

void afficher_liste(LlcShape* cell){
    LlcShape* temp = cell;
    while(temp != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

Shape* getShapeById(LlcShape* cell, unsigned int id){
    LlcShape* temp = cell;
    while((temp != NULL) && (temp->value->id_shape != id)){
        temp = temp->next;
    }
    return temp->value;
}