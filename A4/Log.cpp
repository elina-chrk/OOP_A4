#include "Log.h"
using namespace std;

void Log::add_item(double price, const string& manufacturer, const BallSpec& spec) {
    if (_count >= Log::MAX_SIZE) {
        return;
    }
    Ball new_item( price, manufacturer, spec);
    Ball res = find_item(new_item);
    if (res.get_manufacturer() != "") {
        return;
    }
    _items[_count] = new_item;
    _count++;
}

Ball Log::find_item(const Ball& query) {
    auto query_spec{ query.get_spec() };
    for (size_t i = 0; i < _count; i++) {
        if (query.get_price() != 0 && query.get_price() != _items[i].get_price())
            continue;

        if (query.get_manufacturer() != "" && query.get_manufacturer() != _items[i].get_manufacturer())
            continue;

        auto item_spec{ _items[i].get_spec() };

        if (query_spec.get_type() != BallSpec::Type::ANY
            && query_spec.get_type() != item_spec.get_type())
            continue;

        if (query_spec.get_colour() != BallSpec::Colour::ANY
            && query_spec.get_colour() != item_spec.get_colour())
            continue;

        return _items[i];
    }

    return Ball();
}
