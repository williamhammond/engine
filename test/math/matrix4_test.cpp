#include "math/matrix4.h"

#include <gtest/gtest.h>

namespace matrix4_test {
TEST(Matrix4, it_indexes) {
  // clang-format off
  Matrix4 matrix4{1, 0, 0, 0,
                  0, 1, 0, 0,
                  0, 0, 1, 0,
                  0, 0, 0, 1 };
  // clang-format on
  EXPECT_EQ(1, matrix4(0, 0));
  EXPECT_EQ(1, matrix4(1, 1));
  EXPECT_EQ(1, matrix4(2, 2));
  EXPECT_EQ(1, matrix4(3, 3));

  EXPECT_EQ(0, matrix4(0, 1));
  EXPECT_EQ(0, matrix4(0, 2));
  EXPECT_EQ(0, matrix4(0, 3));

  EXPECT_EQ(0, matrix4(1, 0));
  EXPECT_EQ(0, matrix4(1, 2));
  EXPECT_EQ(0, matrix4(1, 3));

  EXPECT_EQ(0, matrix4(2, 0));
  EXPECT_EQ(0, matrix4(2, 1));
  EXPECT_EQ(0, matrix4(2, 3));

  EXPECT_EQ(0, matrix4(3, 0));
  EXPECT_EQ(0, matrix4(3, 1));
  EXPECT_EQ(0, matrix4(3, 2));
}

}  // namespace matrix4_test
