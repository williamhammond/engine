#include "transform4.h"

namespace engine {

Transform4 Transform4::Inverse(const Transform4& H) {
  const Vector3& a = H[0];
  const Vector3& b = H[1];
  const Vector3& c = H[2];
  const Vector3& d = H[3];

  Vector3 s = a.Cross(b);
  Vector3 t = c.Cross(d);

  float invDet = 1.0f / s.Dot(c);
  s *= invDet;
  t *= invDet;
  Vector3 v = c * invDet;

  Vector3 r0 = b.Cross(v);
  Vector3 r1 = v.Cross(a);

  // clang-format off
  return {
      r0.x, r0.y, r0.z, -b.Dot(t),
      r1.x, r1.y, r1.z,  a.Dot(t),
      s.x,  s.y,  s.z, -d.Dot(s),
  };
  // clang-format on
}
Transform4 Transform4::MakeReflection(const Plane& f) {
  float x = f.x * -2.0f;
  float y = f.y * -2.0f;
  float z = f.z * -2.0f;

  // clang-format off
  return {
    x * f.x + 1.0f, x * f.y       , x * f.z       , x * f.w,
    x * f.y       , y * f.y + 1.0f, y * f.z       , y * f.w,
    x * f.z       , z * f.z + 1.0f, z * f.z + 1.0f, z * f.w,
  };
  // clang-format on
}
}  // namespace engine