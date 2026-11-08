#include "Vector2.h"

#include <cmath>
#include <ostream>

float Vector2::norm() const noexcept {
    return std::sqrt(x_ * x_ + y_ * y_);
}

std::ostream& operator<<(std::ostream& out, const Vector2& vector) {
    return out << '{' << vector.x_ << ", " << vector.y_ << '}';
}
