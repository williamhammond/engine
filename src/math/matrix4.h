#ifndef ENGINE_MATRIX4_H
#define ENGINE_MATRIX4_H

#include "utils.h"
#include "vector3.h"
#include "vector4.h"

class Matrix4 {
 protected:
  float n[4][4];

 public:
  Matrix4() = default;
  static Matrix4 Identity();
  static Matrix4 RotationX(float theta);
  static Matrix4 RotationY(float theta);
  static Matrix4 RotationZ(float theta);
  static Matrix4 Rotation(float theta, Vector4 axis);
  static Matrix4 Reflection(const Vector4& a);
  static Matrix4 Involution(const Vector4& a);
  static Matrix4 Scale(float x_scalar, float y_scalar, float z_scalar);
  static Matrix4 Scale(float s, const Vector4& a);
  static Matrix4 Skew(float theta, const Vector4& a_norm, const Vector4& b_norm);

  Matrix4(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21,
          float n22, float n23, float n30, float n31, float n32, float n33) {
    n[0][0] = n00;
    n[1][0] = n01;
    n[2][0] = n02;
    n[3][0] = n03;

    n[0][1] = n10;
    n[1][1] = n11;
    n[2][1] = n12;
    n[3][1] = n13;

    n[0][2] = n20;
    n[1][2] = n21;
    n[2][2] = n22;
    n[3][2] = n23;

    n[0][3] = n30;
    n[1][3] = n31;
    n[2][3] = n32;
    n[3][3] = n33;
  }

