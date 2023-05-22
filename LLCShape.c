//
// Created by maloc on 22/04/2023.
//

#include "LLCShape.h"

LlcShape* create_empty_llc(){
    LlcShape* cell = (LlcShape*) malloc(sizeof (LlcShape));
    cell = NULL;
    return cell;
}


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
    return firstcell;
}

LlcShape* add_to_llc(LlcShape* cell, Shape* value){
    if(llc_empty(cell)==FALSE){
        LlcShape* lastcell = create_cell(value);
        LlcShape* temp = cell;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next=lastcell;
        return cell;
    }else{
        cell = create_cell(value);
        return cell;
    }
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

void display_llc(LlcShape* cell){
    if(llc_empty(cell)==FALSE){
        LlcShape* temp = cell;
        while(temp != NULL){
            printf("%d : ",temp->value->id_shape);
            display_shape(temp->value);
            printf("\n");
            temp = temp->next;
        }
    }
}



Shape* getShapeById(LlcShape* cell, unsigned int id){
    LlcShape* temp = cell;
    while((temp != NULL) && (temp->value->id_shape != id)){
        temp = temp->next;
    }
    return temp->value;
}

void deleteShapeFromLlc(LlcShape** cell,unsigned int id){
    LlcShape* temp = *cell;
    if((*cell)->value->id_shape==id){
        temp=(*cell)->next;
        delete_shape((*cell)->value);
        (*cell)=temp;
    }else{
        while((temp->next != NULL) && (temp->next->value->id_shape != id)){
            temp = temp->next;
        }
        if(temp->next!=NULL && temp->next->value->id_shape == id){
            delete_shape(temp->next->value);
            temp->next=temp->next->next;
        }
    }
}
