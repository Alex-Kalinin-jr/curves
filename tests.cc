#include <gtest/gtest.h>

#include <vector>

#include "lib/curves.h"

#define EPS 1e-6

TEST(Cell, a1) {
  fig::RoundFig a(5, 4);
  ASSERT_EQ(4, 4);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
