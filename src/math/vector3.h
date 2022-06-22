#ifndef ENGINE_VECTOR3_H
#define ENGINE_VECTOR3_H

class Vector3 {
 private:
  float x, y, z;

 public:
  Vector3() = default;
  Vector3(float x_in, float y_in, float z_in);
  float& operator[](int i);
  const float& operator[](int i) const;
  float magnitude() const;
};

#endif  // ENGINE_VECTOR3_H
