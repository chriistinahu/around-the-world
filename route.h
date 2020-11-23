#pragma once
#include <string>

using std::string;

class Route {
    public:
        Route(string src_id, string dest_id, int num_stops);
        string getSrcAirport();
        string getDestAirport();
        int getNumStops();
    private:
        string src_airport_id_;
        string dest_airport_id_;
        int num_stops_;
        // maybe have two airport objects here??
};

