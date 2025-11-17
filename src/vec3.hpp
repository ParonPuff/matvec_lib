#ifndef VEC3
#define VEC3

// #include "vec4.hpp"
struct vec3{
  float x,y,z;

  vec3() : x(0),y(0),z(0) {}
  vec3(float x,float y,float z) : x(x),y(y),z(z) {}
    // vec3(const vec4& v) : x(v.x),y(v.y),z(v.z) {}
  inline vec3 operator+(const vec3& other) {
    return vec3(
        x+other.x,
        y+other.y,
        z+other.z
    );
  }

  inline vec3 operator*(float s){
    return vec3(
        x*s,
        y*s,
        z*s
    );
  }

};

#endif
