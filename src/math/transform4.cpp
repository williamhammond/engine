#include "transform4.h"

namespace engine {

engine::Transform4 engine::Transform4::Inverse(const engine::Transform4& H) {
  const engine::Vector3& a = H[0];
  const engine::Vector3& b = H[1];
  const engine::Vector3& c = H[2];
  const engine::Vector3& d = H[3];

  engine::Vector3 s = a.Cross(b);
  engine::Vector3 t = c.Cross(d);

  float invDet = 1.0f / s.Dot(c);
  s *= invDet;
  t *= invDet;
  engine::Vector3 v = c * invDet;

  engine::Vector3 r0 = b.Cross(v);
  engine::Vector3 r1 = v.Cross(a);

  // clang-format off
  return {
      r0.x, r0.y, r0.z, -b.Dot(t),
      r1.x, r1.y, r1.z,  a.Dot(t),
      s.x,  s.y,  s.z, -d.Dot(s),
  };
  // clang-format on
}
}  // namespace engine