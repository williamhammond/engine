#ifndef ENGINE_VECTOR3_H
#define ENGINE_VECTOR3_H

#include "utils.h"

class Vector3 {
 private:
 public:
  float x, y, z;

  Vector3() = default;
  Vector3(float x_in, float y_in, float z_in);

  float& operator[](int i);
  const float& operator[](int i) const;

  Vector3 operator+(const Vector3& v) const { return {x + v.x, y + v.y, z + v.z}; }
  Vector3& operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return (*this);
  }

  Vector3 operator-(const Vector3& v) const { return {x - v.x, y - v.y, z - v.z}; }
  Vector3& operator-=(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return (*this);
  }

  inline Vector3& operator*=(float a) {
    x *= a;
    y *= a;
    z *= a;
    return (*this);
  }
  inline Vector3& operator/=(float a) {
    x /= a;
    y /= a;
    z /= a;
    return (*this);
  }
  inline Vector3 operator*(float a) const { return {x * a, y * a, z * a}; }
  inline Vector3 operator/(float a) const { return {x / a, y / a, z / a}; }
  inline Vector3 operator-() const { return {-x, -y, -z}; }

  [[nodiscard]] inline bool Equals(const Vector3& b, float epsilon = 0.0f) const {
    return Utils::abs(b.x - x) <= epsilon && Utils::abs(b.y - y) <= epsilon && Utils::abs(b.z - z) <= epsilon;
  }

  [[nodiscard]] inline float Magnitude() const {
    return Utils::sqrt(Utils::square(x) + Utils::square(y) + Utils::square(z));
  }

  inline Vector3 Normalize() {
    if (Magnitude() == 0) {
      return (*this);
    }
    return ((*this) / Magnitude());
  }

  [[nodiscard]] inline float Dot(Vector3 b) const { return x * b.x + y * b.y + z * b.z; }

  inline Vector3 Cross(Vector3 b) const { return {y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x}; }

  // TODO: figure out 0 projection
  inline Vector3 Project(Vector3 b) const { return b * (this->Dot(b) / b.Dot(b)); }

  inline Vector3 Reject(const Vector3& b) const { return *this - Project(b); }
};

#endif  // ENGINE_VECTOR3_H
