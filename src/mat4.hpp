#pragma once
#include "./vec4.hpp"
namespace matvec{
  struct mat4{
    float data[16];

    constexpr mat4() : data{0} {}
    // NOTE: may cause issues
    constexpr mat4(
        float m00,float m01,float m02,float m03,
        float m10,float m11,float m12,float m13,
        float m20,float m21,float m22,float m23,
        float m30,float m31,float m32,float m33
    ) : data{
         m00, m01, m02, m03,
         m10, m11, m12, m13,
         m20, m21, m22, m23,
         m30, m31, m32, m33
    } {}

    // i know this is inefficient but i'm to lazy to research the good algorithm
    inline mat4 operator*(const mat4& other){
      mat4 result;

      for (int col= 0; col<4; ++col){
        for(int row = 0; row <4; ++row){
          float sum = 0.0f;
          for (int k = 0; k<4; ++k){
            sum += data[k*4+row] * other.data[col*4+k];
          }

          result.data[col*4+row]=sum;
        }
      }

      return result;
    }

    // maybe a bit inellegant
    inline vec4 operator*(const vec4& v){
      return vec4(
          data[0] * v.x + data[4] * v.y + data[8]  * v.z + data[12] * v.w,
          data[1] * v.x + data[5] * v.y + data[9]  * v.z + data[13] * v.w,
          data[2] * v.x + data[6] * v.y + data[10] * v.z + data[14] * v.w,
          data[3] * v.x + data[7] * v.y + data[11] * v.z + data[15] * v.w
      );
    }
  };
}
