#ifndef ABC_HW2_BULAMU_DILAN_COMPLEX_H
#define ABC_HW2_BULAMU_DILAN_COMPLEX_H

//------------------------------------------------------------------------------
// complex.h - Contains a description of the complex number and its interface.
//------------------------------------------------------------------------------

#include "number.h"

class Complex: public Number{
public:
    ~Complex() {};

    // Getting parameters from file.
    void Input(FILE *input_file) override;
    // Random generation of parameters.
    void Random() override;
    // Output of parameters to the formatted stream.
    void Output(FILE *output_file) override;
    // Cast comlex number to double number.
    double CastToDouble() override;
    // Return parameters as a char array.
    char* GetParams() override;

private:
    // Parameters for random generation.
    const static int min_value = -1000;
    const static int max_value = 1000;

    double real;
    double imaginary;
};
#endif //ABC_HW2_BULAMU_DILAN_COMPLEX_H
