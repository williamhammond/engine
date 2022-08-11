#ifndef ENGINE_VECTOR4_H
#define ENGINE_VECTOR4_H

#include <sstream>

#include "utils.h"
namespace engine {
class Vector4 {
 private:
 public:
  float x, y, z, w;

  Vector4() = default;
  Vector4(float x_in, float y_in, float z_in, float w_in);

  float& operator[](int i);
  const float& operator[](int i) const;

  inline Vector4 operator+(const Vector4& v) const { return {x + v.x, y + v.y, z + v.z, w + v.w}; }
  inline Vector4& operator+=(const Vector4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return (*this);
  }

  // TODO: Double check that w should actually be subtracted here
  inline Vector4 operator-(const Vector4& v) const { return {x - v.x, y - v.y, z - v.z, w - v.w}; }
  inline Vector4& operator-=(const Vector4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return (*this);
  }

  inline Vector4& operator*=(float a) {
    x *= a;
    y *= a;
    z *= a;
    w *= a;
    return (*this);
  }
  inline Vector4& operator/=(float a) {
    x /= a;
    y /= a;
    z /= a;
    w /= a;
    return (*this);
  }
  inline Vector4 operator*(float a) const { return {x * a, y * a, z * a, w * a}; }
  inline Vector4 operator/(float a) const { return {x / a, y / a, z / a, w / a}; }
  inline Vector4 operator-() const { return {-x, -y, -z, -w}; }

  [[nodiscard]] inline bool Equals(const Vector4& b, float epsilon = 0.0f) const {
    return Utils::abs(b.x - x) <= epsilon && Utils::abs(b.y - y) <= epsilon && Utils::abs(b.z - z) <= epsilon &&
           Utils::abs(b.w - w) <= epsilon;
  }

  [[nodiscard]] inline float Magnitude() const {
    return Utils::sqrt(Utils::square(x) + Utils::square(y) + Utils::square(z) + Utils::square(w));
  }

  [[nodiscard]] inline Vector4 Normalize() const {
    if (Magnitude() == 0) {
      return (*this);
    }
    return ((*this) / Magnitude());
  }

  [[nodiscard]] inline float Dot(Vector4 b) const { return x * b.x + y * b.y + z * b.z + w * b.w; }

  // TODO: figure out 0 projection
  [[nodiscard]] inline Vector4 Project(Vector4 b) const { return b * (this->Dot(b) / b.Dot(b)); }

  [[nodiscard]] inline Vector4 Reject(const Vector4& b) const { return *this - Project(b); }

  [[nodiscard]] inline bool IsOrthogonal(const Vector4& b) const { return Utils::Equals((*this).Dot(b), 0, 1e-9f); }

  [[nodiscard]] std::string ToString() const;
};
}  // namespace engine

#endif  // ENGINE_VECTOR4_H
