#ifndef ABC_HW2_BULAMU_DILAN_POLAR_H
#define ABC_HW2_BULAMU_DILAN_POLAR_H

//------------------------------------------------------------------------------
// polar.h - Contains a description of the polar number and its interface.
//------------------------------------------------------------------------------

#include "number.h"
#include "point.h"

class Polar: public Number{
public:
    ~Polar() {};

    // Getting parameters from file.
    void Input(FILE *input_file) override;
    // Random generation of parameters.
    void Random() override;
    // Output of parameters to the formatted stream.
    void Output(FILE *output_file) override;
    // Cast polar to double number.
    double CastToDouble() override;
    // Return parameters as a char array.
    char* GetParams() override;

private:
    // Parameters for random generation.
    const static int min_value = -100;
    const static int max_value = 100;
    // Tilt angle.
    double angle;
    // Location (coordinates).
    Point point;
};
#endif //ABC_HW2_BULAMU_DILAN_POLAR_H
