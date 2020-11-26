#include "../cs225/catch/catch.hpp"
#include "../loader.cpp"

TEST_CASE("Confirm distance calculation works") {
    // Boston to Chicago (1580.3 km)

    // Chicago coords
    double lat_1 = 41.8781;
    double long_1 = 87.6298;

    // Boston coords
    double lat_2 = 42.3601;
    double long_2 = 71.0589;

    double distanceBtwn = getDistanceFromLatLong(lat_1, long_1, lat_2, long_2);

    REQUIRE(distanceBtwn == 1580.3);

}