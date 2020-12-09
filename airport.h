#pragma once

#include <string>

using std::string;

/**
 * The Airport class represents an airport that has the following information:
 * 3 letter IATA ID, airport name, city, longitude, and latitude.
 */
class Airport {
  private:
    string airport_id_;
    string name_;
    string city_;
    double latitude_;
    double longitude_;

  public:
    Airport(string airport_id, string name, string city, double latitude, double longitude);
    string getID();
    string getName();
    string getCity();
    double getLatitude();
    double getLongitude();
};