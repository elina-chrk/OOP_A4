#include "ball.h"

Ball::Ball(double price, const std::string& manufacturer, const BallSpec& spec)
{
	_price = price;
	_manufacturer = manufacturer;
	_spec = spec;
}