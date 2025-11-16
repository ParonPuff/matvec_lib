namespace gfx{
  struct vec3{
    float x,y,z;

    vec3() : x(0),y(0),z(0) {}
    vec3(float x,float y,float z) : x(x),y(y),z(z) {}
    vec3(const vec4& v) : x(v.x),y(v.y),z(v.z) {}
  };
}
