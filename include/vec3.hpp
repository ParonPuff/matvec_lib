#pragma once
#include <cmath>
namespace matvec {
struct vec3 {
  float x, y, z;

  vec3() : x(0), y(0), z(0) {}
  vec3(float x, float y, float z) : x(x), y(y), z(z) {}

  inline vec3 operator+(const vec3 &other) const {
    return vec3(x + other.x, y + other.y, z + other.z);
  }
  inline vec3 operator-(const vec3 &other) const {
    return vec3(x - other.x, y - other.y, z - other.z);
  }

  inline vec3 operator*(float s) const { return vec3(x * s, y * s, z * s); }

  inline vec3 operator/(float s) const { return vec3(x, y, z) * (1 / s); }

  inline float length() const { return std::sqrt(x * x + y * y + z * z); }

  inline vec3 normalized() const {
    float len = length();
    return (len == 0) ? vec3(0, 0, 0) : (*this) / len;
  }

  inline vec3 cross(vec3 other) const {
    return vec3(y * other.z - z * other.y, z * other.x - x * other.z,
                x * other.y - y * other.x);
  }
  inline float dot(vec3 other) const {
    return x * other.x + y * other.y + z * other.z;
  }
  // inline void operator*=(float s){
  //   this = this * s;
  // }
};
} // namespace matvec
