//
// Created by sergiy on 06.03.2020.
//
#include "gtest/gtest.h"
#include <lib.c>

TEST(test, Test2) {
    long long num = 98;
    size_t sizeRomeStr = 0;
    char *Str=NULL;
    Str=getRomeNumber(num, Str, &sizeRomeStr);
    std::cout<<"Size: "<<sizeRomeStr<<"; Str: '"<<Str<<"'"<<std::endl;

    int i=strncmp(Str, "XCVIII", 6);
    if(Str!=NULL) free(Str);
    ASSERT_EQ(sizeRomeStr, 6);
    //ASSERT_EQ(i, 0);

}

TEST(test, FailTest) {
    size_t num=0;
    ASSERT_EQ(checkNumber(num), -1);
    num=-25536;
    ASSERT_EQ(checkNumber(num), -1);
}