#ifndef ENGINE_VECTOR3_H
#define ENGINE_VECTOR3_H

#include <sstream>

#include "utils.h"

namespace engine {
class Vector3 {
 public:
  float x, y, z;

  Vector3() = default;
  Vector3(float x_in, float y_in, float z_in);

  float& operator[](int i);
  const float& operator[](int i) const;

  inline Vector3 operator+(const Vector3& v) const { return {x + v.x, y + v.y, z + v.z}; }
  inline Vector3& operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return (*this);
  }

  inline Vector3 operator-(const Vector3& v) const { return {x - v.x, y - v.y, z - v.z}; }
  inline Vector3& operator-=(const Vector3& v) {
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

  [[nodiscard]] inline Vector3 Normalize() const {
    if (Magnitude() == 0) {
      return (*this);
    }
    return ((*this) / Magnitude());
  }

  [[nodiscard]] inline float Dot(Vector3 b) const { return x * b.x + y * b.y + z * b.z; }

  [[nodiscard]] inline Vector3 Cross(Vector3 b) const {
    return {y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x};
  }

  // TODO: figure out 0 projection
  [[nodiscard]] inline Vector3 Project(Vector3 b) const { return b * (this->Dot(b) / b.Dot(b)); }

  [[nodiscard]] inline Vector3 Reject(const Vector3& b) const { return *this - Project(b); }

  [[nodiscard]] inline bool IsOrthogonal(const Vector3& b) const { return Utils::Equals((*this).Dot(b), 0, 1e-9f); }

  [[nodiscard]] std::string ToString() const;
};
}  // namespace engine

#endif  // ENGINE_VECTOR3_H
