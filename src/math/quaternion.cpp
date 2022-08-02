#include "quaternion.h"

Matrix3 Quaternion::GetRotation() {
  float x_squared = x * x;
  float y_squared = y * y;
  float z_squared = z * z;

  float xy = x * y;
  float xz = x * z;

  float yz = y * z;

  float wx = w * x;
  float wy = w * y;
  float wz = w * z;

  // clang-format off
  return {
    1.0f - 2.0f * (y_squared + z_squared), 2.0f * (xy-wz)                       , 2.0f * (xz + wy),
    2.0f * (xy + wz)                     , 1.0f - 2.0f * (x_squared + z_squared), 2.0f * (yz - wx),
    2.0f * (xz - wy)                     , 2.0f * (yz + wx)                     , 1.0f - 2.0f * (x_squared + y_squared)
  };
  // clang-format on
}
