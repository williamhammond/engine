#include "plane.h"

#include "vector3.h"

engine::Plane::Plane(float x_in, float y_in, float z_in, float w_in) {
  x = x_in;
  y = y_in;
  z = z_in;
  w = w_in;
}

engine::Plane::Plane(const Vector3& n, float d) {
  x = n.x;
  y = n.y;
  z = n.z;
  w = d;
}
const engine::Vector3& engine::Plane::GetNormal() const { return (reinterpret_cast<const Vector3&>(x)); }

float Dot(const engine::Plane& p, const engine::Vector3& v) { return p.x * v.x + p.y * v.y + p.z * v.z + p.w; }