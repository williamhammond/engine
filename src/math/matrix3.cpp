#include "matrix3.h"

#include <cmath>
#include <stdexcept>

#include "fmath.h"
#include "vector3.h"

engine::Matrix3 engine::Matrix3::Identity() {
  // clang-format off
  return { 1.0f, 0.0f, 0.0f,
           0.0f, 1.0f, 0.0f,
           0.0f, 0.0f, 1.0f
  };
  // clang-format on
}

engine::Matrix3 engine::Matrix3::RotationX(float theta) {
  auto c = std::cos(FMath::Degree2Radian(theta));
  auto s = std::sin(FMath::Degree2Radian(theta));

  // clang-format off
  return { 1.0f, 0.0f, 0.0f,
           0.0f,  c,   -s  ,
           0.0f,  s,    c
  };
  // clang-format on
}

engine::Matrix3 engine::Matrix3::RotationY(float theta) {
  auto c = std::cos(FMath::Degree2Radian(theta));
  auto s = std::sin(FMath::Degree2Radian(theta));

  // clang-format off
  return {  c,   0.0f,  s  ,
           0.0f, 1.0f, 0.0f,
           -s,   0.0f,  c
  };
  // clang-format on
}

engine::Matrix3 engine::Matrix3::RotationZ(float theta) {
  auto c = std::cos(FMath::Degree2Radian(theta));
  auto s = std::sin(FMath::Degree2Radian(theta));

  // clang-format off
  return {  c,   -s,   0.0f ,
            s,    c,   0.0f ,
           0.0f, 0.0f, 1.0f };
  // clang-format on
}

// https://gamemath.com/book/matrixtransforms.html#rotation_3d_arbitrary_axis
engine::Matrix3 engine::Matrix3::Rotation(float theta, Vector3 axis) {
  auto a = axis.Normalize();

  auto c = std::cos(FMath::Degree2Radian(theta));
  auto s = std::sin(FMath::Degree2Radian(theta));
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

engine::Matrix3 engine::Matrix3::Reflection(const Vector3 &a) {
  auto x = a.x * -2.0f;
  auto y = a.y * -2.0f;
  auto z = a.z * -2.0f;

  auto axay = x * a.y;
  auto axaz = x * a.z;
  auto ayaz = y * a.z;

  // clang-format off
  return {  x * a.x + 1.0f, axay          , axaz,
            axay          , y * a.y + 1.0f, ayaz,
            axaz          , ayaz          , z * a.z + 1.0f
  };
  // clang-format on
}

engine::Matrix3 engine::Matrix3::Involution(const Vector3 &a) {
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

engine::Matrix3 engine::Matrix3::Scale(float x_scalar, float y_scalar, float z_scalar) {
  // clang-format off
  return { x_scalar, 0       , 0,
           0       , y_scalar, 0,
           0       , 0       , z_scalar
  };
  // clang-format on
}

engine::Matrix3 engine::Matrix3::Scale(float s, const Vector3 &a) {
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

engine::Matrix3 engine::Matrix3::Skew(float theta, const Vector3 &a, const Vector3 &b) {
  if (!a.IsOrthogonal(b)) {
    throw std::invalid_argument(a.ToString() + "needs to be orthogonal to " + b.ToString());
  }

  auto a_norm = a.Normalize();
  auto b_norm = b.Normalize();
  theta = std::tan(FMath::Degree2Radian(theta));

  auto x = a_norm.x * theta;
  auto y = a_norm.y * theta;
  auto z = a_norm.z * theta;

  // clang-format off
  return { x * b_norm.x + 1.0f, x * b_norm.y       , x * b_norm.z,
           y * b_norm.x       , y * b_norm.y + 1.0f, y * b_norm.z,
           z * b_norm.x       , z * b_norm.y       , z * b_norm.z + 1.0f,
  };
  // clang-format on
}
