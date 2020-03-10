//
// Created by Daniil Tchyorny on 03.03.2020.
//

#include "../include/dz.h"

int main() {
    int64_t decNum = 98;
    printf("The arabian number is: %ld", decNum);
    if (decNum <= 0) {
        printf("Error number\nIt should be greater then zero\n");
        return 0;
    }
    size_t size = 0;
    char *answer = NULL;
    answer = getRomeNumber(decNum, answer, &size);
    printf("\nRome number is: ");
    printf("%s", answer);
    printf("\nsize: %lu\n", size);
    return 0;
}
