//
// Created by Daniil Tchyorny on 03.03.2020.
//

#include "../include/dz.h"

int main() {
    int64_t decNum=47;
    printf("The arabian number is: %d", decNum);
    if (decNum <= 0) {
        printf("Error number\nIt should be greater then zero\n");
        return INCORRECT_NUMBER;
    }
    size_t size = 0;
    char *answer;
    answer=getRomeNumber(decNum, answer, &size);
    printf("Rome number is: ");
    printf("%s", answer);
    printf("\nsize: %lu\n", size);
    return 0;
}