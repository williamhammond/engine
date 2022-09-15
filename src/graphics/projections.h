#ifndef ENGINE_PROJECTIONS_H
#define ENGINE_PROJECTIONS_H

#include "math/matrix4.h"

namespace engine {
Matrix4 FrustumProjection(float vovy, float s, float n, float f);
}  // namespace engine

#endif  // ENGINE_PROJECTIONS_H
