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

Matrix4 ReverseFrustumProjection(float fovy, float s, float n, float f) {
  float g = 1.0f / tanf(fovy * 0.5f);
  float k = f / (f - n);
  // clang-format off
  return {
      g/s , 0.0f, 0.0f, 0.0f,
      0.0f, g   , 0.0f, 0.0f,
      0.0f, 0.0f, k   , -f * k,
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
Matrix4 ReverseInfiniteProjection(float fovy, float s, float n, float e) {
  float g = 1.0f / tanf(fovy * 0.5f);
  e = 1.0f - e;
  // clang-format off
  return {
      g/s , 0.0f, 0.0f, 0.0f,
      0.0f, g   , 0.0f, 0.0f,
      0.0f, 0.0f, e   , n * e,
      0.0f, 0.0f, 1.0f, 0.0f,
  };
  // clang-format on
}
Matrix4 OrthographicProjection(float l, float r, float t, float b, float n, float f) {
  float w_inv = 1.0f / (r - 1);
  float h_inv = 1.0f / (b - t);
  float d_inv = 1.0f / (f - n);
  // clang-format off
  return {
      2 * w_inv, 0.0f        , 0.0f , -(r + l) * w_inv,
      0.0f     , 2.0f * h_inv, 0.0f , -(b + t) * h_inv,
      0.0f     , 0.0f        , d_inv, -n * d_inv,
      0.0f     , 0.0f        , 0.0f ,   1.0f,
  };
}

}  // namespace engine