  Matrix4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d) {
    n[0][0] = a.x;
    n[0][1] = a.y;
    n[0][2] = a.z;
    n[0][3] = a.w;

    n[1][0] = b.x;
    n[1][1] = b.y;
    n[1][2] = b.z;
    n[1][3] = b.w;

    n[2][0] = c.x;
    n[2][1] = c.y;
    n[2][2] = c.z;
    n[2][3] = c.w;

    n[3][0] = d.x;
    n[3][1] = d.y;
    n[3][2] = d.z;
    n[3][3] = d.w;
  }

  float& operator()(int i, int j) { return (n[j][i]); }
  const float& operator()(int i, int j) const { return (n[j][i]); }

  Vector4& operator[](int j) { return (*reinterpret_cast<Vector4*>(n[j])); }

  // TODO: Probably remove this in favor of named vector fetchers
  const Vector4& operator[](int j) const { return (*reinterpret_cast<const Vector4*>(n[j])); }

  Matrix4 operator*(const Matrix4 B) const {
    return {(*this)(0, 0) * B(0, 0) + (*this)(0, 1) * B(1, 0) + (*this)(0, 2) * B(2, 0) + (*this)(0, 3) * B(3, 0),
            (*this)(0, 0) * B(0, 1) + (*this)(0, 1) * B(1, 1) + (*this)(0, 2) * B(2, 1) + (*this)(0, 3) * B(3, 1),
            (*this)(0, 0) * B(0, 2) + (*this)(0, 1) * B(1, 2) + (*this)(0, 2) * B(2, 2) + (*this)(0, 3) * B(3, 2),
            (*this)(0, 0) * B(0, 3) + (*this)(0, 1) * B(1, 3) + (*this)(0, 2) * B(2, 3) + (*this)(0, 3) * B(3, 3),

            (*this)(1, 0) * B(0, 0) + (*this)(1, 1) * B(1, 0) + (*this)(1, 2) * B(2, 0) + (*this)(1, 3) * B(3, 0),
            (*this)(1, 0) * B(0, 1) + (*this)(1, 1) * B(1, 1) + (*this)(1, 2) * B(2, 1) + (*this)(1, 3) * B(3, 1),
            (*this)(1, 0) * B(0, 2) + (*this)(1, 1) * B(1, 2) + (*this)(1, 2) * B(2, 2) + (*this)(1, 3) * B(3, 2),
            (*this)(1, 0) * B(0, 3) + (*this)(1, 1) * B(1, 3) + (*this)(1, 2) * B(2, 3) + (*this)(1, 3) * B(3, 3),

            (*this)(2, 0) * B(0, 0) + (*this)(2, 1) * B(1, 0) + (*this)(2, 2) * B(2, 0) + (*this)(2, 3) * B(3, 0),
            (*this)(2, 0) * B(0, 1) + (*this)(2, 1) * B(1, 1) + (*this)(2, 2) * B(2, 1) + (*this)(2, 3) * B(3, 1),
            (*this)(2, 0) * B(0, 2) + (*this)(2, 1) * B(1, 2) + (*this)(2, 2) * B(2, 2) + (*this)(2, 3) * B(3, 2),
            (*this)(2, 0) * B(0, 3) + (*this)(2, 1) * B(1, 3) + (*this)(2, 2) * B(2, 3) + (*this)(2, 3) * B(3, 3),

            (*this)(3, 0) * B(0, 0) + (*this)(3, 1) * B(1, 0) + (*this)(3, 2) * B(2, 0) + (*this)(3, 3) * B(3, 0),
            (*this)(3, 0) * B(0, 1) + (*this)(3, 1) * B(1, 1) + (*this)(3, 2) * B(2, 1) + (*this)(3, 3) * B(3, 1),
            (*this)(3, 0) * B(0, 2) + (*this)(3, 1) * B(1, 2) + (*this)(3, 2) * B(2, 2) + (*this)(3, 3) * B(3, 2),
            (*this)(3, 0) * B(0, 3) + (*this)(3, 1) * B(1, 3) + (*this)(3, 2) * B(2, 3) + (*this)(3, 3) * B(3, 3)};
  }

  Vector4 operator*(const Vector4& v) {
    return {(*this)[0][0] * v.x + (*this)[0][1] * v.y + (*this)[0][2] * v.z + (*this)[0][2] * v.w,
            (*this)[1][0] * v.x + (*this)[1][1] * v.y + (*this)[1][2] * v.z + (*this)[1][2] * v.w,
            (*this)[2][0] * v.x + (*this)[2][1] * v.y + (*this)[2][2] * v.z + (*this)[2][2] * v.w,
            (*this)[2][0] * v.x + (*this)[2][1] * v.y + (*this)[2][2] * v.z + (*this)[2][2] * v.w};
  }

  [[nodiscard]] inline bool Equals(const Matrix4& N, float epsilon = 0.0f) const {
    return Utils::abs((*this)(0, 0) - N(0, 0)) < epsilon && Utils::abs((*this)(0, 1) - N(0, 1)) < epsilon &&
           Utils::abs((*this)(0, 2) - N(0, 2)) < epsilon && Utils::abs((*this)(1, 0) - N(1, 0)) < epsilon &&
           Utils::abs((*this)(1, 1) - N(1, 1)) < epsilon && Utils::abs((*this)(1, 2) - N(1, 2)) < epsilon &&
           Utils::abs((*this)(2, 0) - N(2, 0)) < epsilon && Utils::abs((*this)(2, 1) - N(2, 1)) < epsilon &&
           Utils::abs((*this)(2, 2) - N(2, 2)) < epsilon;
  }

  [[nodiscard]] inline float Determinant() const {
    return (*this)(0, 0) * (*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1) +
           (*this)(0, 1) * (*this)(1, 2) * (*this)(2, 0) - (*this)(1, 0) * (*this)(2, 2) +
           (*this)(0, 2) * (*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0);
  }

  [[nodiscard]] inline Matrix4 Inverse() const {
    const auto& a = reinterpret_cast<const Vector3&>((*this)[0]);
    const auto& b = reinterpret_cast<const Vector3&>((*this)[1]);
    const auto& c = reinterpret_cast<const Vector3&>((*this)[2]);
    const auto& d = reinterpret_cast<const Vector3&>((*this)[3]);

    const auto& x = (*this)(3, 0);
    const auto& y = (*this)(3, 1);
    const auto& z = (*this)(3, 2);
    const auto& w = (*this)(3, 3);

    Vector3 s = a.Cross(b);
    Vector3 t = c.Cross(d);
    Vector3 u = a * y - b * x;
    Vector3 v = c * w - d * z;

    float invDet = 1.0f / s.Dot(v) + t.Dot(u);

    s *= invDet;
    t *= invDet;
    u *= invDet;
    v *= invDet;

    Vector3 r0 = b.Cross(v) + t * y;
    Vector3 r1 = v.Cross(a) - t * w;
    Vector3 r2 = d.Cross(u) + s * w;
    Vector3 r3 = u.Cross(c) - s * z;

    // clang-format off
    return {
      r0.x, r0.y, r0.z, -b.Dot(t),
      r1.x, r1.y, r1.z,  a.Dot(t),
      r2.x, r2.y, r2.z, -d.Dot(s),
      r3.x, r3.y, r3.z,  c.Dot(s),
    };
    // clang-format on
  }

  [[nodiscard]] std::string ToString() const {
    std::string result{};
    for (int i = 0; i < 4; i++) {
      result += "| ";
      for (int j = 0; j < 4; j++) {
        result += std::to_string((*this)(i, j));
        if (j != 3) {
          result += ", ";
        }
      }
      result += " |";
      if (i != 3) {
        result += "\n";
      }
    }

    return result;
  }
};

#endif  // ENGINE_MATRIX4_H
