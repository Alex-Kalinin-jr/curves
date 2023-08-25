#include <gtest/gtest.h>

#include <cmath>
#include <vector>

#include "lib/curves.h"

#define EPS 1e-6


TEST(point, a1) {
  fig::Point a(3, 2, 0);
  fig::Point b(3, 2, 0);
  ASSERT_EQ(a, b);
}

TEST(point, a2) {
  fig::RoundFig a(5, 4);
  fig::Point b = a.GetPoint(M_PI / 2);
  fig::Point c(0, 4, 0);
  ASSERT_EQ(b, c);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
