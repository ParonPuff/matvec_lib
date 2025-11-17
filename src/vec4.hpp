#ifndef VEC4
#define VEC4
#include "vec3.hpp"
namespace gfx{
  using namespace gfx;
  struct vec4{
    float x,y,z,w;

    vec4() : x(0),y(0),z(0),w(0) {}
    vec4(float x,float y, float z, float w) 
      : x(x),y(y),z(z),w(w) {}
    vec4(const vec3& v, float w=1.0f) 
      : x(v.x),y(v.y),z(v.z),w(w) {}
  };
}
#endif
