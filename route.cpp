#include "route.h"

Route::Route(string src_id, string dest_id) {
    src_airport_id_ = src_id;
    dest_airport_id_ = dest_id;
}

string Route::getSrcAirport() {
    return src_airport_id_;
}

string Route::getDestAirport() {
    return dest_airport_id_;
}