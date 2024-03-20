#ifndef LOG_H
#define LOG_H

#include "ball.h"  // Include the necessary header file for Ball class

class Log
{
public:
    // Initializes the log
    void init() { _count = 0; }

    // Returns the current number of abstraction objects
    size_t get_count() const { return _count; }

    // Returns stored abstraction object by its index or default object if index is invalid
    Ball get_item(size_t i) const { return (i < _count) ? _items[i] : Ball{}; }

    // From passed property values, creates and adds new abstraction object in an array _items
    void add_item(Ball::Colour colour, Ball::Type type, double price, const std::string& manufacturer);

    // Looks for a matching abstraction object and returns the first found or default object
    Ball find_item(const Ball& query);

private:
    // The maximum number of abstraction objects that can be stored
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Ball _items[MAX_SIZE];

    // The number of currently stored abstraction objects in the array _items
    size_t _count;
};

#endif
