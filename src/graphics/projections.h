#ifndef ENGINE_PROJECTIONS_H
#define ENGINE_PROJECTIONS_H

#include "math/matrix4.h"

namespace engine {
Matrix4 FrustumProjection(float fovy, float s, float n, float f);
Matrix4 InfiniteProjection(float fovy, float s, float n, float e);

}  // namespace engine

#endif  // ENGINE_PROJECTIONS_H
