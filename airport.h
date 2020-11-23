#pragma once

#include <string>

using std::string;

class Airport {
  private:
    int airport_id_;
    string name_;
    double latitude_;
    double longitude_;

  public:
    Airport(int airport_id_, string name_, double latitude_, double longitude_);
    string getName();
    string getLatitude();
    string getLongitude();
};