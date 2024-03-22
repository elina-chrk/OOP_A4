#ifndef BALLSPEC_H
#define BALLSPEC_H

#include <string>

class BallSpec {
public:
    enum class Colour { ANY, RED, BLUE, GREEN };
    enum class Type { ANY, BASKETBALL, VOLLEYBALL, SOCCER };

    static constexpr std::string_view Colour_str[]{ "Any", "Red", "Blue", "Green" };
    static constexpr std::string_view Type_str[]{ "Any", "Basketball", "Volleyball", "Soccer" };

    BallSpec()
        : _type{ Type::ANY }, _colour { Colour::ANY }
    { }

    BallSpec(Type type, Colour colour)
        : _type{ type }
        , _colour{ colour }
    {
        // std::cout << "BicycleSpec(..) called\n";
    }

    Type get_type() const { return _type; }
    Colour get_colour() const { return _colour; }

private:
    Type _type;
    Colour _colour;
};

#endif