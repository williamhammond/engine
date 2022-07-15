#include "math/matrix3.h"

#include <gtest/gtest.h>

#include <vector>

TEST(Matrix3, it_indexes) {
  Matrix3 matrix3{1, 0, 0, 0, 1, 0, 0, 0, 1};

  EXPECT_EQ(1, matrix3(0, 0));
  EXPECT_EQ(1, matrix3(1, 1));
  EXPECT_EQ(1, matrix3(2, 2));

  EXPECT_EQ(0, matrix3(1, 0));
  EXPECT_EQ(0, matrix3(0, 1));
  EXPECT_EQ(0, matrix3(0, 2));
  EXPECT_EQ(0, matrix3(2, 0));
  EXPECT_EQ(0, matrix3(2, 1));
  EXPECT_EQ(0, matrix3(1, 2));

  EXPECT_EQ(1, matrix3[0][0]);
  EXPECT_EQ(1, matrix3[1][1]);
  EXPECT_EQ(1, matrix3[2][2]);

  EXPECT_EQ(0, matrix3[1][0]);
  EXPECT_EQ(0, matrix3[0][1]);
  EXPECT_EQ(0, matrix3[0][2]);
  EXPECT_EQ(0, matrix3[2][0]);
  EXPECT_EQ(0, matrix3[2][1]);
  EXPECT_EQ(0, matrix3[1][2]);
}

struct EqualityTest {
  Matrix3 A;
  Matrix3 B;
  Matrix3 C;
  float epsilon;
};
TEST(Matrix3, it_computes_equality) {
  std::vector<EqualityTest> tests = {
      {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 1e-9f},
      {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 1e-9f},
      {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
       {{1.000001f, 0, 0}, {0, 1.000001f, 0}, {0, 0, 1.000001f}},
       {{1.01f, 0, 0}, {0, 1.01f, 0}, {0, 0, 1.01f}},
       1e-2f},
  };

  for (const auto& test : tests) {
    EXPECT_TRUE(test.A.Equals(test.A, test.epsilon));
    EXPECT_TRUE(test.A.Equals(test.B, test.epsilon));
    EXPECT_TRUE(test.A.Equals(test.C, test.epsilon));

    EXPECT_TRUE(test.B.Equals(test.A, test.epsilon));
    EXPECT_TRUE(test.B.Equals(test.B, test.epsilon));
    EXPECT_TRUE(test.B.Equals(test.C, test.epsilon));

    EXPECT_TRUE(test.C.Equals(test.A, test.epsilon));
    EXPECT_TRUE(test.C.Equals(test.B, test.epsilon));
    EXPECT_TRUE(test.C.Equals(test.C, test.epsilon));
  }
}

struct InequalityTest {
  Matrix3 A;
  Matrix3 B;
  float epsilon;
};
TEST(Matrix3, it_computes_inequality) {
  std::vector<InequalityTest> tests = {
      {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{0, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 1e-9f},
      {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{1.01f, 0, 0}, {0, 1.01f, 0}, {0, 0, 1.01f}}, 1e-9f},
  };

  for (const auto& test : tests) {
    EXPECT_FALSE(test.A.Equals(test.B, test.epsilon));
    EXPECT_FALSE(test.B.Equals(test.A, test.epsilon));
  }
}

struct MultiplicationTest {
  Matrix3 A;
  Matrix3 B;
  Matrix3 expected;
  float epsilon = 1e-9f;
};
TEST(Matrix3, it_multiplies) {
  std::vector<MultiplicationTest> tests = {
      {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 1e-9f},
      {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 1e-9f},
      {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, 1e-9f},
      {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1e-9f},
  };

  for (const auto& test : tests) {
    auto actual = test.A * test.B;
    EXPECT_TRUE(actual.Equals(test.expected, test.epsilon)) << test.A << "\n*\n"
                                                            << test.B << "\n!=\n"
                                                            << test.expected << "\n\n"
                                                            << actual;
  }
}

struct DeterminantTest {
  Matrix3 A;
  float expected;
  float epsilon;
};
TEST(Matrix3, it_computes_determinant) {
  std::vector<DeterminantTest> tests = {
      {{0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 1e-9f},
      {{1, 0, 0, 0, 1, 0, 0, 0, 1}, 1, 1e-9f},
      {{1, 1, 1, 1, 1, 1, 1, 1, 1}, 0, 1e-9f},
      {{2, 0, 0, 0, 2, 0, 0, 0, 2}, 8, 1e-9f},
  };

  for (const auto& test : tests) {
    auto actual = test.A.Determinant();
    EXPECT_NEAR(test.expected, actual, test.epsilon);
  }
}

struct InverseTest {
  Matrix3 A;
  float epsilon;
};
TEST(Matrix3, it_computes_inverse) {
  std::vector<InverseTest> tests = {
      {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 1e-9f},
      {{{2, 0, 0}, {0, 2, 0}, {0, 0, 3}}, 1e-9f},
  };

  Matrix3 identity = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  for (const auto& test : tests) {
    auto actual = test.A * test.A.Inverse();
    EXPECT_TRUE(actual.Equals(identity, test.epsilon));
  }
}
