#ifndef ABC_HW2_BULAMU_DILAN_POINT_H
#define ABC_HW2_BULAMU_DILAN_POINT_H

#include "../myRandom.h"
#include "math.h"
#include "stdio.h"

//------------------------------------------------------------------------------
// polar.h - Contains a description of the polar number and its interface.
//------------------------------------------------------------------------------

class Point {
private:
    // Parameters for random generation.
    const static int min_value = -1000;
    const static int max_value = 1000;
    // Coordinates
    int x;
    int y;

public:
    // Parameterless constructor.
    Point();
    // Constructor with parameters.
    Point(int x, int y);
    // Random generation of parameters.
    static Point Random();
    // Getting parameters from file.
    static Point Input(FILE *input_file);
    // Output of parameters to the formatted stream.
    void Output(FILE *output_file);
    // Getting the distance from x to y.
    double GetLength();
    // Return x value.
    int X();
    // Return y value.
    int Y();
};


#endif //ABC_HW2_BULAMU_DILAN_POINT_H
