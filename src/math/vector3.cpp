#include "vector3.h"

Vector3::Vector3(float x_in, float y_in, float z_in) {
  x = x_in;
  y = y_in;
  z = z_in;
}

float& Vector3::operator[](int i) { return ((&x)[i]); }

const float& Vector3::operator[](int i) const { return ((&x)[i]); }
