#include "route.h"

Route::Route(string src_id, string dest_id, int num_stops) {
    src_airport_id_ = src_id;
    dest_airport_id_ = dest_id;
    num_stops_ = num_stops;
}

string Route::getSrcAirport() {
    return src_airport_id_;
}

string Route::getDestAirport() {
    return dest_airport_id_;
}