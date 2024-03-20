#include <iostream>
#include "ball.h"
#include "Log.h"

using namespace std;

// Function to convert Ball::Colour enum to string
string colourToString(Ball::Colour colour) {
    switch (colour) {
    case Ball::Colour::RED:
        return "Red";
    case Ball::Colour::BLUE:
        return "Blue";
    case Ball::Colour::GREEN:
        return "Green";
    default:
        return "Unknown Colour";
    }
}

// Function to convert Ball::Type enum to string
string typeToString(Ball::Type type) {
    switch (type) {
    case Ball::Type::BASKETBALL:
        return "Basketball";
    case Ball::Type::VOLLEYBALL:
        return "Volleyball";
    case Ball::Type::SOCCER:
        return "Soccer";
    default:
        return "Unknown Type";
    }
}


void show(const Ball& item) {
    cout << "Colour: " << colourToString(item.get_colour()) << ", "
        << "Type: " << typeToString(item.get_type()) << ", "
        << "Price: " << item.get_price() << ", "
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
    log.init();

    log.add_item(Ball::Colour::RED, Ball::Type::BASKETBALL, 67.88, "Vivo");
    log.add_item(Ball::Colour::BLUE, Ball::Type::VOLLEYBALL, 455.88, "Kero");

    Ball qry(Ball::Colour::BLUE, Ball::Type::VOLLEYBALL, 455.88, "Kero");
    show(log.find_item(qry));

    qry = Ball(Ball::Colour::RED, Ball::Type::ANY, 0, "");
    show(log.find_item(qry));

    qry = Ball(Ball::Colour::ANY, Ball::Type::ANY, 0, "Miba");
    show(log.find_item(qry));


    // show(max_price(log));

    return 0;
}