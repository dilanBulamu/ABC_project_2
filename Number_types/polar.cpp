#include "polar.h"

//------------------------------------------------------------------------------
// polar.cpp - Contains polar number methods.
//------------------------------------------------------------------------------

void Polar::Input(FILE *input_file) {
    double angle;

    if (fscanf(input_file, "%lf", &angle) != 1) {
        throw "Incorrect input.";
    }

    this->angle = angle;
    this->point = Point::Input(input_file);
}

void Polar::Random() {
    angle = GetRandomDouble(min_value, max_value);
    point = Point::Random();
}

void Polar::Output(FILE *output_file) {
    fprintf(output_file, "Polar number: angle = %lf, coordinates =  ", angle);
    point.Output(output_file);
    fprintf(output_file, ". Double cast =  %lf\n", CastToDouble());
}

double Polar::CastToDouble() {
    return point.GetLength();
}

char* Polar::GetParams() {
    char* params = new char[255];
    sprintf(params, "%d\n%lf %d %d", 2, angle, point.X(), point.Y());
    return params;
}