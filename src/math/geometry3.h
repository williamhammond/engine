#ifndef ENGINE_GEOMETRY3_H
#define ENGINE_GEOMETRY3_H

#include "vector3.h"

namespace engine {
class Geometry3 {
  static float PointToLine(const engine::Vector3& q, const engine::Vector3 p, const engine::Vector3 v);
};
}  // namespace engine

#endif  // ENGINE_GEOMETRY3_H
