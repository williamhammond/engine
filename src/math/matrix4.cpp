#include "matrix4.h"

engine::Matrix4 engine::Matrix4::Identity() {
  // clang-format off
  return { 1.0f, 0.0f, 0.0f, 0.0f,
           0.0f, 1.0f, 0.0f, 0.0f,
           0.0f, 0.0f, 1.0f, 0.0f,
           0.0f, 0.0f, 0.0f, 1.0f,
  };
  // clang-format on
}
