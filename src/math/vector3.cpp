#include "vector3.h"

Vector3::Vector3(float x_in, float y_in, float z_in) {
  x = x_in;
  y = y_in;
  z = z_in;
}

float& Vector3::operator[](int i) { return ((&x)[i]); }

const float& Vector3::operator[](int i) const { return ((&x)[i]); }

[[nodiscard]] std::string Vector3::ToString() const {
  std::string result = "<x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z) + ">";
  return result;
}
