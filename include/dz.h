//
// Created by Sergei Alexeev on 03.03.2020.
//

#ifndef IZ1_DZ_H
#define IZ1_DZ_H

#include <stdint.h>
#include <stdio.h>

#define INCORRECT_NUMBER -1
#define SEGMENTATION_FAULT -2

static const char *units = "IVX";
static const char *dozens = "XLC";
static const char *hundreds = "CDM";
static const char *thousends = "M";

enum order {
    UNIT,
    DOZEN,
    HUNDRED,
    THOUSAND
};


u_int16_t getOrder(u_int64_t num);

int breakOnHundreds(u_int64_t num, char *charArr, int sizeChar);

char *getRomeNumber(u_int64_t decNum, char *romeNumber, size_t *size);

int addCount(char num, enum order type, char *romeString, size_t *size);


#endif //IZ1_DZ_H
