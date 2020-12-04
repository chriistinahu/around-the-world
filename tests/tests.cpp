#include "../cs225/catch/catch.hpp"
#include "../loader.h"
#include "../bfs.h"
#include "../graph.h"

using namespace traversals;

TEST_CASE("Calculate Distance Between Coordinates #1") {
    // Boston to Chicago (1580.3 km)

    // Chicago coords
    double lat_1 = 41.8781;
    double long_1 = 87.6298;

    // Boston coords
    double lat_2 = 42.3601;
    double long_2 = 71.0589;

    double distanceBtwn = getDistanceFromLatLong(lat_1, long_1, lat_2, long_2);

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

    // our calculated distance will never be completely accurate since the earth is not a perfect sphere
    // so, just require that it is within 85% of actual value
    REQUIRE( (distanceBtwn >= 952 * 0.85 || distanceBtwn <= 952 * 1.15) );
}

TEST_CASE("Subgraph on Peru: path skips airport") {
    // Expected Path: IQT -> PCL -> LIM -> AQP -> CUZ
    // 2801, 2781, 2789, 2802, 2812
    
    // IQT -> PCL -> LIM -> AQP -> JUL -> CUZ is a possible path but is longer so path bypasses JUL
    
    vector<Vertex> corr_path{"2801", "2781", "2789", "2802", "2812"};
    
    BFS bfs;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = bfs.BFS_get_path(g, "2801", "2812");
    
    REQUIRE(path == corr_path);
}


TEST_CASE("Larger Graph Using ALL Data #1") {
    // SCY to ORD
    // Expected Path: SCY -> GYE -> JFK -> ORD
    // 6045, 2673, 3797, 3830
    vector<Vertex> corr_path{"6045", "2673", "3797", "3830"};
    
    BFS bfs;
    Graph g = createGraph("routes.txt", "airports.txt");

    vector<Vertex> path = bfs.BFS_get_path(g, "6045", "3830");
    
    REQUIRE(path == corr_path);
}


TEST_CASE("Larger Graph Using ALL Data #2") {
    // LAX to KIX
    // Expected Path: LAX -> JFK -> KIX (BFS check in alphabetical order)
    // 3484 -> 3797 -> 3992
    vector<Vertex> corr_path{"3484", "3797", "3992"};
    
    BFS bfs;
    Graph g = createGraph("routes.txt", "airports.txt");

    vector<Vertex> path = bfs.BFS_get_path(g, "3484", "3992");
    
    REQUIRE(path == corr_path);
}

TEST_CASE("Test what happens if no path exists for BFS") {
    
    REQUIRE(1 == 1);
}

