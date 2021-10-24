#include "complex.h"
#include "fraction.h"
#include "polar.h"

//------------------------------------------------------------------------------
// number.cpp - Contains generalized number methods.
//------------------------------------------------------------------------------

Number* Number::StaticInput(FILE *input_file) {
    int number_type;
    Number* number = nullptr;
    if (fscanf(input_file, "%d'\n", &number_type) != 1) {
        throw "Incorrect input.";
    }
    if (number_type > 2 || number_type < 0) {
        throw "Incorrect input.";
    }

    switch(number_type) {
        case 0:
            number = new Complex;
            break;
        case 1:
            number = new Fraction;
            break;
        case 2:
            number = new Polar;
            break;
    }

    number->Input(input_file);
    return number;
}

Number* Number::StaticRandom() {
    int number_type = GetRandomInt(0, 2);
    Number* number = nullptr;

    switch (number_type) {
        case 0:
            number = new Complex;
            break;
        case 1:
            number = new Fraction;
            break;
        case 2:
            number = new Polar;
            break;
    }

    number->Random();
    return number;
}