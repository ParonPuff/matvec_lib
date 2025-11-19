#pragma once
#include "vec3.hpp"
namespace matvec{
  struct vec4{
    float x,y,z,w;

    vec4() : x(0),y(0),z(0),w(0) {}
    vec4(float x,float y, float z, float w=1.0f) 
      : x(x),y(y),z(z),w(w) {}
    vec4(const vec3& v, float w=1.0f) 
      : x(v.x),y(v.y),z(v.z),w(w) {}

    inline explicit operator vec3() const {
      return vec3(x,y,z);
    }

    inline vec4 operator+(const vec4& other) {
      return vec4(
          x+other.x,
          y+other.y,
          z+other.z,
          w+other.w
      );
    }

    inline vec4 operator*(float s){
      return vec4(
          x*s,
          y*s,
          z*s,
          w*s
      );
    }

  };
}
