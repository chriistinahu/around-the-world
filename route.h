#pragma once
#include <string>

using std::string;

class Route {
    /**
     * The Route class represents a route, and contains the source and destination airport IATA codes
     */
    public:
        Route(string src_id, string dest_id);
        string getSrcAirport();
        string getDestAirport();
    private:
        string src_airport_id_;
        string dest_airport_id_;
};

