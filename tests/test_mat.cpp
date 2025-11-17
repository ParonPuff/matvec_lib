#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "../src/type.hpp"

TEST_CASE("mat4 constructors work"){
  matvec::mat4 m{
    1 ,2 ,3 ,4 ,
    5 ,6 ,7 ,8 ,
    9 ,10,11,12,
    13,14,15,16
  };
  
  for(int i=0;i<16;++i){
    REQUIRE_THAT(m.data[i], Catch::Matchers::WithinRel(static_cast<float>(i+1)));
  }

}
TEST_CASE("mat-mat mult"){
  matvec::mat4 m1{
    1 ,2 ,3 ,4 ,
    5 ,6 ,7 ,8 ,
    9 ,10,11,12,
    13,14,15,16
  };

  matvec::mat4 m2{
    1 ,2 ,3 ,4 ,
    5 ,6 ,7 ,8 ,
    9 ,10,11,12,
    13,14,15,16
  };

  matvec::mat4 m_res = m1 * m2;

  matvec::mat4 expected{
    90 ,100,110,120,
    202,228,254,280,
    314,356,398,440,
    426,484,542,600
  };

  for(int i = 0; i<16;++i){
    REQUIRE_THAT(m_res.data[i], Catch::Matchers::WithinRel(expected.data[i]));
  }
}

TEST_CASE("mat-vec mult"){
  matvec::mat4 m{
    1 ,2 ,3 ,4 ,
    5 ,6 ,7 ,8 ,
    9 ,10,11,12,
    13,14,15,16
  };

  matvec::vec4 v(1,2,3,4);

  matvec::vec4 result = m*v;

  REQUIRE_THAT(result.x, Catch::Matchers::WithinRel(90.0f));
  REQUIRE_THAT(result.y, Catch::Matchers::WithinRel(100.0f));
  REQUIRE_THAT(result.z, Catch::Matchers::WithinRel(110.0f));
  REQUIRE_THAT(result.w, Catch::Matchers::WithinRel(120.0f));
}
