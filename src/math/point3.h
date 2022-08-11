#ifndef ENGINE_POINT3_H
#define ENGINE_POINT3_H

#include "vector3.h"

class Point3 : engine::Vector3 {
 public:
  using engine::Vector3::x;
  using engine::Vector3::y;
  using engine::Vector3::z;

  Point3() = default;
  Point3(float a, float b, float c) : Vector3(a, b, c) {}

  inline Point3 operator+(const Vector3& b) { return {x + b.x, y + b.y, z + b.z}; }

  inline Point3 operator-(const Point3& b) { return {x - b.x, y - b.y, z - b.z}; }
};

#endif  // ENGINE_POINT3_H
