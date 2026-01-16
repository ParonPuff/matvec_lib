#pragma once
#include <cmath>
namespace matvec {
struct vec2 {
  float x, y;

  vec2() : x(0), y(0) {}
  vec2(float x, float y) : x(x), y(y) {}

  inline vec2 operator+(const vec2 &other) const {
    return vec2(x + other.x, y + other.y);
  }
  inline vec2 operator-(const vec2 &other) const {
    return vec2(x - other.x, y - other.y);
  }

  inline vec2 operator*(float s) const { return vec2(x * s, y * s); }

  inline vec2 operator/(float s) const { return vec2(x, y) * (1 / s); }

  inline float length() const { return std::sqrt(x * x + y * y); }

  inline vec2 normalized() const {
    float len = length();
    return (len == 0) ? vec2(0, 0) : (*this) / len;
  }

  // inline vec2 cross(vec2 other) const {
  //   return vec2(
  //     y * other.z - z * other.y,
  //     z * other.x - x * other.z,
  //     x * other.y - y * other.x
  //   );
  // }
  // inline float dot(vec2 other) const {
  //   return x * other.x + y * other.y + z * other.z;
  // }
  // inline void operator*=(float s){
  //   this = this * s;
  // }
};
} // namespace matvec
