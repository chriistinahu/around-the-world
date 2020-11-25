#pragma once
#include <string>

using std::string;

class Route {
    public:
        Route(string src_id, string dest_id);
        string getSrcAirport();
        string getDestAirport();
    private:
        string src_airport_id_;
        string dest_airport_id_;
        // maybe have two airport objects here??
};

