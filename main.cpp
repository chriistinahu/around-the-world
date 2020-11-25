#include <iostream>

#include "loader.cpp"
#include "route.h"
#include "airport.h"


using std::cout;
using std::endl;

int main() {
  loadDataFromRouteFile("routes.txt");
  return 0;
}