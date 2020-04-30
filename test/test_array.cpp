#include <catch2/catch.hpp>

#include "array.hpp"

namespace cousar {
TEST_CASE("Cousar Array construction", "[Cousar, Array]") {
    Array<double> a;
    a.resize(2, 2);
    REQUIRE(a.rows() == 2);
    REQUIRE(a.cols() == 2);
    REQUIRE(a.size() == 2 * 2);
    REQUIRE(a.capacity() == 2 * 2 + a.resize_chunk());

    Array<double> b(a);
    REQUIRE(b.rows() == 2);
    REQUIRE(b.cols() == 2);
    REQUIRE(b.size() == 2 * 2);
    REQUIRE(b.capacity() == 2 * 2 + a.resize_chunk());
}
}  // namespace cousar
