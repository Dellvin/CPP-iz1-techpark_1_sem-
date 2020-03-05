//
// Created by Sergei Alexeev on 03.03.2020.
//

#include "gtest/gtest.h"
extern "C" {
#include "dz.h"
}

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

//    num = -234;
//    sizeRomeStr = 0;
//    char *irrcorrectStr = (char*)malloc(sizeRomeStr + 1);
//    irrcorrectStr=getRomeNumber(num, irrcorrectStr, &sizeRomeStr);
//    ASSERT_EQ(sizeRomeStr, 0);
////    ASSERT_EQ(irrcorrectStr, NULL);
////
//    num = 0;
//    sizeRomeStr = 0;
//    char *irrcorrectStrTwo = (char*)malloc(sizeRomeStr + 1);
//    irrcorrectStrTwo=getRomeNumber(num, irrcorrectStrTwo, &sizeRomeStr);
//    ASSERT_EQ(sizeRomeStr, 0);
////    ASSERT_EQ(irrcorrectStrTwo, NULL);
}
