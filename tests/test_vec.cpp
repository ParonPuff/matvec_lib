#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "../src/vec3.hpp"


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

  REQUIRE_THAT(c.x, Catch::Matchers::WithinRel(5.0f));
  REQUIRE_THAT(c.y, Catch::Matchers::WithinRel(7.0f));
  REQUIRE_THAT(c.z, Catch::Matchers::WithinRel(9.0f));
}

