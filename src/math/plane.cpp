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
}  // namespace engine