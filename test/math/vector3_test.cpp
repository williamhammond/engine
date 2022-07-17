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

struct AdditionTest {
  Vector3 a{};
  Vector3 b{};
  Vector3 expected{};
  std::string message;
};
TEST(Vector3, it_calculates_addition) {
  std::vector<AdditionTest> tests = {
      AdditionTest{Vector3{0, 0, 0}, Vector3{0, 0, 0}, Vector3{0, 0, 0}, ""},
      AdditionTest{Vector3{0, 0, 0}, Vector3{1, 1, 1}, Vector3{1, 1, 1}, ""},
      AdditionTest{Vector3{0, 0, 0}, Vector3{-1, -1, -1}, Vector3{-1, -1, -1},
                   ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a + test.b;
    EXPECT_NEAR(test.expected.x, actual.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, 0.001f) << test.message;
  }
}
TEST(Vector3, it_calculates_addition_with_assignment) {
  std::vector<AdditionTest> tests = {
      AdditionTest{Vector3{0, 0, 0}, Vector3{0, 0, 0}, Vector3{0, 0, 0}, ""},
      AdditionTest{Vector3{0, 0, 0}, Vector3{1, 1, 1}, Vector3{1, 1, 1}, ""},
      AdditionTest{Vector3{0, 0, 0}, Vector3{-1, -1, -1}, Vector3{-1, -1, -1},
                   ""},
  };
  for (auto test : tests) {
    test.a += test.b;
    EXPECT_NEAR(test.expected.x, test.a.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, test.a.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, test.a.z, 0.001f) << test.message;
  }
}

struct SubtractionTest {
  Vector3 a{};
  Vector3 b{};
  Vector3 expected{};
  std::string message;
};
TEST(Vector3, it_calculates_subtraction) {
  std::vector<SubtractionTest> tests = {
      SubtractionTest{Vector3{0, 0, 0}, Vector3{0, 0, 0}, Vector3{0, 0, 0}, ""},
      SubtractionTest{Vector3{0, 0, 0}, Vector3{1, 1, 1}, Vector3{-1, -1, -1},
                      ""},
      SubtractionTest{Vector3{0, 0, 0}, Vector3{-1, -1, -1}, Vector3{1, 1, 1},
                      ""},
  };
  for (auto test : tests) {
    test.a -= test.b;
    EXPECT_NEAR(test.expected.x, test.a.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, test.a.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, test.a.z, 0.001f) << test.message;
  }
}
TEST(Vector3, it_calculates_subtraction_with_assignment) {
  std::vector<SubtractionTest> tests = {
      SubtractionTest{Vector3{0, 0, 0}, Vector3{0, 0, 0}, Vector3{0, 0, 0}, ""},
      SubtractionTest{Vector3{0, 0, 0}, Vector3{1, 1, 1}, Vector3{-1, -1, -1},
                      ""},
      SubtractionTest{Vector3{0, 0, 0}, Vector3{-1, -1, -1}, Vector3{1, 1, 1},
                      ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a - test.b;
    EXPECT_NEAR(test.expected.x, actual.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, 0.001f) << test.message;
  }
}

struct MultiplicationTest {
  Vector3 input{};
  Vector3 expected{};
  float scalar;
  std::string message;
};
TEST(Vector3, it_calculates_multiplication) {
  std::vector<MultiplicationTest> tests = {
      MultiplicationTest{Vector3{0, 0, 0}, Vector3{0, 0, 0}, 1, ""},
      MultiplicationTest{Vector3{1, 1, 1}, Vector3{2, 2, 2}, 2, ""},
      MultiplicationTest{Vector3{1, 1, 1}, Vector3{-1, -1, -1}, -1, ""},
      MultiplicationTest{Vector3{1, 1, 1}, Vector3{-1, -1, -1}, -1.00001f, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.input * test.scalar;
    EXPECT_NEAR(test.expected.x, actual.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, 0.001f) << test.message;
  }
}
TEST(Vector3, it_calculates_multiplication_with_assignment) {
  std::vector<MultiplicationTest> tests = {
      MultiplicationTest{Vector3{0, 0, 0}, Vector3{0, 0, 0}, 1, ""},
      MultiplicationTest{Vector3{1, 1, 1}, Vector3{2, 2, 2}, 2, ""},
      MultiplicationTest{Vector3{1, 1, 1}, Vector3{-1, -1, -1}, -1, ""},
      MultiplicationTest{Vector3{1, 1, 1}, Vector3{-1, -1, -1}, -1.00001f, ""},
  };
  for (auto test : tests) {
    test.input *= test.scalar;
    EXPECT_NEAR(test.input.x, test.expected.x, 0.001f) << test.message;
    EXPECT_NEAR(test.input.y, test.expected.y, 0.001f) << test.message;
    EXPECT_NEAR(test.input.z, test.expected.z, 0.001f) << test.message;
  }
}

struct DivisionTest {
  Vector3 input{};
  Vector3 expected{};
  float scalar;
  std::string message;
};
TEST(Vector3, it_calculates_division) {
  std::vector<DivisionTest> tests = {
      DivisionTest{Vector3{0, 0, 0}, Vector3{0, 0, 0}, 1, ""},
      DivisionTest{Vector3{2, 2, 2}, Vector3{1, 1, 1}, 2, ""},
      DivisionTest{Vector3{1, 1, 1}, Vector3{-1, -1, -1}, -1, ""},
      DivisionTest{Vector3{1, 1, 1}, Vector3{-1, -1, -1}, -1.00001f, ""},
  };
  for (const auto& test : tests) {
    Vector3 actual = test.input / test.scalar;
    EXPECT_NEAR(test.expected.x, actual.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, 0.001f) << test.message;
  }
}
TEST(Vector3, it_calculates_division_with_assignment) {
  std::vector<DivisionTest> tests = {
      DivisionTest{Vector3{0, 0, 0}, Vector3{0, 0, 0}, 1, ""},
      DivisionTest{Vector3{2, 2, 2}, Vector3{1, 1, 1}, 2, ""},
      DivisionTest{Vector3{1, 1, 1}, Vector3{-1, -1, -1}, -1, ""},
      DivisionTest{Vector3{1, 1, 1}, Vector3{-1, -1, -1}, -1.00001f, ""},
  };
  for (auto test : tests) {
    test.input /= test.scalar;
    EXPECT_NEAR(test.input.x, test.expected.x, 0.001f) << test.message;
    EXPECT_NEAR(test.input.y, test.expected.y, 0.001f) << test.message;
    EXPECT_NEAR(test.input.z, test.expected.z, 0.001f) << test.message;
  }
}

TEST(Vector3, it_handles_negation) {
  std::vector<Vector3> vectors = {
      Vector3{0, 0, 0},
      Vector3{1, 1, 1},
      Vector3{-1, -1, -1},
  };
  for (auto expected : vectors) {
    Vector3 actual = -expected;
    EXPECT_NEAR(-expected.x, actual.x, 0.001f);
    EXPECT_NEAR(-expected.y, actual.y, 0.001f);
    EXPECT_NEAR(-expected.z, actual.z, 0.001f);
  }
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
      MagnitudeTest{Vector3{1, 1, 1}, 1.73f, 0.01f, "it handles unit vector"},
      MagnitudeTest{Vector3{-1, -1, -1}, 1.73f, 0.01f,
                    "it handles negative unit vector"},
  };
  for (const auto& test : tests) {
    EXPECT_NEAR(test.expected, test.vector.Magnitude(), test.tolerance)
        << test.message;
  }
}

TEST(Vector3, it_handles_normalization) {
  std::vector<Vector3> vectors = {
      Vector3{1, 1, 1},
      Vector3{5, 5, 5},
      Vector3{-1, -1, -1},
      Vector3{-5, -5, -5},
  };
  for (auto vector : vectors) {
    Vector3 expected = vector.Normalize();
    EXPECT_NEAR(1.0f, expected.Magnitude(), 0.001f);
  }
  Vector3 vector = Vector3{0, 0, 0};
  Vector3 expected = vector.Normalize();
  EXPECT_NEAR(0.0f, expected.Magnitude(), 0.001f);
}

struct DotTest {
  Vector3 a;
  Vector3 b;
  float expected;
  std::string message;
};
TEST(Vector3, it_handles_dot_product) {
  std::vector<DotTest> tests = {
      {{1, 1, 1}, {1, 1, 1}, 3, ""},     {{0, 0, 0}, {1, 1, 1}, 0, ""},
      {{1, 1, 1}, {-1, -1, -1}, -3, ""}, {{1, 1, 1}, {1, -1, 1}, 1, ""},
      {{1, 1, 1}, {-1, 1, 1}, 1, ""},    {{1, 1, 1}, {1, 1, -1}, 1, ""},
      {{1, 1, 1}, {-1, -1, 1}, -1, ""},  {{1, 1, 1}, {-1, 1, -1}, -1, ""},
      {{1, 1, 1}, {1, -1, -1}, -1, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a.Dot(test.b);
    EXPECT_NEAR(test.expected, actual, 0.001f) << test.message;
  }
}

struct CrossTest {
  Vector3 a;
  Vector3 b;
  Vector3 expected;
  std::string message;
};
TEST(Vector3, it_handles_cross_product) {
  std::vector<CrossTest> tests = {
      {{1, 1, 1}, {1, 1, 1}, {0, 0, 0}, ""},
      {{-1, -1, -1}, {1, 1, 1}, {0, 0, 0}, ""},
      {{1, 1, 1}, {-1, -1, -1}, {0, 0, 0}, ""},

      {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, ""},
      {{0, 1, 0}, {1, 0, 0}, {0, 0, -1}, ""},

      {{0, 0, 1}, {0, 1, 0}, {-1, 0, 0}, ""},
      {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}, ""},

      {{1, 0, 0}, {0, 0, 1}, {0, -1, 0}, ""},
      {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a.Cross(test.b);
    EXPECT_NEAR(test.expected.x, actual.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, 0.001f) << test.message;
  }

  // Anti-communative
  for (const auto& test : tests) {
    auto lhs = test.a.Cross(test.b);
    auto rhs = -(test.b.Cross(test.a));

    EXPECT_NEAR(test.expected.x, lhs.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, lhs.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, lhs.z, 0.001f) << test.message;

    EXPECT_NEAR(test.expected.x, rhs.x, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.y, rhs.y, 0.001f) << test.message;
    EXPECT_NEAR(test.expected.z, rhs.z, 0.001f) << test.message;
  }
}
