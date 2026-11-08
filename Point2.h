#ifndef SEGMENT2D_POINT2_H
#define SEGMENT2D_POINT2_H

#include "Vector2.h"

#include <iosfwd>

class Point2 {
public:
    constexpr Point2() noexcept = default;
    constexpr Point2(float x, float y) noexcept : x_(x), y_(y) {}

    constexpr float x() const noexcept { return x_; }
    constexpr float y() const noexcept { return y_; }
    constexpr void setX(float x) noexcept { x_ = x; }
    constexpr void setY(float y) noexcept { y_ = y; }

    constexpr Vector2 operator-(const Point2& other) const noexcept {
        return {x_ - other.x_, y_ - other.y_};
    }
    constexpr Point2 operator+(const Vector2& offset) const noexcept {
        return {x_ + offset.x(), y_ + offset.y()};
    }

    friend std::ostream& operator<<(std::ostream& out, const Point2& point);

private:
    float x_ = 0.0F;
    float y_ = 0.0F;
};

#endif
