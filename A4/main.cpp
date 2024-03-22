#include <iostream>
#include <iomanip>
#include <cassert>
#include "ball.h"
#include "Log.h"

using namespace std;

string colourToString(BallSpec::Colour colour) {
    switch (colour) {
    case BallSpec::Colour::RED:
        return "Red";
    case BallSpec::Colour::BLUE:
        return "Blue";
    case BallSpec::Colour::GREEN:
        return "Green";
    default:
        return "Unknown Colour";
    }
}

string typeToString(BallSpec::Type type) {
    switch (type) {
    case BallSpec::Type::BASKETBALL:
        return "Basketball";
    case BallSpec::Type::VOLLEYBALL:
        return "Volleyball";
    case BallSpec::Type::SOCCER:
        return "Soccer";
    default:
        return "Unknown Type";
    }
}

Ball max_price(const Log& log) {
    Ball max_item;
    double max_price = 0.0;
    bool found_max = false;

    for (size_t i = 0; i < log.get_count(); ++i) {
        Ball current_item = log.get_item(i);
        double current_price = current_item.get_price();

        if (!found_max || current_price > max_price) {
            max_price = current_price;
            max_item = current_item;
            found_max = true;
        }
    }

    return max_item;
}

int main() {
    Log log;

    BallSpec spec(BallSpec::Type::SOCCER, BallSpec::Colour::BLUE);

    log.add_item(10.99, "Kero", spec);
    log.add_item(15.99, "Miba", spec);
    log.add_item(17.99, "Romet Vintage M brown", spec);
    log.add_item(20.99, "Romet Vintage M green", spec);

    Ball found_ball = log.find_item(spec);

    if (found_ball.get_manufacturer() != "") {
        cout << "Found ball matching the query specifications:\n";
        cout << "Price: " << found_ball.get_price() << endl;
        cout << "Manufacturer: " << found_ball.get_manufacturer() << endl;
    }
    else {
        cout << "No ball found matching the query specifications.\n";
    }

    Ball found_ball_spec = log.find_item(spec);
    Ball found_ball_query = log.find_item(Ball(0.0, "", spec));

    Ball expected_ball(10.99, "Kero", spec);

    // assertions to check if the found Ball matches the expected one
    assert(found_ball_spec.get_price() == expected_ball.get_price());
    assert(found_ball_spec.get_manufacturer() == expected_ball.get_manufacturer());
    assert(found_ball_spec.get_spec().get_type() == expected_ball.get_spec().get_type());
    assert(found_ball_spec.get_spec().get_colour() == expected_ball.get_spec().get_colour());

    assert(found_ball_query.get_price() == expected_ball.get_price());
    assert(found_ball_query.get_manufacturer() == expected_ball.get_manufacturer());
    assert(found_ball_query.get_spec().get_type() == expected_ball.get_spec().get_type());
    assert(found_ball_query.get_spec().get_colour() == expected_ball.get_spec().get_colour());

    cout << "All assertions passed successfully.\n";

    return 0;
}
