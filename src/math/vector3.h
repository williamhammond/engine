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

  [[nodiscard]] inline float Magnitude() const {
    return Utils::sqrt(Utils::square(x) + Utils::square(y) + Utils::square(z));
  }

  inline Vector3 Normalize() {
    // TODO handle 0 division properly
    return ((*this) / (Magnitude() + 0.000000001f));
  }
};

#endif  // ENGINE_VECTOR3_H
