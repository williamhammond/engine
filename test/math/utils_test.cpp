#include "math/utils.h"

#include <gtest/gtest.h>

#include <vector>

struct AbsTest {
  float expected;
  float x;
};
TEST(Utils, it_calculates_abs) {
  std::vector<AbsTest> tests = {
      AbsTest{0, 0},
      AbsTest{1, 1},
      AbsTest{1, -1},
      AbsTest{
          1.00000001f,
          1.00000001f,
      },
      AbsTest{
          1.00000001f,
          -1.00000001f,
      },
  };

  for (auto test : tests) {
    EXPECT_EQ(test.expected, Utils::abs(test.x));
  }
}

struct SquareTest {
  float expected;
  float x;
  float tolerance;
};
TEST(Utils, it_calculates_square) {
  std::vector<SquareTest> tests = {
      SquareTest{9, -3, 0.01f}, SquareTest{4, -2, 0.01f},
      SquareTest{1, -1, 0.01f}, SquareTest{0, 0, 0.01f},
      SquareTest{1, 1, 0.01f},  SquareTest{4, 2, 0.01f},
      SquareTest{9, 3, 0.01f},
  };

  for (auto test : tests) {
    EXPECT_NEAR(test.expected, Utils::square(test.x), test.tolerance);
  }
}

struct SqrtTest {
  float expected;
  float x;
  float tolerance;
};
TEST(Utils, it_calculates_sqrt) {
  std::vector<SqrtTest> tests = {
      SqrtTest{0, 0, 0.01f},
      SqrtTest{1, 1, 0.01f},
  };

  for (auto test : tests) {
    EXPECT_NEAR(test.expected, Utils::sqrt(test.x), test.tolerance);
  }
}
