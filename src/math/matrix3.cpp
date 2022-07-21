#include "matrix3.h"

#include <cmath>

Matrix3 Matrix3::RotationX(float theta) {
  auto c = std::cos(Utils::Degree2Radian(theta));
  auto s = std::sin(Utils::Degree2Radian(theta));

  // clang-format off
  return { 1.0f, 0.0f, 0.0f,
           0.0f,  c,   -s  ,
           0.0f,  s,    c   };
  // clang-format on
}

Matrix3 Matrix3::RotationY(float theta) {
  auto c = std::cos(Utils::Degree2Radian(theta));
  auto s = std::sin(Utils::Degree2Radian(theta));

  // clang-format off
  return {  c,   0.0f,  s  ,
           0.0f, 1.0f, 0.0f,
           -s,   0.0f,  c  };
// clang-format on
}

Matrix3 Matrix3::RotationZ(float theta) {
  auto c = std::cos(Utils::Degree2Radian(theta));
  auto s = std::sin(Utils::Degree2Radian(theta));

  // clang-format off
  return {  c,   -s,   0.0f ,
            s,    c,   0.0f ,
           0.0f, 0.0f, 1.0f };
  // clang-format on
}
