//
// Created by paul_s on 02.03.2020.
//

#include <gtest/gtest.h>
#include "arabiantorome.h"


TEST(testMainFunc, test1) {
ASSERT_EQ(true, true);
int64_t decNumber = 123456;
size_t sizeRomeStr = 0;
char *romeStr;
romeStr=getRomeNumber(decNumber, romeStr, &sizeRomeStr);
ASSERT_EQ(sizeRomeStr, 11);
ASSERT_EQ(strcmp(romeStr, "CXXIIICDLVI"), 0);

long long num = 987;
sizeRomeStr = 0;
char *Str = (char*)malloc(sizeRomeStr + 1);
Str=getRomeNumber(num, Str, &sizeRomeStr);
ASSERT_EQ(sizeRomeStr, 9);
ASSERT_EQ(strcmp(Str, "CMLXXXVII"), 0);

num=0;
ASSERT_EQ(checkNumber(num), -1);

num=-25536;
ASSERT_EQ(checkNumber(num), -1);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}