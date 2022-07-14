#include "utils.h"

/**
 * Implemented using Newton's Method
 * https://en.wikipedia.org/wiki/Newton's_method
 */
float Utils::sqrt(float x) {
  float r = x;
  float precision = pow(x, -10);

  while (abs(x - r * r) > precision) {
    r = (r + x / r) / 2;
  }

  return r;
}

float Utils::square(float x) { return x * x; }

float Utils::abs(float x) {
  if (x >= 0) {
    return x;
  }
  return -x;
}

int Utils::abs(int x) {
  if (x >= 0) {
    return x;
  }
  return -x;
}

float Utils::pow(float x, int exponent) {
  bool is_negative = exponent < 0;
  exponent = abs(exponent);
  float answer = 1;
  while (exponent > 0) {
    answer *= x;
    exponent--;
  }
  if (is_negative) {
    return 1 / answer;
  }
  return answer;
}
