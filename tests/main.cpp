//
// Created by paul_s on 02.03.2020.
//

#include <gtest/gtest.h>
#include "../project/include/arabiantorome.h"


TEST(testMainFunc, test1) {
ASSERT_EQ(true, true);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}