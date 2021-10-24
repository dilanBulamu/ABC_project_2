#ifndef ABC_HW2_BULAMU_DILAN_MYRANDOM_H
#define ABC_HW2_BULAMU_DILAN_MYRANDOM_H

#include "math.h"
#include "stdio.h"
#include "stdlib.h"

static int GetRandomInt(int min_value, int max_value) {
    if (min_value > max_value) {
        printf("The first value cannot be greater than the second!");
        exit(1);
    }
    return rand() % (max_value - min_value + 1) + min_value;
}

static double GetRandomDouble(int min_value, int max_value) {
    if (min_value > max_value) {
        printf("The first value cannot be greater than the second!");
        exit(1);
    }
    return rand() % (max_value - min_value + 1) + (double) rand() / RAND_MAX;
}

#endif //ABC_HW2_BULAMU_DILAN_MYRANDOM_H
