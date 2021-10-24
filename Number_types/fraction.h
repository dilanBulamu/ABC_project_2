#ifndef ABC_HW2_BULAMU_DILAN_FRACTION_H
#define ABC_HW2_BULAMU_DILAN_FRACTION_H

//------------------------------------------------------------------------------
// fraction.h - Contains a description of the fraction number and its interface.
//------------------------------------------------------------------------------

#include "number.h"

class Fraction: public Number{
public:
    ~Fraction() {};

    // Getting parameters from file.
    void Input(FILE *input_file) override;
    // Random generation of parameters.
    void Random() override;
    // Output of parameters to the formatted stream.
    void Output(FILE *output_file) override;
    // Cast fraction to double number.
    double CastToDouble() override;
    // Return parameters as a char array.
    char* GetParams() override;

private:
    // Parameters for random generation.
    const static int min_value = -1000;
    const static int max_value = 1000;

    int numerator;
    int denominator;
};

#endif //ABC_HW2_BULAMU_DILAN_FRACTION_H
