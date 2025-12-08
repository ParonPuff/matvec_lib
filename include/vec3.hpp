#pragma once
#include <cmath>
namespace matvec {
struct vec3 {
  float x, y, z;

  vec3() : x(0), y(0), z(0) {}
  vec3(float x, float y, float z) : x(x), y(y), z(z) {}

  inline vec3 operator+(const vec3 &other) {
    return vec3(x + other.x, y + other.y, z + other.z);
  }
  inline vec3 operator-(const vec3 &other) {
    return vec3(x - other.x, y - other.y, z - other.z);
  }

  inline vec3 operator*(float s) { return vec3(x * s, y * s, z * s); }

  inline vec3 operator/(float s) { return vec3(x, y, z) * (1 / s); }

  inline float length() {
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
  }

  inline vec3 normalized() { return vec3(x, y, z) / length(); }

  // inline void operator*=(float s){
  //   this = this * s;
  // }
};
} // namespace matvec
