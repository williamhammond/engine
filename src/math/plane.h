#ifndef ENGINE_PLANE_H
#define ENGINE_PLANE_H

#include "transform4.h"
#include "vector3.h"

namespace engine {
class Plane {
 public:
  float x, y, z, w;

  Plane() = default;

  Plane(float x_in, float y_in, float z_in, float w_in);

  Plane(const Vector3& n, float d);

  [[nodiscard]] const Vector3& GetNormal() const;

  [[nodiscard]] float Dot(const Vector3& v) const;

  Transform4 MakeReflection(const Plane& f);
};

Plane operator*(const Plane& f, const Transform4& H);

}  // namespace engine
#endif  // ENGINE_PLANE_H
