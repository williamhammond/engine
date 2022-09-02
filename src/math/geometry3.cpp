#include "geometry3.h"

#include "fmath.h"

namespace engine {
float Geometry3::PointToLine(const engine::Vector3& q, const engine::Vector3 p, const engine::Vector3 v) {
  Vector3 a = (q - p).Cross(v);
  return FMath::sqrt(a.Dot(a) / v.Dot(v));
}
}  // namespace engine
