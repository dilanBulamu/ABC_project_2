#include "complex.h"
#include "math.h"

//------------------------------------------------------------------------------
// complex.cpp - Contains complex number methods.
//------------------------------------------------------------------------------

void Complex::Input(FILE *input_file) {
    double real, imaginary;
    if (fscanf(input_file, "%lf %lf", &real, &imaginary) != 2) {
        throw "Incorrect input.";
    }

    this->imaginary = imaginary;
    this->real = real;
}

void Complex::Random() {
    real = GetRandomDouble(min_value, max_value);
    imaginary = GetRandomDouble(min_value,max_value);
}

void Complex::Output(FILE *output_file) {
    fprintf(output_file, "Complex number: real = %lf, imaginary = %lf. Double cast = %lf\n", real, imaginary, CastToDouble());
}

double Complex::CastToDouble() {
    return sqrt(real * real + imaginary * imaginary);
}

char* Complex::GetParams() {
    char* params = new char[255];
    sprintf(params, "%d\n%lf %lf", 0, real, imaginary);
    return params;
}