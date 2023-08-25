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

TEST(Ellipse, a2) {
  fig::Ellipse a(5, 4);

  fig::Point b1 = a.GetPoint(M_PI / 2);
  fig::Point c1(0, 4, 0);
  ASSERT_EQ(b1, c1);

  fig::Point b2 = a.GetPoint(M_PI);
  fig::Point c2(-5, 0, 0);
  ASSERT_EQ(b2, c2);

  fig::Point b3 = a.GetPoint(3 * M_PI / 2);
  fig::Point c3(0, -4, 0);
  ASSERT_EQ(b3, c3);

  fig::Point b4 = a.GetPoint(2 * M_PI);
  fig::Point c4(5, 0, 0);
  ASSERT_EQ(b4, c4);
}

TEST(Circle, a1) {
  fig::Circle a(5);

  fig::Point b1 = a.GetPoint(M_PI / 2);
  fig::Point c1(0, 5, 0);
  ASSERT_EQ(b1, c1);

  fig::Point b2 = a.GetPoint(M_PI);
  fig::Point c2(-5, 0, 0);
  ASSERT_EQ(b2, c2);

  fig::Point b3 = a.GetPoint(3 * M_PI / 2);
  fig::Point c3(0, -5, 0);
  ASSERT_EQ(b3, c3);

  fig::Point b4 = a.GetPoint(2 * M_PI);
  fig::Point c4(5, 0, 0);
  ASSERT_EQ(b4, c4);
}

TEST(Helix, a1) {
  fig::Helix a(5, 2);

  fig::Point b1 = a.GetPoint(M_PI / 2);
  fig::Point c1(0, 5, 0.5);
  ASSERT_EQ(b1, c1);

  // fig::Point b2 = a.GetPoint(M_PI);
  // fig::Point c2(-5, 0, 1);
  // ASSERT_EQ(b2, c2);

  // fig::Point b3 = a.GetPoint(3 * M_PI / 2);
  // fig::Point c3(0, -5, 1.5);
  // ASSERT_EQ(b3, c3);

  // fig::Point b4 = a.GetPoint(2 * M_PI);
  // fig::Point c4(5, 0, 2);
  // ASSERT_EQ(b4, c4);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
