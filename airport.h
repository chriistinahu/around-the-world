#pragma once

#include <string>

using std::string;

class Airport {
  private:
    string airport_id_;
    string name_;
    string city_;
    double latitude_;
    double longitude_;

  public:
    Airport(string airport_id, string name, string city, double latitude, double longitude);
    string getName();
    string getCity();
    double getLatitude();
    double getLongitude();
};