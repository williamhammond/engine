#include "math/vector3.h"

#include <gtest/gtest.h>

#include <cmath>
#include <string>
#include <vector>

namespace vector3_test {

TEST(Vector3, it_indexes) {
  engine::Vector3 vector{0, 1, 2};

  EXPECT_EQ(0, vector[0]);
  EXPECT_EQ(1, vector[1]);
  EXPECT_EQ(2, vector[2]);
}

struct AdditionTest {
  engine::Vector3 a{};
  engine::Vector3 b{};
  engine::Vector3 expected{};
  std::string message;
};
TEST(Vector3, it_calculates_addition) {
  std::vector<AdditionTest> tests = {
      AdditionTest{engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, ""},
      AdditionTest{engine::Vector3{0, 0, 0}, engine::Vector3{1, 1, 1}, engine::Vector3{1, 1, 1}, ""},
      AdditionTest{engine::Vector3{0, 0, 0}, engine::Vector3{-1, -1, -1}, engine::Vector3{-1, -1, -1}, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a + test.b;
    EXPECT_NEAR(test.expected.x, actual.x, engine::FMath::relative_epsilon(test.expected.x, actual.x)) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, engine::FMath::relative_epsilon(test.expected.y, actual.y)) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, engine::FMath::relative_epsilon(test.expected.z, actual.z)) << test.message;
  }
}
TEST(Vector3, it_calculates_addition_with_assignment) {
  std::vector<AdditionTest> tests = {
      AdditionTest{engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, ""},
      AdditionTest{engine::Vector3{0, 0, 0}, engine::Vector3{1, 1, 1}, engine::Vector3{1, 1, 1}, ""},
      AdditionTest{engine::Vector3{0, 0, 0}, engine::Vector3{-1, -1, -1}, engine::Vector3{-1, -1, -1}, ""},
  };
  for (auto test : tests) {
    test.a += test.b;
    EXPECT_NEAR(test.expected.x, test.a.x, engine::FMath::relative_epsilon(test.expected.x, test.a.x)) << test.message;
    EXPECT_NEAR(test.expected.y, test.a.y, engine::FMath::relative_epsilon(test.expected.y, test.a.y)) << test.message;
    EXPECT_NEAR(test.expected.z, test.a.z, engine::FMath::relative_epsilon(test.expected.z, test.a.z)) << test.message;
  }
}

