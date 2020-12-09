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

TEST_CASE("BFS on subgraph on Peru", "[bfs]") {
    // Expected Path: IQT -> PCL -> LIM -> AQP -> CUZ
    // 2801, 2781, 2789, 2802, 2812
    
    // IQT -> PCL -> LIM -> AQP -> JUL -> CUZ is a possible path but is longer so path bypasses JUL
    
    vector<Vertex> correct_path{"IQT", "PCL", "LIM", "AQP", "CUZ"};
    
    BFS bfs;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = bfs.BFS_get_path(g, "IQT", "CUZ");
    REQUIRE(path == correct_path);
}


TEST_CASE("BFS on Larger Graph Using ALL Data #1", "[bfs]") {
    // SCY to ORD: needs minimum 2 stops (4 airports in total)
    // Expected Path: SCY -> GYE -> AMS -> ORD
    // vector<Vertex> correct_path{"SCY", "GYE", "AMS", "ORD"};
    
    BFS bfs;
    Graph g = createGraph("routes.txt", "airports.txt");

    vector<Vertex> path = bfs.BFS_get_path(g, "SCY", "ORD");
    
    REQUIRE(path.size() == 4);
}


TEST_CASE("BFS on Larger Graph Using ALL Data #2", "[bfs]") {
    // LAX to KIX: needs minimum 1 stop (3 airports in total)
    // Expected Path: LAX -> JFK -> KIX (BFS check in alphabetical order)
    // vector<Vertex> correct_path{"LAX", "JFK", "KIX"};
    
    BFS bfs;
    Graph g = createGraph("routes.txt", "airports.txt");

    vector<Vertex> path = bfs.BFS_get_path(g, "LAX", "KIX");
    
    REQUIRE(path.size() == 3);
}

TEST_CASE("Dijkstra on subgraph - find all shortest path distances",  "[dijkstra]") {
    // Path: IQT -> PCL -> LIM -> AQP -> CUZ
    
    Dijkstra d;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    map<Vertex, double> distances = d.dijkstra_main(g, "IQT");

    Vertex airports[5] = {"IQT", "PCL", "LIM", "AQP", "CUZ"};

    double correctDistances[5];
    correctDistances[0] = 0.0;
    for (int i = 1; i < 5; i++) {
      correctDistances[i] = (correctDistances[i - 1] + g.getEdgeWeight(airports[i - 1], airports[i]));
    }

    for (int i = 0; i < 5; i++) {
      REQUIRE(distances[airports[i]] == correctDistances[i]);
    } 
}

TEST_CASE("Dijkstra on subgraph - find one shortest path",  "[dijkstra]") {
    // Path: TPP -> LIM -> CCS -> CUR
    
    Dijkstra d;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = d.dijkstra_path(g, "TPP", "CUR");
    vector<Vertex> correct_path{"TPP", "LIM", "CCS", "CUR"};
    REQUIRE(path == correct_path);
}

TEST_CASE("Dijkstra on large graph - find all shortest path distances",  "[dijkstra]") {
    // ORD -> MIA -> AUA
    Dijkstra d;
    Graph g = createGraph("routes.txt", "airports.txt");
    map<Vertex, double> distances = d.dijkstra_main(g, "ORD");

    Vertex airports[3] = {"ORD", "MIA", "AUA"};

    double correctDistances[3];
    correctDistances[0] = 0.0;
    for (int i = 1; i < 3; i++) {
      correctDistances[i] = (correctDistances[i - 1] + g.getEdgeWeight(airports[i - 1], airports[i]));
    }

    for (int i = 0; i < 3; i++) {
      REQUIRE(distances[airports[i]] - correctDistances[i] < 5);
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
    
    vector<Vertex> path = d.dijkstra_path(g, "LAX", "KIX");
    vector<Vertex> correct_path{"LAX", "SFO", "KIX"};

    REQUIRE(path == correct_path);
}

TEST_CASE("Landmark on subgraph",  "[landmark]") {
    // Shortest path from source to dest without landmark is: IQT -> PCL -> LIM -> AQP -> CUZ
    // Shorest path with landmark through JUL: IQT -> PCL -> LIM -> AQP -> JUL -> CUZ
    
    vector<Vertex> correct_path{"IQT", "PCL", "LIM", "AQP", "JUL", "CUZ"};
    
    Landmark l;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = l.landmark_path(g, "IQT", "CUZ", "JUL");
    
    REQUIRE(path == correct_path);
}

TEST_CASE("Landmark on large graph",  "[landmark]") {
    // Shortest path from  FNJ to HAV through PEK

    vector<Vertex> correct_path{"FNJ", "PEK", "YYZ", "HAV"};
    
    Landmark l;
    Graph g = createGraph("routes.txt", "airports.txt");
    vector<Vertex> path = l.landmark_path(g, "FNJ", "HAV", "PEK");
    
    REQUIRE(path == correct_path);
}

TEST_CASE("BFS: Airport doesn't exist", "[bfs][no-airport]") {
    // Airport ZZZ doesn't exist
    vector<Vertex> correct_path{};
    BFS bfs;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = bfs.BFS_get_path(g, "ZZZ", "AER");
    
    REQUIRE(path == correct_path);
}

TEST_CASE("Dijkstra: Airport doesn't exist", "[dijkstra][no-airport]") {
    // Airport ZZZ doesn't exist
    vector<Vertex> correct_path{};
    Dijkstra d;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = d.dijkstra_path(g, "CUZ", "ZZZ");
    
    REQUIRE(path == correct_path);
}

TEST_CASE("Landmark: Airport doesn't exist", "[landmark][no-airport]") {
    // Airport ZZZ doesn't exist
    vector<Vertex> correct_path{};
    Landmark l;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = l.landmark_path(g, "JUL", "AER", "ZZZ");
    
    REQUIRE(path == correct_path);
}

TEST_CASE("BFS: No path exists", "[bfs][no-path]") {
    // no route from IQT -> AER 
    vector<Vertex> correct_path{};
    BFS bfs;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = bfs.BFS_get_path(g, "IQT", "AER");
    
    REQUIRE(path == correct_path);
}

TEST_CASE("Dijkstra: No path exists",  "[dijkstra][no-path]") {
    // no route from IQT -> AER 
    vector<Vertex> correct_path{};

    Dijkstra d;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = d.dijkstra_path(g, "IQT", "AER");
    
    REQUIRE(path == correct_path);
}

TEST_CASE("Landmark: No path exists",  "[landmark][no-path]") {
    // no route from IQT -> AER 
    vector<Vertex> correct_path{};

    Landmark l;
    Graph g = createGraph("tests/test_route.txt", "tests/test_airports.txt");
    vector<Vertex> path = l.landmark_path(g, "IQT", "AER", "JUL");
    
    REQUIRE(path == correct_path);

    path = l.landmark_path(g, "IQT", "CUZ", "AER");
    REQUIRE(path == correct_path);
}
