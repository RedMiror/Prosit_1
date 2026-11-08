#ifndef SEGMENT2D_VECTOR2_H
#define SEGMENT2D_VECTOR2_H

#include <iosfwd>

class Vector2 {
public:
    constexpr Vector2() noexcept = default;
    constexpr Vector2(float x, float y) noexcept : x_(x), y_(y) {}

    constexpr float x() const noexcept { return x_; }
    constexpr float y() const noexcept { return y_; }
    constexpr void setX(float x) noexcept { x_ = x; }
    constexpr void setY(float y) noexcept { y_ = y; }

    float norm() const noexcept;
    constexpr float dot(const Vector2& other) const noexcept {
        return x_ * other.x_ + y_ * other.y_;
    }
    constexpr float cross(const Vector2& other) const noexcept {
        return x_ * other.y_ - y_ * other.x_;
    }

    constexpr Vector2 operator*(float scalar) const noexcept {
        return {scalar * x_, scalar * y_};
    }
    constexpr Vector2 operator-() const noexcept { return {-x_, -y_}; }

    friend std::ostream& operator<<(std::ostream& out, const Vector2& vector);

private:
    float x_ = 0.0F;
    float y_ = 0.0F;
};

#endif
