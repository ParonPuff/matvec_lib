#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include "../gfx::vec4.hpp"
#include "../gfx::vec3.hpp"

TEST_CASE("vec3 constructors work"){
  vec3 a;
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  REQUIRE(a.z == 0.0f);

  vec3 b(1,2,3);
  REQUIRE(b.x == 1);
  REQUIRE(b.y == 2);
  REQUIRE(b.z == 3);
}

TEST_CASE("vec3 addition"){
  vec3 a(1,2,3);
  vec3 b(4,5,6);
  vec3 c = a+b;

  REQUIRE(c.x == APPROX(5))
  REQUIRE(c.y == APPROX(7))
  REQUIRE(c.z == APPROX(9))
}

