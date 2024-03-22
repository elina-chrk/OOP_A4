#ifndef LOG_H
#define LOG_H

#include "Ball.h"

class Log {
public:
    Log() : _count{ 0 } {}

    size_t get_count() const { return _count; }

    Ball get_item(size_t i) const { return (i < _count) ? _items[i] : Ball{}; }

    void add_item(double price, const std::string& manufacturer, const BallSpec& spec);

    Ball find_item(const Ball& query);

    Ball find_item(const BallSpec& spec_query);

private:
    static const size_t MAX_SIZE{ 10 };
    Ball _items[MAX_SIZE];
    size_t _count;
};

#endif