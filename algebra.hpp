namespace gfx{
  inline vec3 operator+(const vec3& a,const vec3& b) {
    return new vec4(
        a.x+b.x,
        a.y+b.y,
        a.z+b.z
    );
  }

  inline vec3 operator*(float s, const vec3& v){
    return new vec4(
        v.x*s,
        v.y*s,
        v.z*s
    );
  }

  inline vec4 operator+(const vec4& a,const vec4& b) {
    return new vec4(
        a.x+b.x,
        a.y+b.y,
        a.z+b.z,
        a.w+b.w
    );
  }

  inline vec4 operator*(float s, const vec4& v){
    return new vec4(
        v.x*s,
        v.y*s,
        v.z*s,
        v.w*s;
    );
  }

  // inline mat4 operator*(const mat4& a, const mat4& b) {
  //   return new
  // }
  inline const float* ptr(const mat4& m) {return m.data;}
}
