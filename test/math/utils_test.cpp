#include <gtest/gtest.h>

#include <vector>

#include "math/fmath.h"

namespace utils_test {

struct AbsTest {
  float expected;
  float x;
};
TEST(FMath, it_calculates_abs) {
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
    EXPECT_EQ(test.expected, engine::FMath::abs(test.x));
  }
}

struct SquareTest {
  float expected;
  float x;
};
TEST(FMath, it_calculates_square) {
  std::vector<SquareTest> tests = {
      SquareTest{9, -3}, SquareTest{4, -2}, SquareTest{1, -1}, SquareTest{0, 0},
      SquareTest{1, 1},  SquareTest{4, 2},  SquareTest{9, 3},
  };

  for (auto test : tests) {
    auto actual = engine::FMath::square(test.x);
    EXPECT_NEAR(test.expected, actual, engine::FMath::relative_epsilon(test.expected, actual));
  }
}

struct SqrtTest {
  float expected;
  float x;
};
TEST(FMath, it_calculates_sqrt) {
  std::vector<SqrtTest> tests = {
      SqrtTest{0, 0},
      SqrtTest{1, 1},
  };

  for (auto test : tests) {
    auto actual = engine::FMath::sqrt(test.x);
    EXPECT_NEAR(test.expected, actual, engine::FMath::relative_epsilon(test.expected, actual));
  }
}
struct PowerTest {
  float expected;
  float x;
  int e;
};
TEST(FMath, it_calculates_power) {
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
    auto actual = engine::FMath::pow(test.x, test.e);
    EXPECT_NEAR(test.expected, actual, engine::FMath::relative_epsilon(test.expected, actual, 1e-4f));
  }
}

struct Degree2RadTest {
  float degrees;
  float rads;
  float epsilon;
};

TEST(FMath, it_calculates_degree_2_rad) {
  std::vector<Degree2RadTest> tests = {
      {57.2958f, 1, 1e-3f},     {90, 1.570796f, 1e-3f},   {180, 3.14169f, 1e-3f},   {360, 6.28319f, 1e-3f},
      {-90, -1.570796f, 1e-3f}, {-180, -3.14169f, 1e-3f}, {-360, -6.28319f, 1e-3f},
  };

  for (auto test : tests) {
    auto actual = engine::FMath::Degree2Radian(test.degrees);
    EXPECT_NEAR(test.rads, actual, test.epsilon);
  }
}
}  // namespace utils_test
