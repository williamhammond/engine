#include "quaternion.h"

#include "utils.h"

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
void Quaternion::SetRotation(const Matrix3& m) {
  float sum = m(0, 0) + m(1, 1) + m(2, 2);

  // TODO proper epsilon check
  if (sum > 0.0f) {
    w = Utils::sqrt(sum + 1.0f) * 0.5f;
    float f = 0.25f / w;
    x = (m(2, 1) - m(1, 2)) * f;
    y = (m(0, 2) - m(2, 0)) * f;
    z = (m(1, 0) - m(0, 1)) * f;
  } else if (m(0, 0) > m(1, 1) && m(0, 0) > m(2, 2)) {
    x = Utils::sqrt(m(0, 0) - m(1, 1) - m(2, 2) + 1.0f) * 0.5f;
    float f = 0.25f / x;

    y = (m(1, 0) + m(0, 1)) * f;
    z = (m(0, 2) + m(2, 0)) * f;
    w = (m(2, 1) - m(1, 2)) * f;
  } else if (m(1, 1) > m(2, 2)) {
    y = Utils::sqrt(m(1, 1) - m(0, 0) - m(2, 2) + 1.0f) * 0.5f;
    float f = 0.25f / y;

    x = (m(1, 0) + m(0, 1)) * f;
    z = (m(2, 1) + m(1, 2)) * f;
    w = (m(0, 2) - m(2, 0)) * f;
  } else {
    z = Utils::sqrt(m(2, 2) - m(0, 0) - m(1, 1) + 1.0f) * 0.5f;
    float f = 0.25f / z;

    x = (m(0, 2) + m(2, 0)) * f;
    y = (m(2, 1) + m(1, 2)) * f;
    w = (m(1, 0) - m(0, 1)) * f;
  }
}
