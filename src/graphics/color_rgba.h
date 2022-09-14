#ifndef ENGINE_COLOR_RGBA_H
#define ENGINE_COLOR_RGBA_H

#include <string>

#include "math/fmath.h"

namespace engine {

class ColorRGBA {
 public:
  float red, green, blue, alpha;

  ColorRGBA() = default;

  ColorRGBA(float r, float g, float b, float a = 1.0f) {
    red = r;
    green = g;
    blue = b;
    alpha = a;
  }

  ColorRGBA& operator*=(float s) {
    red *= s;
    green *= s;
    blue *= s;
    alpha *= s;
    return (*this);
  }

  ColorRGBA& operator/=(float s) {
    s = 1.0f / s;
    red *= s;
    green *= s;
    blue *= s;
    alpha *= s;
    return (*this);
  }

  ColorRGBA& operator+=(const ColorRGBA& c) {
    red += c.red;
    green += c.green;
    blue += c.blue;
    alpha += c.alpha;
    return (*this);
  }

  ColorRGBA& operator-=(const ColorRGBA& c) {
    red -= c.red;
    green -= c.green;
    blue -= c.blue;
    alpha -= c.alpha;
    return (*this);
  }

  ColorRGBA& operator*=(const ColorRGBA& c) {
    red *= c.red;
    green *= c.green;
    blue *= c.blue;
    alpha *= c.alpha;
    return (*this);
  }
  [[nodiscard]] inline bool Equals(const ColorRGBA& other, float epsilon = 0.0f) const {
    return FMath::abs(other.red - (*this).red) < epsilon && FMath::abs(other.green - (*this).green) < epsilon &&
           FMath::abs(other.blue - (*this).blue) < epsilon && FMath::abs(other.alpha - (*this).alpha) < epsilon;
  }

  [[nodiscard]] std::string ToString() const;
};

inline ColorRGBA operator*(const ColorRGBA& c, float s) { return {c.red * s, c.green * s, c.blue * s, s * c.alpha}; }

inline ColorRGBA operator/(const ColorRGBA& c, float s) {
  s = 1.0f / s;
  return {c.red * s, c.green * s, c.blue * s, s * c.alpha};
}

inline ColorRGBA operator+(const ColorRGBA& a, const ColorRGBA& b) {
  return {a.red + b.red, a.green + b.green, a.blue + b.blue, a.alpha + b.alpha};
}

inline ColorRGBA operator-(const ColorRGBA& a, const ColorRGBA& b) {
  return {a.red - b.red, a.green - b.green, a.blue - b.blue, a.alpha - b.alpha};
}

inline ColorRGBA operator*(const ColorRGBA& a, const ColorRGBA& b) {
  return {a.red * b.red, a.green * b.green, a.blue * b.blue, a.alpha * b.alpha};
}

#endif  // ENGINE_COLOR_RGBA_H
}
