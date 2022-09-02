#include "geometry3.h"

#include <cfloat>

#include "fmath.h"

namespace engine {
float Geometry3::PointToLine(const Vector3& q, const Vector3& p, const Vector3& v) {
  Vector3 a = (q - p).Cross(v);
  return FMath::sqrt(a.Dot(a) / v.Dot(v));
}
float Geometry3::PointToPoint(const Vector3& p1, const Vector3& v1, const Vector3& p2, const Vector3& v2) {
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
bool Geometry3::LineIntersectsPlane(const Vector3& p, const Vector3& v, const Plane& f, Vector3& intersection) {
  float f_dot_v = f.Dot(v);
  if (FMath::abs(f_dot_v) > FLT_MIN) {
    intersection = p - v * (f.Dot(p) / f_dot_v);
    return true;
  }
  return false;
}
bool Geometry3::TwoPlanesIntersect(const Plane& f1, const Plane& f2, Vector3& intersection, Vector3& normal) {
  const Vector3& n1 = f1.GetNormal();
  const Vector3& n2 = f2.GetNormal();
  normal = n1.Cross(n2);

  float det = normal.Dot(normal);
  if (FMath::abs(det) > FLT_MIN) {
    intersection = (normal.Cross(n2) * f1.w + n1.Cross(normal) * f2.w) / det;
    return true;
  }

  return false;
}

bool Geometry3::ThreePlanesIntersect(const Plane& f1, const Plane& f2, const Plane& f3, Vector3& intersection) {
  const Vector3& n1 = f1.GetNormal();
  const Vector3& n2 = f2.GetNormal();
  const Vector3& n3 = f3.GetNormal();
  Vector3 normal = n1.Cross(n2);

  float det = normal.Dot(n3);
  if (FMath::abs(det) > FLT_MIN) {
    intersection = (n3.Cross(n2) * f1.w + n1.Cross(n3) * f2.w - normal * f3.w) / det;
    return true;
  }

  return false;
}
}  // namespace engine
