#include "airport.h"

Airport::Airport(string airport_id, string name, string city, double latitude, double longitude) {
  airport_id_ = airport_id;
  name_ = name;
  city_ = city;
  latitude_ = latitude;
  longitude_ = longitude;
}

string Airport::getID() {
  return airport_id_;
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