#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "Commands.h"

int main() {
    int exit_status=0;
    AREA* area = create_area(50,50);
    while(exit_status==0){
        action(&exit_status,area);
    }






    return 0;
}
