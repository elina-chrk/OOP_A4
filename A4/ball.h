#ifndef BALL_H
#define BALL_H

#include <string>

class Ball {
public:
    enum class Colour { ANY, RED, BLUE, GREEN };
    enum class Type { ANY, BASKETBALL, VOLLEYBALL, SOCCER };

    static constexpr std::string_view Colour_str[]{ "Any", "Red", "Blue", "Green" };
    static constexpr std::string_view Type_str[]{ "Any", "Basketball", "Volleyball", "Soccer" };


    Ball(Colour colour, Type type, double price, const std::string& manufacturer);
    Ball();

    Colour get_colour() const { return _colour; }

    Type get_type() const { return _type; }

    double get_price() const { return _price; }
    std::string get_manufacturer() const { return _manufacturer; }

private:
    Colour _colour;
    Type _type;
    double _price;
    std::string _manufacturer;
};

#endif
