//
// Created by maloc on 22/04/2023.
//

#include " CharToInt.h"


Bool isnumber(StringArray* stringArray){
    Bool number=TRUE;
    for(int i=0;i<stringArray->size;i++){
        if(*(stringArray->array[i])<47 || *(stringArray->array[i])>58){
            number=FALSE;
        }
    }
    return number;
}

CoordTab* StringArrayToCoordTab(StringArray* stringArray){
    CoordTab* coordTab = (CoordTab*) malloc(sizeof(CoordTab));
    coordTab->size= stringArray->size;
    coordTab->coords = (int*) malloc(coordTab->size*sizeof(int) );
    if(isnumber(stringArray)==TRUE){
        for(int i=0;i<stringArray->size;i++){
            coordTab->coords[i]=atoi(stringArray->array[i]);
        }
    }
    return coordTab;
}