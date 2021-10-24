#include "point.h"

//------------------------------------------------------------------------------
// polar.cpp - Contains point methods.
//------------------------------------------------------------------------------

Point::Point() {

}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point Point::Random() {
    int x = GetRandomInt(min_value, max_value);
    int y = GetRandomInt(min_value, max_value);
    return Point(x, y);
}

Point Point::Input(FILE *input_file) {
    int x, y;
    if (fscanf(input_file, "%d %d", &x, &y) != 2) {
        throw "Incorrect input.";
    }

    Point point(x, y);

    return point;
}

void Point::Output(FILE *output_file) {
    fprintf(output_file, "(%d, %d)", x, y);
}

double Point::GetLength() {
    return sqrt(x * x + y * y);
}

int Point::X() {
    return x;
}

int Point::Y() {
    return y;
}