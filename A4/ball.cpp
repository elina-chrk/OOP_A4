#include "ball.h"

Ball::Ball(Colour colour, Type type, double price, const std::string& manufacturer)
    : _colour(colour), _type(type), _price(price), _manufacturer(manufacturer) {}

Ball::Ball() : _colour(Colour::ANY), _type(Type::ANY), _price(0.0), _manufacturer("") {}