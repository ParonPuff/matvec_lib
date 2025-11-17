#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "../src/type.hpp"

TEST_CASE("mat4 constructors work"){
  matvec::mat4 m([
    1 ,2 ,3 ,4 ,
    5 ,6 ,7 ,8 ,
    9 ,10,11,12,
    13,14,15,16
  ]);

  REQUIRE(m.data[0]  == 1);
  REQUIRE(m.data[1]  == 2);
  REQUIRE(m.data[2]  == 3);
  REQUIRE(m.data[3]  == 4);

  REQUIRE(m.data[4]  == 5);
  REQUIRE(m.data[5]  == 6);
  REQUIRE(m.data[6]  == 7);
  REQUIRE(m.data[7]  == 8);

  REQUIRE(m.data[8]  == 9);
  REQUIRE(m.data[9]  == 10);
  REQUIRE(m.data[10] == 11);
  REQUIRE(m.data[11] == 12);

  REQUIRE(m.data[12] == 13);
  REQUIRE(m.data[13] == 14);
  REQUIRE(m.data[15] == 15);
  REQUIRE(m.data[15] == 16);

}
TEST_CASE("mat-mat mult"){
  matvec::mat4 m1([
    1 ,2 ,3 ,4 ,
    5 ,6 ,7 ,8 ,
    9 ,10,11,12,
    13,14,15,16
  ]);

  matvec::mat4 m2([
    1 ,2 ,3 ,4 ,
    5 ,6 ,7 ,8 ,
    9 ,10,11,12,
    13,14,15,16
  ]);

  matvec::mat4 m_res = m1 * m2;

  matvec::mat4 expected([
    90 ,100,110,120,
    202,228,254,280,
    314,156,398,440,
    426,184,542,600
  ]);

  REQUIRE_THAT(m_res.data, Catch::Matchers::Equals(expected.data));
}
TEST_CASE("mat-vec mult"){
  matvec::mat4 m([
    1 ,2 ,3 ,4 ,
    5 ,6 ,7 ,8 ,
    9 ,10,11,12,
    13,14,15,16
  ]);

  matvec::vec4 v(1,2,3,4);

  matvec::vec4 result = m*v;
  std::vector<float> expected{30,70,110,150};

  REQUIRE_THAT(expected,Catch::Matchers::Equals(std::vector<float>{result.x,result.y,result.z,result.w}));
}
