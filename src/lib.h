//
// Created by Daniil Tchyorny on 07.03.2020.
//

#ifndef IZ1__LIB_H_
#define IZ1__LIB_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCORRECT_NUMBER -1
#define SEGMENTATION_FAULT -2

enum order {
    UNIT,
    DOZEN,
    HUNDRED,
    THOUSAND
};


uint16_t getOrder(uint64_t num);

int breakOnHundreds(uint64_t num, char *charArr, int sizeChar);

char *getRomeNumber(uint64_t decNum, char *romeNumber, size_t *size);

int addCount(char num, enum order type, char *romeString, size_t *size);

int checkNumber(int64_t num);
#endif //IZ1__LIB_H_
