#ifndef ENGINE_MATRIX3_H
#define ENGINE_MATRIX3_H

#include <iostream>

#include "vector3.h"

class Matrix3 {
 private:
  float n[3][3];

 public:
  Matrix3() = default;

  Matrix3(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22) {
    n[0][0] = n00;
    n[1][0] = n01;
    n[2][0] = n02;

    n[0][1] = n10;
    n[1][1] = n11;
    n[2][1] = n12;

    n[0][2] = n20;
    n[1][2] = n21;
    n[2][2] = n22;
  }

  Matrix3(const Vector3& a, const Vector3& b, const Vector3& c) {
    n[0][0] = a.x;
    n[0][1] = a.y;
    n[0][2] = a.z;

    n[1][0] = b.x;
    n[1][1] = b.y;
    n[1][2] = b.z;

    n[2][0] = c.x;
    n[2][1] = c.y;
    n[2][2] = c.z;
  }

  float& operator()(int i, int j) { return (n[j][i]); }
  const float& operator()(int i, int j) const { return (n[j][i]); }

  Vector3& operator[](int j) { return (*reinterpret_cast<Vector3*>(n[j])); }

  // TODO: Probably remove this in favor of named vector fetchers
  const Vector3& operator[](int j) const { return (*reinterpret_cast<const Vector3*>(n[j])); }

  Matrix3 operator*(const Matrix3 B) const {
    return {(*this)(0, 0) * B(0, 0) + (*this)(0, 1) * B(1, 0) + (*this)(0, 2) * B(2, 0),
            (*this)(0, 0) * B(0, 1) + (*this)(0, 1) * B(1, 1) + (*this)(0, 2) * B(2, 1),
            (*this)(0, 0) * B(0, 2) + (*this)(0, 1) * B(1, 2) + (*this)(0, 2) * B(2, 2),
            (*this)(1, 0) * B(0, 0) + (*this)(1, 1) * B(1, 0) + (*this)(1, 2) * B(2, 0),
            (*this)(1, 0) * B(0, 1) + (*this)(1, 1) * B(1, 1) + (*this)(1, 2) * B(2, 1),
            (*this)(1, 0) * B(0, 2) + (*this)(1, 1) * B(1, 2) + (*this)(1, 2) * B(2, 2),
            (*this)(2, 0) * B(0, 0) + (*this)(2, 1) * B(1, 0) + (*this)(2, 2) * B(2, 0),
            (*this)(2, 0) * B(0, 1) + (*this)(2, 1) * B(1, 1) + (*this)(2, 2) * B(2, 1),
            (*this)(2, 0) * B(0, 2) + (*this)(2, 1) * B(1, 2) + (*this)(2, 2) * B(2, 2)};
  }

  Vector3 operator*(const Vector3& v) {
    return {(*this)[0][0] * v.x + (*this)[0][1] * v.y + (*this)[0][2] * v.z,
            (*this)[1][0] * v.x + (*this)[1][1] * v.y + (*this)[1][2] * v.z,
            (*this)[2][0] * v.x + (*this)[2][1] * v.y + (*this)[2][2] * v.z};
  }

  [[nodiscard]] inline bool Equals(const Matrix3& N, float epsilon = 0.0f) const {
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

  [[nodiscard]] inline Matrix3 Inverse() const {
    const auto& a = (*this)[0];
    const auto& b = (*this)[1];
    const auto& c = (*this)[2];

    Vector3 r0 = b.Cross(c);
    Vector3 r1 = c.Cross(a);
    Vector3 r2 = a.Cross(b);

    auto invDet = 1.0f / r2.Dot(c);

    return {r0.x * invDet, r0.y * invDet, r0.z * invDet, r1.x * invDet, r1.y * invDet,
            r1.z * invDet, r2.x * invDet, r2.y * invDet, r2.z * invDet};
  }
  // TODO make this not fking stupid
  friend std::ostream& operator<<(std::ostream& os, const Matrix3& A);
};

std::ostream& operator<<(std::ostream& strm, const Matrix3& A) {
  for (int i = 0; i < 3; i++) {
    strm << "| ";
    for (int j = 0; j < 3; j++) {
      strm << A(i, j);
      if (j != 2) {
        strm << ", ";
      }
    }
    strm << " |";
    if (i != 2) {
      strm << "\n";
    }
  }
  return strm;
}
#endif  // ENGINE_MATRIX3_H
