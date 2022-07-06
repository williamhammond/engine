#include "utils.h"

float Utils::sqrt(float x) {
  float n = x;
  float y = 1;
  float e = 0.000001f;
  while (n - y > e) {
    n = (n + y) / 2;
    y = x / n;
  }
  return n;
}

float Utils::square(float x) { return x * x; }

float Utils::abs(float x) {
  if (x >= 0) {
    return x;
  }
  return -x;
}