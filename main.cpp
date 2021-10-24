#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "container/container.h"

/*
 * Программу разработал Буламу Дилан группа БПИ204.
 * Домашнее задание по дисциплине архитектура вычислительных систем задание №2.
 */

#define HELP    "Для генерации случаных параметров введите -r, количество элементов и название файла формата .txt, через пробел.\n"\
                "Пример: -r 100 output.txt\n"\
                "Для открытия файла с параметрами и последующей записи в дугой файл в другом формате\n" \
                "-in названия открываемого файла и загрузочного через пробел.\n"\
                "Пример: -in test_1.txt output_1.txt"\
                 "Для генерации файла с параметрами и последующей записи в дугой файл в другом формате\n" \
                "-s названия генерируемого файла, количество элементов и загрузочного через пробел.\n"\
                "Пример: -s test_1.txt 100 output.txt"

int main(int argc, char* argv[]){
    time_t start, finish;
    start = clock();
    Container* container = new Container();

    if (argc == 4) {
        if (strcmp(argv[1], "-r") == 0) {
            FILE *output_file = fopen(argv[3], "w");
            container->Random(std::atoi(argv[2]), output_file);
        } else if (strcmp(argv[1], "-in") == 0) {
            if (access(argv[2], F_OK) == 0) {
                FILE* input_file = fopen(argv[2], "r");
                try {
                    container->Input(input_file);
                } catch (const char *message) {
                    printf("Error : %s\n", message);
                }
                FILE *output_file = fopen(argv[3], "w");
                container->Output(output_file);
                container-> Sort();
                fprintf(output_file, "\n\n===================================\n\nSorted container:\n\n");
                container->Output(output_file);
            } else {
                printf("Could not open file %s", argv[2]);
                return 1;
            }
        } else {
            printf("The wrong command was entered.");
            printf(HELP);
            return 1;
        }
    } else if (argc == 5) {
        if (strcmp(argv[1], "-s") == 0) {
            if (access(argv[2], F_OK) == 0) {
                FILE *output_file_random = fopen(argv[2], "w");
                container->Random(std::atoi(argv[3]), output_file_random);
                FILE *output_file = fopen(argv[4], "w");
                container->Output(output_file);
                container-> Sort();
                fprintf(output_file, "\n\n===================================\n\nSorted container:\n\n");
                container->Output(output_file);
            } else {
                printf("Could not open file %s", argv[2]);
                return 1;
            }
        }
    } else {
        printf("The wrong command was entered.\n");
        printf(HELP);
        return 1;
    }

    finish = clock();
    printf("Execution: %f\n", difftime(finish, start) / CLOCKS_PER_SEC);
    return 0;
}
// -in /Users/dilanbulamu/CLionProjects/ABC_HW2_Bulamu_Dilan/tests/test_1.txt /Users/dilanbulamu/CLionProjects/ABC_HW2_Bulamu_Dilan/tests/output_1.txt