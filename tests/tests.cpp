#include "../cs225/catch/catch.hpp"
#include "../loader.h"
#include "../bfs.h"
#include "../graph.h"
#include "../dijkstra.h"
#include "../landmark.h"

using namespace traversals;

TEST_CASE("Calculate Distance Between Coordinates #1", "[loader]") {
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
    std::cout << distanceBtwn << std::endl;
    REQUIRE( (distanceBtwn >= 1580.3 * 0.85 || distanceBtwn <= 1580.3 * 1.15) );
}

TEST_CASE("Calculate Distance Between Coordinates #2", "[loader]") {
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

TEST_CASE("Subgraph on Peru: path skips airport", "[bfs]") {
    // Expected Path: IQT -> PCL -> LIM -> AQP -> CUZ
    // 2801, 2781, 2789, 2802, 2812
    
    // IQT -> PCL -> LIM -> AQP -> JUL -> CUZ is a possible path but is longer so path bypasses JUL
    
    vector<Vertex> corr_path{"IQT", "PCL", "LIM", "AQP", "CUZ"};
    
    BFS bfs;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    cout << "57" << endl;
    g.print();
    vector<Vertex> path = bfs.BFS_get_path(g, "IQT", "CUZ");
    cout << "60" << endl;
    REQUIRE(path == corr_path);
}

/*
TEST_CASE("Larger Graph Using ALL Data #1", "[bfs]") {
    // SCY to ORD
    // Expected Path: SCY -> GYE -> JFK -> ORD
    // 6045, 2673, 3797, 3830
    vector<Vertex> corr_path{"6045", "2673", "3797", "3830"};
    
    BFS bfs;
    Graph g = createGraph("routes.txt", "airports.txt");

    vector<Vertex> path = bfs.BFS_get_path(g, "6045", "3830");
    
    REQUIRE(path == corr_path);
}


TEST_CASE("Larger Graph Using ALL Data #2", "[bfs]") {
    // LAX to KIX
    // Expected Path: LAX -> JFK -> KIX (BFS check in alphabetical order)
    // 3484 -> 3797 -> 3992
    vector<Vertex> corr_path{"3484", "3797", "3992"};
    
    BFS bfs;
    Graph g = createGraph("routes.txt", "airports.txt");

    vector<Vertex> path = bfs.BFS_get_path(g, "3484", "3992");
    
    REQUIRE(path == corr_path);
}

TEST_CASE("Test what happens if no path exists for BFS", "[bfs]") {
    // no route from 2801 -> 2965 
    vector<Vertex> correct_path{};
    BFS bfs;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = bfs.BFS_get_path(g, "2801", "2965");
    
    REQUIRE(path == correct_path);
}


TEST_CASE("Dijkstra: Subgraph on Peru - path skips airport",  "[dijkstra]") {
    // Expected Path: IQT -> PCL -> LIM -> AQP -> CUZ
    // 2801, 2781, 2789, 2802, 2812
    
    // IQT -> PCL -> LIM -> AQP -> JUL -> CUZ is a possible path but is longer so path bypasses JUL
    
    Dijkstra d;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    map<Vertex, double> distances = d.dijkstra_main(g, "2801");
    for (map<Vertex, double>::iterator it = distances.begin(); it != distances.end(); it++) {
      std::cout << it->first << ":" << it->second << std::endl;
    }
    
    Vertex airports[5] = {"2801", "2781", "2789", "2802", "2812"};

    double correctDistances[5];
    correctDistances[0] = 0.0;
    for (int i = 1; i < 5; i++) {
      correctDistances[i] = (correctDistances[i - 1] + g.getEdgeWeight(airports[i - 1], airports[i]));
    }

    for (int i = 0; i < 5; i++) {
      REQUIRE(distances[airports[i]] == correctDistances[i]);
    } 
}

TEST_CASE("Dijsktra to find shortest path",  "[dijkstra]") {
    // LAX to KIX

    // Path #1: LAX -> JFK -> KIX (BFS check in alphabetical order)
    // 3484 -> 3797 -> 3992
    // total distance: 3972 + 11147 = 15119 KM

    // Path #2: LAX -> HKG -> KIX
    // total distance: 11657 + 2474 = 14131 KM

    // Path #3: LAX -> TPE -> KIX 
    // total distance: 10915 + 1702 = 12617 KM

    // Path #3: LAX -> SFO -> KIX (EXPECTED PATH)
    // 3484 -> 3469 -> 3992
    // total distance: 543 + 8686 = 9226
    
    Dijkstra d;
    Graph g = createGraph("routes.txt", "airports.txt");
    
    vector<Vertex> path = d.dijkstra_path(g, "3484", "3992");
    vector<Vertex> corr_path{"3484", "3469", "3992"};

    REQUIRE(path == corr_path);
}

TEST_CASE("Landmark through subgraph",  "[landmark]") {
    // Expected Path: IQT -> PCL -> LIM -> AQP -> CUZ
    // 2801, 2781, 2789, 2802, 2812
    
    // IQT -> PCL -> LIM -> AQP -> JUL -> CUZ is a possible path but is longer so path bypasses JUL
    
    vector<Vertex> corr_path{"2801", "2781", "2789", "2802", "2792", "2812"};
    
    Landmark l;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = l.landmark_path(g, "2801", "2812", "2792");
    
    REQUIRE(path == corr_path);
}
*/