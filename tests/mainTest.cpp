//
// Created by Daniil Tchyorny on 08.03.2020.
//

#include <iostream>
#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
#include "arabiantorome.h"
}


TEST(Test1, test1) {
ASSERT_EQ(true, true);
int64_t decNumber = 123456;
size_t sizeRomeStr = 0;
char *romeStr = NULL;
romeStr=getRomeNumber(decNumber, romeStr, &sizeRomeStr);
ASSERT_EQ(sizeRomeStr, 11);
ASSERT_EQ(strcmp(romeStr, "CXXIIICDLVI"), 0);
free(romeStr);
}

TEST(Test2, test1) {
long long num = 987;
size_t sizeRomeStr = 0;
char *Str = (char*)malloc(sizeRomeStr + 1);
Str=getRomeNumber(num, Str, &sizeRomeStr);
ASSERT_EQ(sizeRomeStr, 9);
ASSERT_EQ(strcmp(Str, "CMLXXXVII"), 0);
free(Str);
}

TEST(FailTest, test1) {
size_t num=0;
ASSERT_EQ(checkNumber(num), -1);
num=-25536;
ASSERT_EQ(checkNumber(num), -1);
}
