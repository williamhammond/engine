#include <gtest/gtest.h>

#include "graphics/color_rgba.h"

namespace color_rgba_tests {

struct EqualityTest {
  engine::ColorRGBA A;
  engine::ColorRGBA B;
  engine::ColorRGBA expected;
  float epsilon;
};
TEST(ColorRGBA, it_adds) {
  std::vector<EqualityTest> tests = {
      {{1, 1, 1, 1}, {1, 1, 1, 1}, {2, 2, 2, 2}, 1e-9f},
      {{1, 1, 1, 1}, {-1, -1, -1, -1}, {0, 0, 0, 0}, 1e-9f},
  };
  for (const auto& test : tests) {
    auto message = test.A.ToString() + " + " + test.B.ToString() + "!= " + test.expected.ToString();
    auto actual = test.A + test.B;
    EXPECT_TRUE(actual.Equals(test.expected, test.epsilon)) << message;
  }
}

TEST(ColorRGBA, it_subtracts) {
  std::vector<EqualityTest> tests = {
      {{1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}, 1e-9f},
      {{1, 1, 1, 1}, {-1, -1, -1, -1}, {2, 2, 2, 2}, 1e-9f},
  };
  for (const auto& test : tests) {
    auto message = test.A.ToString() + " - " + test.B.ToString() + "!= " + test.expected.ToString();
    auto actual = test.A - test.B;
    EXPECT_TRUE(actual.Equals(test.expected, test.epsilon)) << message;
  }
}
}  // namespace color_rgba_tests