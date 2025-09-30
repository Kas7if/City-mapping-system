#include "city.hpp"
#include <cstring>
#include <cmath>

City::City() {
    name[0] = '\0';
}

City::City(const char* cityName, double x, double y) {
    strncpy(name, cityName, MAX_CITY_NAME - 1);
    name[MAX_CITY_NAME - 1] = '\0';
    location = Point(x, y);
}

City::City(const City &other) : location(other.location) {
    strncpy(name, other.name, MAX_CITY_NAME - 1);
    name[MAX_CITY_NAME - 1] = '\0';
}

double City::distance(const City &other) const {
    return location.distance(other.location);
}

Point City::get_location() const {
    return location;
}

const char* City::get_name() const {
    return name;
}

void City::set_name(const char* cityName) {
    strncpy(name, cityName, MAX_CITY_NAME - 1);
    name[MAX_CITY_NAME - 1] = '\0';
}

void City::set_location(double x, double y) {
    location = Point(x, y);
}
