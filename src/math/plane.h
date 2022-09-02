#ifndef ENGINE_PLANE_H
#define ENGINE_PLANE_H

#include "vector3.h"

namespace engine {
class Plane {
 public:
  float x, y, z, w;

  Plane() = default;

  Plane(float x_in, float y_in, float z_in, float w_in);

  Plane(const Vector3& n, float d);

  [[nodiscard]] const Vector3& GetNormal() const;

  float Dot(const Plane& p, const Vector3& v);
};

}  // namespace engine
#endif  // ENGINE_PLANE_H
