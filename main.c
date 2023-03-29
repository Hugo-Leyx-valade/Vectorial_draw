#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Point.h"
#include "Line.h"
#include "Polygon.h"

int main() {
    Polygon* polygon;
    polygon = create_polygone(3);
    display_polygon(polygon);
    return 0;
}
