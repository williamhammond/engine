#include "matrix4.h"

Matrix4 Matrix4::Identity() {
  // clang-format off
  return { 1.0f, 0.0f, 0.0f, 0.0f,
           0.0f, 1.0f, 0.0f, 0.0f,
           0.0f, 0.0f, 1.0f, 0.0f,
           0.0f, 0.0f, 0.0f, 1.0f,
  };
  // clang-format on
}
