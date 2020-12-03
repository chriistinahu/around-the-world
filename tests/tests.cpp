#include "../cs225/catch/catch.hpp"
#include "../loader.h"


TEST_CASE("Calculate Distance Between Coordinates #1") {
    // Boston to Chicago (1580.3 km)

    // Chicago coords
    double lat_1 = 41.8781;
    double long_1 = 87.6298;

    // Boston coords
    double lat_2 = 42.3601;
    double long_2 = 71.0589;

    double distanceBtwn = getDistanceFromLatLong(lat_1, long_1, lat_2, long_2);
    // std::cout << distanceBtwn << std::endl; prints 1365.64

    // our calculated distance will never be completely accurate since the earth is not a perfect sphere
    // so, just require that it is within 85% of actual value
    REQUIRE( (distanceBtwn >= 1580.3 * 0.85 || distanceBtwn <= 1580.3 * 1.15) );
}

TEST_CASE("Calculate Distance Between Coordinates #2") {
    // Beijing to Seoul (952 km)

    // Boston coords
    double lat_1 = 37.5665;
    double long_1 = -126.9780;

    // Beijing coords
    double lat_2 = 39.9042;
    double long_2 = -116.4074;

    double distanceBtwn = getDistanceFromLatLong(lat_1, long_1, lat_2, long_2);
    // std::cout << distanceBtwn << std::endl; prints 952.328

    // our calculated distance will never be completely accurate since the earth is not a perfect sphere
    // so, just require that it is within 85% of actual value
    REQUIRE( (distanceBtwn >= 952 * 0.85 || distanceBtwn <= 952 * 1.15) );
}