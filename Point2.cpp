#include "Point2.h"

#include <ostream>

std::ostream& operator<<(std::ostream& out, const Point2& point) {
    return out << '{' << point.x_ << ", " << point.y_ << '}';
}
