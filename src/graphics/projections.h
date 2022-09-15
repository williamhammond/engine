#ifndef ENGINE_PROJECTIONS_H
#define ENGINE_PROJECTIONS_H

#include "math/matrix4.h"

namespace engine {
Matrix4 FrustumProjection(float fovy, float s, float n, float f);
Matrix4 ReverseFrustumProjection(float fovy, float s, float n, float f);
Matrix4 InfiniteProjection(float fovy, float s, float n, float e);
Matrix4 ReverseInfiniteProjection(float fovy, float s, float n, float e);
Matrix4 OrthographicProjection(float l, float r, float t, float b, float n, float f);

}  // namespace engine

#endif  // ENGINE_PROJECTIONS_H
