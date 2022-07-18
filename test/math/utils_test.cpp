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
};
TEST(Utils, it_calculates_square) {
  std::vector<SquareTest> tests = {
      SquareTest{9, -3}, SquareTest{4, -2}, SquareTest{1, -1}, SquareTest{0, 0},
      SquareTest{1, 1},  SquareTest{4, 2},  SquareTest{9, 3},
  };

  for (auto test : tests) {
    auto actual = Utils::square(test.x);
    EXPECT_NEAR(test.expected, actual,
                Utils::relative_epsilon(test.expected, actual));
  }
}

struct SqrtTest {
  float expected;
  float x;
};
TEST(Utils, it_calculates_sqrt) {
  std::vector<SqrtTest> tests = {
      SqrtTest{0, 0},
      SqrtTest{1, 1},
  };

  for (auto test : tests) {
    auto actual = Utils::sqrt(test.x);
    EXPECT_NEAR(test.expected, actual,
                Utils::relative_epsilon(test.expected, actual));
  }
}
struct PowerTest {
  float expected;
  float x;
  int e;
};
TEST(Utils, it_calculates_power) {
  std::vector<PowerTest> tests = {
      PowerTest{-1, -1, 1},
      PowerTest{1, -1, 2},

      PowerTest{1, 1, 1},
      PowerTest{1, 1, 1},
      PowerTest{1, 1, 2},
      PowerTest{4, 2, 2},
      PowerTest{8, 2, 3},

      PowerTest{4294967296.0f, 2, 32},
      PowerTest{9, 3, 2},
      PowerTest{9.8596f, 3.14f, 2},

      PowerTest{1, 1, -1},
      PowerTest{1, 1, -2},
      PowerTest{0.5f, 2, -1},
      PowerTest{0.25f, 2, -2},
  };

  for (auto test : tests) {
    auto actual = Utils::pow(test.x, test.e);
    EXPECT_NEAR(test.expected, actual,
                Utils::relative_epsilon(test.expected, actual, 1e-4f));
  }
}
