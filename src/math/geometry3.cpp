#include "geometry3.h"

#include <cfloat>

#include "fmath.h"

namespace engine {
float Geometry3::PointToLine(const engine::Vector3& q, const engine::Vector3 p, const engine::Vector3 v) {
  Vector3 a = (q - p).Cross(v);
  return FMath::sqrt(a.Dot(a) / v.Dot(v));
}
float Geometry3::PointToPoint(const Vector3& p1, const engine::Vector3 v1, const engine::Vector3 p2,
                              const engine::Vector3 v2) {
  float v1_squared_mag = v1.Dot(v1);
  float v2_squared_mag = v2.Dot(v2);
  float v1_dot_v2 = v1.Dot(v2);

  float det = v1_dot_v2 * v1_dot_v2 - v1_squared_mag * v2_squared_mag;
  auto dp = p2 - p1;
  if (FMath::abs(det) > FLT_MIN) {
    det = 1.0f / det;

    float dp_dot_v1 = dp.Dot(v1);
    float dp_dot_v2 = dp.Dot(v2);
    float t1 = (v1_dot_v2 * dp_dot_v2 - v2_squared_mag * dp_dot_v1) * det;
    float t2 = (v1_squared_mag * dp_dot_v2 - v1_dot_v2 * dp_dot_v1) * det;

    return (dp + v2 * t2 - v1 * t1).Magnitude();
  }

  // The lines are nearly identical
  Vector3 a = dp.Cross(v1);
  return FMath::sqrt(a.Dot(a) / v1_dot_v2);
}
}  // namespace engine