struct SubtractionTest {
  engine::Vector3 a{};
  engine::Vector3 b{};
  engine::Vector3 expected{};
  std::string message;
};
TEST(Vector3, it_calculates_subtraction) {
  std::vector<SubtractionTest> tests = {
      SubtractionTest{engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, ""},
      SubtractionTest{engine::Vector3{0, 0, 0}, engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, ""},
      SubtractionTest{engine::Vector3{0, 0, 0}, engine::Vector3{-1, -1, -1}, engine::Vector3{1, 1, 1}, ""},
  };
  for (auto test : tests) {
    test.a -= test.b;
    EXPECT_NEAR(test.expected.x, test.a.x, engine::FMath::relative_epsilon(test.expected.x, test.a.x)) << test.message;
    EXPECT_NEAR(test.expected.y, test.a.y, engine::FMath::relative_epsilon(test.expected.y, test.a.y)) << test.message;
    EXPECT_NEAR(test.expected.z, test.a.z, engine::FMath::relative_epsilon(test.expected.z, test.a.z)) << test.message;
  }
}
TEST(Vector3, it_calculates_subtraction_with_assignment) {
  std::vector<SubtractionTest> tests = {
      SubtractionTest{engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, ""},
      SubtractionTest{engine::Vector3{0, 0, 0}, engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, ""},
      SubtractionTest{engine::Vector3{0, 0, 0}, engine::Vector3{-1, -1, -1}, engine::Vector3{1, 1, 1}, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a - test.b;
    EXPECT_NEAR(test.expected.x, actual.x, engine::FMath::relative_epsilon(test.expected.x, actual.x, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, engine::FMath::relative_epsilon(test.expected.y, actual.y, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, engine::FMath::relative_epsilon(test.expected.z, actual.z, 1e-4f))
        << test.message;
  }
}

struct MultiplicationTest {
  engine::Vector3 input{};
  engine::Vector3 expected{};
  float scalar;
  std::string message;
};

TEST(Vector3, it_calculates_multiplication) {
  std::vector<MultiplicationTest> tests = {
      MultiplicationTest{engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, 1, ""},
      MultiplicationTest{engine::Vector3{1, 1, 1}, engine::Vector3{2, 2, 2}, 2, ""},
      MultiplicationTest{engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, -1, ""},
      MultiplicationTest{engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, -1.00001f, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.input * test.scalar;
    EXPECT_NEAR(test.expected.x, actual.x, engine::FMath::relative_epsilon(test.expected.x, actual.x, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, engine::FMath::relative_epsilon(test.expected.y, actual.y, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, engine::FMath::relative_epsilon(test.expected.z, actual.z, 1e-4f))
        << test.message;
  }
}

TEST(Vector3, it_calculates_multiplication_with_assignment) {
  std::vector<MultiplicationTest> tests = {
      MultiplicationTest{engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, 1, ""},
      MultiplicationTest{engine::Vector3{1, 1, 1}, engine::Vector3{2, 2, 2}, 2, ""},
      MultiplicationTest{engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, -1, ""},
      MultiplicationTest{engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, -1.00001f, ""},
  };
  for (auto test : tests) {
    test.input *= test.scalar;
    EXPECT_NEAR(test.input.x, test.expected.x, engine::FMath::relative_epsilon(test.input.x, test.expected.x, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.input.y, test.expected.y, engine::FMath::relative_epsilon(test.input.y, test.expected.y, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.input.z, test.expected.z, engine::FMath::relative_epsilon(test.input.z, test.expected.z, 1e-4f))
        << test.message;
  }
}

struct DivisionTest {
  engine::Vector3 input{};
  engine::Vector3 expected{};
  float scalar;
  std::string message;
};
TEST(Vector3, it_calculates_division) {
  std::vector<DivisionTest> tests = {
      DivisionTest{engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, 1, ""},
      DivisionTest{engine::Vector3{2, 2, 2}, engine::Vector3{1, 1, 1}, 2, ""},
      DivisionTest{engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, -1, ""},
      DivisionTest{engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, -1.00001f, ""},
  };
  for (const auto& test : tests) {
    engine::Vector3 actual = test.input / test.scalar;
    EXPECT_NEAR(test.expected.x, actual.x, engine::FMath::relative_epsilon(test.input.x, test.expected.x, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, engine::FMath::relative_epsilon(test.input.y, test.expected.y, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, engine::FMath::relative_epsilon(test.input.z, test.expected.z, 1e-4f))
        << test.message;
  }
}
TEST(Vector3, it_calculates_division_with_assignment) {
  std::vector<DivisionTest> tests = {
      DivisionTest{engine::Vector3{0, 0, 0}, engine::Vector3{0, 0, 0}, 1, ""},
      DivisionTest{engine::Vector3{2, 2, 2}, engine::Vector3{1, 1, 1}, 2, ""},
      DivisionTest{engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, -1, ""},
      DivisionTest{engine::Vector3{1, 1, 1}, engine::Vector3{-1, -1, -1}, -1.00001f, ""},
  };
  for (auto test : tests) {
    test.input /= test.scalar;
    EXPECT_NEAR(test.input.x, test.expected.x, engine::FMath::relative_epsilon(test.input.x, test.expected.x, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.input.y, test.expected.y, engine::FMath::relative_epsilon(test.input.y, test.expected.y, 1e-4f))
        << test.message;
    EXPECT_NEAR(test.input.z, test.expected.z, engine::FMath::relative_epsilon(test.input.z, test.expected.z, 1e-4f))
        << test.message;
  }
}

TEST(Vector3, it_handles_negation) {
  std::vector<engine::Vector3> vectors = {
      engine::Vector3{0, 0, 0},
      engine::Vector3{1, 1, 1},
      engine::Vector3{-1, -1, -1},
  };
  for (auto expected : vectors) {
    engine::Vector3 actual = -expected;
    EXPECT_NEAR(-expected.x, actual.x, engine::FMath::relative_epsilon(-expected.x, actual.x));
    EXPECT_NEAR(-expected.y, actual.y, engine::FMath::relative_epsilon(-expected.y, actual.y));
    EXPECT_NEAR(-expected.z, actual.z, engine::FMath::relative_epsilon(-expected.z, actual.z));
  }
}

struct EqualityTest {
  engine::Vector3 a;
  engine::Vector3 b;
  engine::Vector3 c;
  float epsilon;
};
TEST(Vector3, it_computes_equality) {
  std::vector<EqualityTest> tests = {
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 1e-9f},
      {{0, 0, 0}, {-0, -0, -0}, {0, 0, 0}, 1e-9f},

      {{1, 1, 1}, {1.000000001f, 1.000000001f, 1.00000001f}, {1.001f, 1.001f, 1.001f}, 0.01f},

      {{-1, -1, -1}, {-1.000000001f, -1.000000001f, -1.00000001f}, {-1, -1, -1}, 1e-9f},
  };
  for (auto test : tests) {
    EXPECT_TRUE(test.a.Equals(test.a, test.epsilon));
    EXPECT_TRUE(test.a.Equals(test.b, test.epsilon));
    EXPECT_TRUE(test.a.Equals(test.c, test.epsilon));

    EXPECT_TRUE(test.b.Equals(test.a, test.epsilon));
    EXPECT_TRUE(test.b.Equals(test.b, test.epsilon));
    EXPECT_TRUE(test.b.Equals(test.c, test.epsilon));

    EXPECT_TRUE(test.c.Equals(test.a, test.epsilon));
    EXPECT_TRUE(test.c.Equals(test.b, test.epsilon));
    EXPECT_TRUE(test.c.Equals(test.c, test.epsilon));
  }
}

struct InequalityTest {
  engine::Vector3 a;
  engine::Vector3 b;
  float epsilon;
};
TEST(Vector3, it_computes_inequality) {
  std::vector<InequalityTest> tests = {
      {{1, 1, 1}, {2, 2, 2}, 1e-9f},
      {{1, 1, 1}, {1.1f, 1.1f, 1.1f}, 1e-9f},
      {{0.00001f, 0.00001f, 0.00001f}, {0, 0, 0}, 1e-9f},
  };

  for (const auto& test : tests) {
    EXPECT_FALSE(test.a.Equals(test.b, test.epsilon));
    EXPECT_FALSE(test.b.Equals(test.a, test.epsilon));
  }
}

struct MagnitudeTest {
  engine::Vector3 vector{};
  float expected;
  std::string message;
};
TEST(Vector3, it_calculates_magitude) {
  std::vector<MagnitudeTest> tests = {
      MagnitudeTest{engine::Vector3{0, 0, 0}, 0, "it handles 0 vector"},
      MagnitudeTest{engine::Vector3{1, 1, 1}, 1.73205080757f, "it handles unit vector"},
      MagnitudeTest{engine::Vector3{-1, -1, -1}, 1.73205080757f, "it handles negative unit vector"},
  };
  for (const auto& test : tests) {
    EXPECT_NEAR(test.expected, test.vector.Magnitude(),
                engine::FMath::relative_epsilon(test.expected, test.vector.Magnitude(), 1e-5f))
        << test.message;
  }
}

TEST(Vector3, it_handles_normalization) {
  std::vector<engine::Vector3> vectors = {
      engine::Vector3{1, 1, 1},
      engine::Vector3{5, 5, 5},
      engine::Vector3{-1, -1, -1},
      engine::Vector3{-5, -5, -5},
  };
  for (auto vector : vectors) {
    engine::Vector3 expected = vector.Normalize();
    EXPECT_NEAR(1.0f, expected.Magnitude(), std::numeric_limits<float>::epsilon());
  }
  engine::Vector3 vector = engine::Vector3{0, 0, 0};
  engine::Vector3 expected = vector.Normalize();
  EXPECT_NEAR(0.0f, expected.Magnitude(), std::numeric_limits<float>::epsilon());
}

struct DotTest {
  engine::Vector3 a;
  engine::Vector3 b;
  float expected;
  std::string message;
};
TEST(Vector3, it_handles_dot_product) {
  std::vector<DotTest> tests = {
      {{1, 1, 1}, {1, 1, 1}, 3, ""},    {{0, 0, 0}, {1, 1, 1}, 0, ""},    {{1, 1, 1}, {-1, -1, -1}, -3, ""},
      {{1, 1, 1}, {1, -1, 1}, 1, ""},   {{1, 1, 1}, {-1, 1, 1}, 1, ""},   {{1, 1, 1}, {1, 1, -1}, 1, ""},
      {{1, 1, 1}, {-1, -1, 1}, -1, ""}, {{1, 1, 1}, {-1, 1, -1}, -1, ""}, {{1, 1, 1}, {1, -1, -1}, -1, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a.Dot(test.b);
    EXPECT_NEAR(test.expected, actual, engine::FMath::relative_epsilon(test.expected, actual)) << test.message;
  }
}

struct CrossTest {
  engine::Vector3 a;
  engine::Vector3 b;
  engine::Vector3 expected;
  std::string message;
};
TEST(Vector3, it_handles_cross_product) {
  std::vector<CrossTest> tests = {
      {{1, 1, 1}, {1, 1, 1}, {0, 0, 0}, ""},    {{-1, -1, -1}, {1, 1, 1}, {0, 0, 0}, ""},
      {{1, 1, 1}, {-1, -1, -1}, {0, 0, 0}, ""}, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, ""},
      {{0, 1, 0}, {1, 0, 0}, {0, 0, -1}, ""},   {{0, 0, 1}, {0, 1, 0}, {-1, 0, 0}, ""},
      {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}, ""},    {{1, 0, 0}, {0, 0, 1}, {0, -1, 0}, ""},
      {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a.Cross(test.b);
    EXPECT_NEAR(test.expected.x, actual.x, engine::FMath::relative_epsilon(test.expected.x, actual.x)) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, engine::FMath::relative_epsilon(test.expected.y, actual.y)) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, engine::FMath::relative_epsilon(test.expected.y, actual.y)) << test.message;
  }

  // Anti-communative
  for (const auto& test : tests) {
    auto lhs = test.a.Cross(test.b);
    auto rhs = -(test.b.Cross(test.a));

    EXPECT_NEAR(test.expected.x, lhs.x, engine::FMath::relative_epsilon(test.expected.x, lhs.x)) << test.message;
    EXPECT_NEAR(test.expected.y, lhs.y, engine::FMath::relative_epsilon(test.expected.y, lhs.y)) << test.message;
    EXPECT_NEAR(test.expected.z, lhs.z, engine::FMath::relative_epsilon(test.expected.z, lhs.z)) << test.message;

    EXPECT_NEAR(test.expected.x, rhs.x, engine::FMath::relative_epsilon(test.expected.x, rhs.x)) << test.message;
    EXPECT_NEAR(test.expected.y, rhs.y, engine::FMath::relative_epsilon(test.expected.y, rhs.y)) << test.message;
    EXPECT_NEAR(test.expected.z, rhs.z, engine::FMath::relative_epsilon(test.expected.z, rhs.z)) << test.message;
  }
}

struct VectorTripleTest {
  engine::Vector3 a;
  engine::Vector3 b;
  engine::Vector3 c;
  float epsilon;
};
TEST(Vector3, it_enforces_vector_triple) {
  std::vector<VectorTripleTest> tests = {
      {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, 1e-9f}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 1e-9f},
      {{1, 1, 1}, {0, 0, 0}, {0, 0, 0}, 1e-9f}, {{0, 0, 0}, {1, 1, 1}, {0, 0, 0}, 1e-9f},
      {{0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 1e-9f}, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, 1e-9f},
  };

  for (auto test : tests) {
    auto lhs = test.a.Cross(test.b.Cross(test.c));
    auto rhs = test.b * (test.a.Dot(test.c)) - test.c * (test.a.Dot(test.b));
    EXPECT_TRUE(lhs.Equals(rhs, test.epsilon));
  }
}

struct LarangeIdentityTest {
  engine::Vector3 a;
  engine::Vector3 b;
  float epsilon;
};

TEST(Vector3, it_enforces_larange_identity) {
  std::vector<LarangeIdentityTest> tests = {
      {{1, 0, 0}, {0, 1, 0}, 1e-5f},
      {{1, 0, 0}, {0, 0, 1}, 1e-5f},
      {{1, 1, 1}, {1, 1, 1}, 1e-5f},
      {{0, 0, 0}, {0, 0, 0}, 1e-5f},
      {{10, 23, 18}, {-1, 30, 5.123123f}, 0.1f},

  };
  for (auto test : tests) {
    auto lhs = engine::FMath::square(test.a.Cross(test.b).Magnitude());
    auto rhs = engine::FMath::square(test.a.Magnitude()) * engine::FMath::square(test.b.Magnitude()) -
               engine::FMath::square(test.a.Dot(test.b));
    EXPECT_NEAR(lhs, rhs, test.epsilon);
  }
}

struct ScalarFactorizationTest {
  engine::Vector3 a;
  engine::Vector3 b;
  float t;
  float epsilon;
};

TEST(Vector3, it_handles_scalar_factorization) {
  std::vector<ScalarFactorizationTest> tests = {
      {{1, 1, 1}, {1, 1, 1}, 10, 1e-9f},     {{0, 0, 0}, {1, 1, 1}, 10, 1e-9f}, {{1, 1, 1}, {0, 0, 0}, 10, 1e-9f},
      {{-1, -1, -1}, {1, 1, 1}, 10, 1e-9f},  {{1, 0, 0}, {0, 1, 0}, 10, 1e-9f}, {{1, 0, 0}, {0, 0, 1}, 10, 1e-9f},
      {{24, -9, 7}, {2, 4, 8}, 0.5f, 1e-9f},
  };
  for (auto test : tests) {
    auto left_term = (test.a * test.t).Cross(test.b);
    auto middle_term = (test.a * test.t).Cross(test.b);
    auto right_term = (test.a * test.t).Cross(test.b);
    EXPECT_TRUE(left_term.Equals(middle_term, test.epsilon));
    EXPECT_TRUE(middle_term.Equals(right_term, test.epsilon));
    EXPECT_TRUE(left_term.Equals(right_term, test.epsilon));
  }
}

struct CrossProductDistributiveTest {
  engine::Vector3 a;
  engine::Vector3 b;
  engine::Vector3 c;
  float epislon;
};
TEST(Vector3, it_handles_cross_product_distributive) {
  std::vector<CrossProductDistributiveTest> tests = {
      {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, 1e-9f}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 1e-9f},
      {{1, 1, 1}, {0, 0, 0}, {0, 0, 0}, 1e-9f}, {{0, 0, 0}, {1, 1, 1}, {0, 0, 0}, 1e-9f},
      {{0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 1e-9f}, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, 1e-9f},
  };
  for (auto test : tests) {
    auto lhs = test.a.Cross(test.b + test.c);
    auto rhs = test.a.Cross(test.b) + test.a.Cross(test.c);
    EXPECT_TRUE(lhs.Equals(rhs, test.epislon));
  }
}

struct ProjectTest {
  engine::Vector3 a;
  engine::Vector3 b;
  engine::Vector3 expected;
  std::string message;
};
TEST(Vector3, it_handles_projection) {
  std::vector<ProjectTest> tests = {
      {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, ""},       {{-1, -1, -1}, {1, 1, 1}, {-1, -1, -1}, ""},
      {{1, 1, 1}, {-1, -1, -1}, {1, 1, 1}, ""},    {{0, 0, 0}, {1, 1, 1}, {0, 0, 0}, ""},
      {{1, 0, 0}, {0, 1, 0}, {0, 0, 0}, ""},       {{0, 1, 0}, {1, 0, 0}, {0, 0, 0}, ""},
      {{0, 0, 1}, {0, 1, 0}, {0, 0, 0}, ""},       {{0, 1, 0}, {0, 0, 1}, {0, 0, 0}, ""},
      {{1, 0, 0}, {0, 0, 1}, {0, 0, 0}, ""},       {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}, ""},
      {{1, 1, 0}, {0, 1, 1}, {0, 0.5f, 0.5f}, ""}, {{0, 1, 1}, {1, 1, 0}, {0.5f, 0.5f, 0}, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a.Project(test.b);
    EXPECT_NEAR(test.expected.x, actual.x, engine::FMath::relative_epsilon(test.expected.x, actual.x)) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, engine::FMath::relative_epsilon(test.expected.y, actual.y)) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, engine::FMath::relative_epsilon(test.expected.y, actual.y)) << test.message;
  }

  auto a = engine::Vector3{1, 1, 1};
  auto b = engine::Vector3{0, 0, 0};
  auto expected = a.Project(b);
  EXPECT_TRUE(std::isnan(expected.x) && std::isnan(expected.y) && std::isnan(expected.z));
}

struct RejectTest {
  engine::Vector3 a;
  engine::Vector3 b;
  engine::Vector3 expected;
  std::string message;
};
TEST(Vector3, it_handles_rejection) {
  std::vector<RejectTest> tests = {
      {{0, 0, 0}, {1, 1, 1}, {0, 0, 0}, ""},

      {{1, 1, 1}, {1, 1, 1}, {0, 0, 0}, ""},        {{-1, -1, -1}, {1, 1, 1}, {0, 0, 0}, ""},
      {{1, 1, 1}, {-1, -1, -1}, {0, 0, 0}, ""},

      {{1, 0, 0}, {0, 1, 0}, {1, 0, 0}, ""},        {{0, 1, 0}, {1, 0, 0}, {0, 1, 0}, ""},
      {{0, 0, 1}, {0, 1, 0}, {0, 0, 1}, ""},        {{0, 1, 0}, {0, 0, 1}, {0, 1, 0}, ""},
      {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}, ""},        {{0, 0, 1}, {1, 0, 0}, {0, 0, 1}, ""},

      {{1, 1, 0}, {0, 1, 1}, {1, 0.5f, -0.5f}, ""}, {{0, 1, 1}, {1, 1, 0}, {-0.5f, 0.5f, 1}, ""},
  };
  for (const auto& test : tests) {
    auto actual = test.a.Reject(test.b);
    EXPECT_NEAR(test.expected.x, actual.x, engine::FMath::relative_epsilon(test.expected.x, actual.x)) << test.message;
    EXPECT_NEAR(test.expected.y, actual.y, engine::FMath::relative_epsilon(test.expected.y, actual.y)) << test.message;
    EXPECT_NEAR(test.expected.z, actual.z, engine::FMath::relative_epsilon(test.expected.y, actual.y)) << test.message;
  }
}
}  // namespace vector3_test
