#include "utils.h"

#include <stdexcept>

/**
 * Implemented using Newton's Method
 * https://en.wikipedia.org/wiki/Newton's_method
 */
float Utils::sqrt(float x) {
  if (x == 0) {
    return 0;
  }

  if (x < 0) {
    throw std::invalid_argument("sqrt only accepts positive numbers");
  }

  float precision = 0.001f;
  float r = x;
  float root;

  int count = 0;
  while (true) {
    count++;
    root = 0.5f * (r + (x / r));
    if (abs(root - r) < precision) break;
    r = root;
  }

  return root;
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
