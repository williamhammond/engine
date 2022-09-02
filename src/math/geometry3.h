#ifndef ENGINE_GEOMETRY3_H
#define ENGINE_GEOMETRY3_H

#include "plane.h"
#include "vector3.h"

namespace engine {
class Geometry3 {
  static float PointToLine(const Vector3& q, const Vector3& p, const Vector3& v);
  static float PointToPoint(const Vector3& p1, const Vector3& v1, const Vector3& p2, const Vector3& v2);
  // TODO possibly break this into multiple methods to avoid the side-effect
  static bool LineIntersectsPlane(const Vector3& p, const Vector3& v, const Plane& f, Vector3& intersection);
};
}  // namespace engine

#endif  // ENGINE_GEOMETRY3_H
