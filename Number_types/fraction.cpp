#include "fraction.h"

//------------------------------------------------------------------------------
// fraction.cpp - Contains fraction number methods.
//------------------------------------------------------------------------------

void Fraction::Input(FILE *input_file) {
    int numerator, denominator;
    if (fscanf(input_file, "%d %d", &numerator, &denominator) != 2) {
        throw "Incorrect input.";
    }

    if (denominator == 0) {
        throw "Error: denominator = 0.";
    }

    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::Random() {
    numerator = GetRandomInt(min_value, max_value);
    denominator = GetRandomInt(1, max_value);
}

void Fraction::Output(FILE *output_file) {
    fprintf(output_file, "Fraction number: %d/%d . Double cast = %lf\n", numerator, denominator, CastToDouble());
}

double Fraction::CastToDouble() {
    return (double) numerator / denominator;
}

char* Fraction::GetParams() {
    char* params = new char[255];
    sprintf(params, "%d\n%d %d", 1, numerator, denominator);
    return params;
}