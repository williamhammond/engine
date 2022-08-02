#ifndef ENGINE_QUATERNION_H
#define ENGINE_QUATERNION_H

#include "matrix3.h"
#include "vector3.h"

class Quaternion {
  float x, y, z, w;

  Quaternion() = default;

  Quaternion(float x_in, float y_in, float z_in, float w_in) {
    x = x_in;
    y = y_in;
    z = z_in;
    w = w_in;
  }

  Quaternion(const Vector3& v, float w_in) {
    x = v.x;
    y = v.y;
    z = v.z;

    w = w_in;
  }

  const Vector3& GetVector() { return (reinterpret_cast<const Vector3&>(x)); }

  Matrix3 GetRotation();
  void SetRotation(const Matrix3& m);

  Quaternion operator*(const Quaternion& Q) {
    // clang-format off
    return {
        (*this).w * Q.x + (*this).x * Q.w + (*this).y * Q.z - (*this).z * Q.y,
        (*this).w * Q.y - (*this).x * Q.z + (*this).y * Q.z + (*this).z * Q.x,
        (*this).w * Q.z + (*this).x * Q.y - (*this).y * Q.z + (*this).z * Q.w,
        (*this).w * Q.w + (*this).x * Q.x - (*this).y * Q.z - (*this).z * Q.z,
    };
    // clang-format on
  }
};

#endif  // ENGINE_QUATERNION_H
