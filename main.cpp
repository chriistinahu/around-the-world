#include <iostream>

#include "loader.cpp"
#include "route.h"
#include "airport.h"


using std::cout;
using std::endl;

int main() {
  double lat_1 = 41.8781;
  double long_1 = 87.6298;

  // Boston coords

  // beijing 39.9042° N, 116.4074° E
  // 10,597
  double lat_2 = 39.9042;
  double long_2 = -116.4074;

  double distanceBtwn = getDistanceFromLatLong(lat_1, long_1, lat_2, long_2);
  cout << distanceBtwn << endl;
  return 0;
}