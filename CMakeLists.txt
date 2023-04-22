cmake_minimum_required(VERSION 3.24)
project(Vectorial_draw1 C)

set(CMAKE_C_STANDARD 99)


add_executable(Vectorial_draw main.c Square.c Square.h Circle.c Circle.h Rect.c Rect.h Line.c Line.h Point.c Point.h Polygon.c Polygon.h Forms.c Forms.h stringToArray.c stringToArray.h Shapes.c Shapes.h LLCShape.c LLCShape.h Bool.c Bool.h " CharToInt.c" " CharToInt.h")
