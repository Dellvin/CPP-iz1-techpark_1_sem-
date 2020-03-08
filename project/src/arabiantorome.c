//
// Created by Daniil Tchyorny on 07.03.2020.
//

#include "../include/arabiantorome.h"
#include <math.h>

  static const char *units = "IVX";
  static const char *dozens = "XLC";
  static const char *hundreds = "CDM";

  uint16_t getOrder(uint64_t num) {
    uint64_t dozen = 10;
    int order = 1;
    do {
        dozen *= 10;
        order++;
    } while (num / dozen);
    return order;
}

  int breakOnHundreds(uint64_t num, char *charArr, int sizeChar) {
    int numLength = getOrder(num);
    int size = 0;
    int *arr = NULL;
    arr = malloc(numLength * 4);
    if (!arr) return SEGMENTATION_FAULT;
    do {
        arr[size] = num % 10;
        num /= 10;
        size += 1;
    } while (num != 0);
    int j = 0;
    for (int i = 0; i < sizeChar; i++) {
        if (i % 4 == 3) {
            charArr[i] = ' ';
        } else {
            charArr[i] = arr[j] + '0';
            j++;
        }
    }
    free(arr);
    return sizeChar;
}

int checkNumber(int64_t num) {
    if (num <= 0) {
        return -1;
    } else { return 0; }
}

char *getRomeNumber(uint64_t decNum, char *romeNumber, size_t *size) {
      romeNumber = calloc(*size + 1);
    if (!romeNumber) return NULL;
    if (checkNumber(decNum) == INCORRECT_NUMBER)
        return NULL;
    int numLength = getOrder(decNum);
    int sizeChar = numLength + (numLength - 1) / 3;
    char *arr = NULL;
    arr = malloc(sizeChar);
    if (!arr) {
        return NULL;
    }
    memset(arr, '\0', sizeChar);
    int sizeOfCharBuf = breakOnHundreds(decNum, arr, sizeChar);
    if (sizeOfCharBuf == SEGMENTATION_FAULT) return NULL;

    char buf[3] = {0};
    int pos = 0;
    for (int i = sizeOfCharBuf - 1; i >= 0; --i) {
        if (arr[i] != ' ') {
            buf[pos] = arr[i];
            pos++;
        }
        if (arr[i] == ' ' || i == 0) {
            if (pos == 1) {
                if (i > 2 && buf[0] - '0' < 4) {
                    if(addCount(buf[0], THOUSAND, romeNumber, size)==SEGMENTATION_FAULT){
                        free(arr);
                        return NULL;
                    }
                } else {
                    if(addCount(buf[0], UNIT, romeNumber, size)==SEGMENTATION_FAULT){
                        free(arr);
                        return NULL;
                    }
                }
            } else if (pos == 2) {
                if(addCount(buf[0], DOZEN, romeNumber, size)==SEGMENTATION_FAULT){
                    free(arr);
                    return NULL;
                }
                if(addCount(buf[1], UNIT, romeNumber, size)==SEGMENTATION_FAULT){
                    free(arr);
                    return NULL;
                }
            } else {
                if(addCount(buf[0], HUNDRED, romeNumber, size)==SEGMENTATION_FAULT){
                    free(arr);
                    return NULL;
                }
                if(addCount(buf[1], DOZEN, romeNumber, size)==SEGMENTATION_FAULT){
                    free(arr);
                    return NULL;
                }
                if(addCount(buf[2], UNIT, romeNumber, size)==SEGMENTATION_FAULT){
                    free(arr);
                    return NULL;
                }
            }
            pos = 0;
            memset(buf, '\0', 3);
        }
    }
    char *checkRealloc = realloc(romeNumber, *size + 1);
    if (!checkRealloc) {
        free(arr);
        free(romeNumber);
        return NULL;
    }
    romeNumber = checkRealloc;
    romeNumber[*size] = '\0';
    free(arr);
    return romeNumber;
}

  int addCount(char num, enum order type, char *romeString, size_t *size) {
    char orderSting[4];
    if (type == THOUSAND) snprintf(orderSting, sizeof(orderSting), "%s", units);
    if (type == HUNDRED) snprintf(orderSting, sizeof(orderSting), "%s", hundreds);
    if (type == DOZEN) snprintf(orderSting, sizeof(orderSting), "%s", dozens);
    if (type == UNIT) snprintf(orderSting, sizeof(orderSting), "%s", units);
    if ((num - '0') < 4) {
        for (int i = (num - '0'); i > 0; i--) {
            *size += 1;
            char *checkRealloc = realloc(romeString, *size);
            if (!checkRealloc) {
                free(romeString);
                return SEGMENTATION_FAULT;;
            }
            romeString[*size - 1] = orderSting[0];
        }
        return 0;
    }
    if ((num - '0') < 9) {
        if ((num - '0') == 4) {
            *size += 2;
            char *checkRealloc = realloc(romeString, *size);
            if (!checkRealloc) {
                free(romeString);
                return SEGMENTATION_FAULT;;
            }
            romeString[*size - 2] = orderSting[0];
            romeString[*size - 1] = orderSting[1];
        } else {
            *size += 1;
            char *checkRealloc = realloc(romeString, *size);
            if (!checkRealloc) {
                free(romeString);
                return SEGMENTATION_FAULT;;
            }
            romeString=checkRealloc;
            romeString[*size - 1] = orderSting[1];
            for (int i = (num - '0'); i > 5; --i) {
                *size += 1;
                char *checkRealloc = realloc(romeString, *size);
                if (!checkRealloc) {
                    free(romeString);
                    return SEGMENTATION_FAULT;;
                }
                romeString=checkRealloc
                romeString[*size - 1] = orderSting[0];
            }
        }
        return 0;
    } else {
        *size += 2;
        char *checkRealloc = realloc(romeString, *size);
        if (!checkRealloc) {
            free(romeString);
            return SEGMENTATION_FAULT;;
        }
        romeString = checkRealloc;
        romeString[*size - 2] = orderSting[0];
        romeString[*size - 1] = orderSting[2];
        return 0;
    }
}
