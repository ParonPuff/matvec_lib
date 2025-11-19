#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "../include/types.hpp"

TEST_CASE("vec3 constructors work"){
  matvec::vec3 a;
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  REQUIRE(a.z == 0.0f);

  matvec::vec3 b(1,2,3);
  REQUIRE(b.x == 1);
  REQUIRE(b.y == 2);
  REQUIRE(b.z == 3);
}

TEST_CASE("vec3 addition"){
  matvec::vec3 a(1,2,3);
  matvec::vec3 b(4,5,6);
  matvec::vec3 c = a+b;

  REQUIRE_THAT(c.x, Catch::Matchers::WithinRel(5.0f));
  REQUIRE_THAT(c.y, Catch::Matchers::WithinRel(7.0f));
  REQUIRE_THAT(c.z, Catch::Matchers::WithinRel(9.0f));
}

TEST_CASE("vec4 constructors work"){
  matvec::vec4 a;
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  REQUIRE(a.z == 0.0f);

  matvec::vec4 b(1,2,3);
  REQUIRE(b.x == 1);
  REQUIRE(b.y == 2);
  REQUIRE(b.z == 3);
  REQUIRE(b.w == 1.0f);

  matvec::vec4 c(1,2,3,4);
  REQUIRE(c.x == 1);
  REQUIRE(c.y == 2);
  REQUIRE(c.z == 3);
  REQUIRE(c.w == 4);
}

TEST_CASE("vec4 addition"){
  matvec::vec4 a(1,2,3,4);
  matvec::vec4 b(5,6,7,8);
  matvec::vec4 c = a+b;

  REQUIRE_THAT(c.x, Catch::Matchers::WithinRel(6.0f));
  REQUIRE_THAT(c.y, Catch::Matchers::WithinRel(8.0f));
  REQUIRE_THAT(c.z, Catch::Matchers::WithinRel(10.0f));
  REQUIRE_THAT(c.w, Catch::Matchers::WithinRel(12.0f));
}

TEST_CASE("vec3 to vec4"){
  matvec::vec3 a;
  matvec::vec4 a_con(a);
  REQUIRE(a_con.x == 0.0f);
  REQUIRE(a_con.y == 0.0f);
  REQUIRE(a_con.z == 0.0f);
  REQUIRE(a_con.w == 1.0f);

  matvec::vec3 b(1,2,3);
  matvec::vec4 b_con(b,4);
  REQUIRE(b_con.x == 1);
  REQUIRE(b_con.y == 2);
  REQUIRE(b_con.z == 3);
  REQUIRE(b_con.w == 4);
}

TEST_CASE("vec4 to vec3"){
  matvec::vec4 a;
  matvec::vec3 a_con(a);
  REQUIRE(a_con.x == 0.0f);
  REQUIRE(a_con.y == 0.0f);
  REQUIRE(a_con.z == 0.0f);

  matvec::vec4 b(1,2,3,4);
  matvec::vec3 b_con(b);
  REQUIRE(b_con.x == 1);
  REQUIRE(b_con.y == 2);
  REQUIRE(b_con.z == 3);
}
