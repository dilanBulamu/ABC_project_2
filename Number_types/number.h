#ifndef ABC_HW2_BULAMU_DILAN_NUMBER_H
#define ABC_HW2_BULAMU_DILAN_NUMBER_H

#include <fstream>
#include "../myRandom.h"
#include "stdio.h"

//------------------------------------------------------------------------------
// number.h - Contains a description of the generalized number and its interface.
//------------------------------------------------------------------------------

class Number {
public:
    virtual ~Number() {};
    // Getting parameters of a generalized number from file.
    static Number *StaticInput(FILE *input_file);
    // Getting parameters from file.
    virtual void Input(FILE *input_file) = 0;
    // Random generation of generalized number parameters.
    static Number *StaticRandom();
    // Random generation of parameters.
    virtual void Random() = 0;
    // Output of parameters to the formatted stream.
    virtual void Output(FILE *output_file) = 0;
    // Cast to double number.
    virtual double CastToDouble() = 0;
    // Return parameters as a char array.
    virtual char* GetParams() = 0;
};
#endif //ABC_HW2_BULAMU_DILAN_NUMBER_H
