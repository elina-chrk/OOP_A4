#include "Log.h"
using namespace std;

void Log::add_item(Ball::Colour colour, Ball::Type type, double price, const string& manufacturer) {
    if (_count >= Log::MAX_SIZE)
    {
        return;
    }
    Ball new_item(colour, type, price, manufacturer);

    Ball res = find_item(new_item);
    if (res.get_manufacturer() != "") {
        return;
    }

    _items[_count] = new_item;
    _count++;
}



Ball Log::find_item(const Ball& query) {
    for (size_t i = 0; i < _count; i++) {
        if (query.get_price() != 0 && query.get_price() != _items[i].get_price())
            continue;

        if (query.get_colour() != Ball::Colour::ANY && query.get_colour() != _items[i].get_colour())
            continue;

        if (query.get_type() != Ball::Type::ANY && query.get_type() != _items[i].get_type())
            continue;

        if (query.get_manufacturer() != "" && query.get_manufacturer() != _items[i].get_manufacturer())
            continue;

        return _items[i];
    }

    return Ball();
}
