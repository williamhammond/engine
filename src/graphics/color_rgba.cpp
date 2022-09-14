#include "color_rgba.h"

#include <string>

namespace engine {

std::string ColorRGBA::ToString() const {
  std::string result = "<r: " + std::to_string(red) + ", g: " + std::to_string(green) + ", b: " + std::to_string(blue) +
                       ", a: " + std::to_string(alpha) + ">";
  return result;
}
}  // namespace engine
