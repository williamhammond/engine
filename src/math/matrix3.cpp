#include "matrix3.h"

#include <cmath>

Matrix3 Matrix3::RotationX(float theta) {
  auto c = std::cos(Utils::Degree2Radian(theta));
  auto s = std::sin(Utils::Degree2Radian(theta));

  // clang-format off
  return { 1.0f, 0.0f, 0.0f,
           0.0f,  c,   -s  ,
           0.0f,  s,    c
  };
  // clang-format on
}

Matrix3 Matrix3::RotationY(float theta) {
  auto c = std::cos(Utils::Degree2Radian(theta));
  auto s = std::sin(Utils::Degree2Radian(theta));

  // clang-format off
  return {  c,   0.0f,  s  ,
           0.0f, 1.0f, 0.0f,
           -s,   0.0f,  c
  };
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

Matrix3 Matrix3::Rotation(float theta, Vector3 axis) {
  auto a = axis.Normalize();

  auto c = std::cos(Utils::Degree2Radian(theta));
  auto s = std::sin(Utils::Degree2Radian(theta));
  auto d = 1.0f - c;

  float x = a.x * d;
  float y = a.y * d;
  float z = a.z * d;

  float axay = x * a.y;
  float axaz = x * a.z;
  float ayaz = y * a.z;

  // clang-format off
  return { c + x * a.x   , axay -s * a.z , axaz + s * a.y,
           axay + s * a.z, c + y * a.y   , ayaz -s * a.x,
           axaz -s * a.y , ayaz + s * a.x, c + z * a.z
  };
  // clang-format on
}

Matrix3 Matrix3::Reflection(const Vector3 &a) {
  auto x = a.x * -2.0f;
  auto y = a.y * -2.0f;
  auto z = a.z * -2.0f;

  auto axay = x * a.y;
  auto axaz = x * a.z;
  auto ayaz = y * a.z;

  // clang-format off
  return {  x * a.x + 1.0f, axay,                 axaz,
            axay                , y * a.y + 1.0f, ayaz,
            axaz                , ayaz          , z * a.z + 1.0f
  };
  // clang-format on
}

Matrix3 Matrix3::Involution(const Vector3 &a) {
  auto x = a.x * 2.0f;
  auto y = a.y * 2.0f;
  auto z = a.z * 2.0f;

  auto axay = x * a.y;
  auto axaz = x * a.z;
  auto ayaz = y * a.z;

  // clang-format off
  return {  x * a.x - 1.0f, axay,                 axaz,
            axay                , y * a.y - 1.0f, ayaz,
            axaz                , ayaz          , z * a.z - 1.0f
  };
  // clang-format on
}

Matrix3 Matrix3::Scale(float x_scalar, float y_scalar, float z_scalar) {
  // clang-format off
  return { x_scalar, 0       , 0,
           0       , y_scalar, 0,
           0       , 0       , z_scalar
  };
  // clang-format on
}

Matrix3 Scale(float s, const Vector3 &a) {
  s -= 1.0f;

  auto x = a.x * s;
  auto y = a.y * s;
  auto z = a.z * s;

  float axay = x * a.y;
  float axaz = x * a.z;
  float ayaz = y * a.z;

  // clang-format off
  return { x * a.x + 1.0f, axay          , axaz,
           axay          , y * a.y + 1.0f, ayaz,
           axaz          , ayaz          , z * a.z + 1.0f

  };
  // clang-format on
}

Matrix3 Skew(float t, const Vector3 &a, const Vector3 b) {
  t = std::tan(t);

  auto x = a.x * t;
  auto y = a.y * t;
  auto z = a.z * t;

  // clang-format off
  return { x * b.x + 1.0f, x * b.y       , x * b.z,
           y * b.x       , y * b.y + 1.0f, y * b.z,
           z * b.x       , z * b.y       , z * b.z + 1.0f,
  };
  // clang-format on
}
