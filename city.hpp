#ifndef CITY_CLASS_HEADER_INCLUDED
#define CITY_CLASS_HEADER_INCLUDED

#include "point.hpp"
#include <cstring>

const size_t MAX_CITY_NAME = 100; // Adjust as needed

class City {
    Point location;
    char name[MAX_CITY_NAME];

public:
    City();
    City(const char* cityName, double x, double y);
    City(const City &other);

    double distance(const City &other) const;
    Point get_location() const;
    const char* get_name() const;

    void set_name(const char* cityName);
    void set_location(double x, double y);
};

#endif
