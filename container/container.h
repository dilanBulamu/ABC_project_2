#ifndef ABC_HW2_BULAMU_DILAN_CONTAINER_H
#define ABC_HW2_BULAMU_DILAN_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - Contains a data type representing the simplest container.
//------------------------------------------------------------------------------

#include "../Number_types/number.h"

#define MAX_CONTAINER_SIZE 10001

class Container {
public:
    Container();

    void Input(FILE *input_file);

    void Random(int size, FILE *output_file);

    void Output(FILE *output_file);

    void Sort();

private:
    ~Container();
    void Clear();

    int count_of_elements;
    Number** container;
};


#endif //ABC_HW2_BULAMU_DILAN_CONTAINER_H
