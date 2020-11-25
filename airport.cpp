#include "airport.h"

Airport::Airport(int airport_id, string name, string city, double latitude, double longitude) {
  airport_id_ = airport_id;
  name_ = name;
  city_ = city;
  latitude_ = latitude;
  longitude_ = longitude;
}

string Airport::getName() {
  return name_;
}

string Airport::getCity() {
  return city_;
}

double Airport::getLatitude() {
  return latitude_;
}

double Airport::getLongitude() {
  return longitude_;
}