#include "airport.h";
#include "route.h";

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<Airport> loadDataFromAirportFile(const string& filename) {
    ifstream text(filename);
    vector<Airport> out;

    if (text.is_open()) {
      std::istream_iterator<std::string> iter(text);
      while (!text.eof()) {
        out.push_back(*iter);
        ++iter;
		}
	}

}

vector<Route> loadDataFromRouteFile(const string& filename) {
    ifstream text(filename);
	vector<std::string> out;

	if (text.is_open()) {
		istream_iterator<string> iter(text);
		while (!text.eof()) {
			out.push_back(*iter);
            std::cout << out;
			++iter;
		}
	}

	return out;

}