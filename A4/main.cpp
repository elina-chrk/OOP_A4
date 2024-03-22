#include <iostream>
#include <iomanip>
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

void show(const Ball& item) {
    auto is = item.get_spec();

    cout << "Colour: " << colourToString(is.get_colour()) << ", "
        << "Type: " << typeToString(is.get_type()) << ", "
        << "Price: " << fixed << setprecision(2) << item.get_price() << ", "
        << "Manufacturer: " << item.get_manufacturer() << endl;
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

    // Adding some example Balls to the log
    BallSpec spec1(BallSpec::Type::SOCCER, BallSpec::Colour::RED);
    log.add_item(10.99, "Kero", spec1);

    BallSpec spec2(BallSpec::Type::BASKETBALL, BallSpec::Colour::BLUE);
    log.add_item(15.99, "Miba", spec2);

    BallSpec spec_beach(BallSpec::Type::SOCCER, BallSpec::Colour::BLUE);
    log.add_item(15.99, "Romet Vintage M brown", spec_beach);
    log.add_item(17.99, "Romet Vintage M green", spec_beach);

    // Querying for a Ball with specific specifications
    BallSpec query_spec(BallSpec::Type::SOCCER, BallSpec::Colour::BLUE);
    Ball found_ball = log.find_item(Ball(0.0, "", query_spec));

    if (found_ball.get_manufacturer() != "") {
        cout << "Found ball matching the query specifications:\n";
        show(found_ball);
    } else {
        cout << "No ball found matching the query specifications.\n";
    }

    // Testing with another set of query values
    BallSpec query_spec2(BallSpec::Type::BASKETBALL, BallSpec::Colour::RED);
    found_ball = log.find_item(Ball(0.0, "", query_spec2));

    if (found_ball.get_manufacturer() != "") {
        cout << "Found ball matching the second query specifications:\n";
        show(found_ball);
    } else {
        cout << "No ball found matching the second query specifications.\n";
    }

    return 0;
}
