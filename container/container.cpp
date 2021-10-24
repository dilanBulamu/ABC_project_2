#include "container.h"

//------------------------------------------------------------------------------
// container.cpp - Contains a data type representing the simplest container.
//------------------------------------------------------------------------------

Container::Container() {
    count_of_elements = 0;
    container = new Number* [MAX_CONTAINER_SIZE];
    for (int i = 0; i < MAX_CONTAINER_SIZE; ++i) {
        container[i] = nullptr;
    }
}

Container::~Container() {
    Clear();
}

void Container::Input(FILE *input_file) {
    int count_of_elements;

    if (fscanf(input_file, "%d", &count_of_elements) != 1) {
        printf("Incorrect input.");
        exit(1);
    } else if (count_of_elements <= 0) {
        printf("The count of elements cannot be less or equels zero.");
        exit(1);
    } else if (count_of_elements >= MAX_CONTAINER_SIZE) {
        printf("The count of elements is more then the container can hold");
        exit(1);
    }

    this->count_of_elements = count_of_elements;

    for (int i = 0; i < count_of_elements; ++i) {
        try {
            Number* number = Number::StaticInput(input_file);
            container[i] = number;
        } catch (const char *message) {
            printf("Error with %d number: %s\n", i + 1, message);
            exit(1);
        }
    }
}

void Container::Random(int size, FILE *output_file) {
    fprintf(output_file, "%d\n", size);
    while(count_of_elements < size) {
        Number* number = Number::StaticRandom();
        container[count_of_elements++] = number;

        fprintf(output_file, "%s\n", number->GetParams());
    }
}

void Container::Output(FILE *output_file) {
    fprintf(output_file, "Container contains: %d elements.\n", count_of_elements);
    for(int i = 0; i < count_of_elements; i++) {
        fprintf(output_file, "%d: ", i + 1);
        container[i]->Output(output_file);
    }
}

void Container::Clear() {
    for (int i = 0; i < count_of_elements; ++i) {
        delete container[i];
    }
    delete container;
    count_of_elements = 0;
}

void Container::Sort() {
    for(int i = 0; i < count_of_elements; ++i) {
        Number* buffer = container[i];
        int j = i;
        for (; j > 0 && container[j-1]->CastToDouble() > buffer->CastToDouble(); --j) {
            container[j] = container[j-1];
        }
        container[j] = buffer;
    }
}