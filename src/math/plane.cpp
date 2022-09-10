#include "plane.h"

#include "vector3.h"

namespace engine {

Plane::Plane(float x_in, float y_in, float z_in, float w_in) {
  x = x_in;
  y = y_in;
  z = z_in;
  w = w_in;
}

Plane::Plane(const Vector3& n, float d) {
  x = n.x;
  y = n.y;
  z = n.z;
  w = d;
}
const Vector3& Plane::GetNormal() const { return (reinterpret_cast<const Vector3&>(x)); }

float Plane::Dot(const Vector3& v) const { return x * v.x + y * v.y + z * v.z + w; }

Plane operator*(const Plane& f, const Transform4& H) {
  // clang-format off
  return {
    f.x * H(0, 0) + f.y * H(1,0) + f.z * H(2, 0),
    f.x * H(0, 1) + f.y * H(1,1) + f.z * H(2, 1),
    f.x * H(0, 2) + f.y * H(1,2) + f.z * H(2, 2),
    f.x * H(0, 3) + f.y * H(1,3) + f.z * H(2, 3) + f.w,
  };
  // clang-format on
}

Transform4 Plane::MakeReflection(const Plane& f) {
  float a = f.x * -2.0f;
  float b = f.y * -2.0f;
  float c = f.z * -2.0f;

  // clang-format off
  return {
      a * f.x + 1.0f, a * f.y       , a * f.z       , a * f.w,
      a * f.y       , b * f.y + 1.0f, b * f.z       , b * f.w,
      a * f.z       , c * f.z + 1.0f, c * f.z + 1.0f, c * f.w,
  };
  // clang-format on
}
}  // namespace engine