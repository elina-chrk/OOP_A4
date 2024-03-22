#ifndef BALL_H
#define BALL_H

#include <string>
#include "BallSpec.h"

class Ball {
public:
    Ball() 
        : _price{ 0.0 }, _manufacturer{ "" }, _spec{ } { }

    Ball(double price, const std::string& manufacturer, const BallSpec& spec);

    double get_price() const { return _price; }
    std::string get_manufacturer() const { return _manufacturer; }
    const BallSpec& get_spec() const { return _spec; }

private:
    double _price;
    std::string _manufacturer;
    BallSpec _spec;
};


#endif
