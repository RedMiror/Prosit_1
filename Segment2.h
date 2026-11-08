#ifndef SEGMENT2D_SEGMENT2_H
#define SEGMENT2D_SEGMENT2_H

#include "Point2.h"
#include "Vector2.h"

enum class IntersectionStatus {
    Point,
    ColinearIntersecting,
    ColinearNonIntersecting,
    ParallelNonIntersecting,
    NonIntersecting
};

class Segment2 {
public:
    constexpr Segment2() noexcept = default;
    constexpr Segment2(Point2 origin, Vector2 direction) noexcept
        : origin_(origin), direction_(direction) {}

    constexpr Point2 origin() const noexcept { return origin_; }
    constexpr Vector2 direction() const noexcept { return direction_; }
    constexpr Point2 end() const noexcept { return origin_ + direction_; }
    float length() const noexcept;

    // On an intersection, intersectionPoint receives the crossing point or
    // the first point of the collinear overlap along this segment.
    IntersectionStatus intersect(const Segment2& other, Point2& intersectionPoint) const noexcept;

private:
    Point2 origin_{};
    Vector2 direction_{};
};

const char* toString(IntersectionStatus status) noexcept;

#endif
