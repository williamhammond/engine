#include "math/vector3.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(Vector3, it_indexes) {
  Vector3 vector{0, 1, 2};

  EXPECT_EQ(0, vector[0]);
  EXPECT_EQ(1, vector[1]);
  EXPECT_EQ(2, vector[2]);
}

struct MagnitudeTest {
  Vector3 vector{};
  float expected;
  float tolerance;
  std::string message;
};
TEST(Vector3, it_calculates_magitude) {
  std::vector<MagnitudeTest> tests = {
      MagnitudeTest{Vector3{0, 0, 0}, 0, 0.01f, "it handles 0 vector"},
      MagnitudeTest{Vector3{1, 1, 1}, 1.73, 0.01f, "it handles unit vector"},
      MagnitudeTest{Vector3{-1, -1, -1}, 1.73, 0.01f,
                    "it handles negative unit vector"},
  };
  for (auto test : tests) {
    EXPECT_NEAR(test.expected, test.vector.magnitude(), test.tolerance)
        << test.message;
  }
}
