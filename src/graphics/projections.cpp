#include "projections.h"

#include <cmath>

namespace engine {

Matrix4 FrustumProjection(float fovy, float s, float n, float f) {
  float g = 1.0f / tanf(fovy * 0.5f);
  float k = f / (f - n);
  // clang-format off
  return {
    g/s , 0.0f, 0.0f, 0.0f,
    0.0f, g   , 0.0f, 0.0f,
    0.0f, 0.0f, k   , -n * k,
    0.0f, 0.0f, 1.0f, 0.0f,
  };
  // clang-format on
}
Matrix4 InfiniteProjection(float fovy, float s, float n, float e) {
  float g = 1.0f / tanf(fovy * 0.5f);
  e = 1.0f - e;
  // clang-format off
  return {
      g/s , 0.0f, 0.0f, 0.0f,
      0.0f, g   , 0.0f, 0.0f,
      0.0f, 0.0f, e   , -n * e,
      0.0f, 0.0f, 1.0f, 0.0f,
  };
  // clang-format on
}
}  // namespace engine
