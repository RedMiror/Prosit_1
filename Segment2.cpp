#include "Segment2.h"

float Segment2::length() const noexcept {
    return direction_.norm();
}

IntersectionStatus Segment2::intersect(const Segment2& other,
                                       Point2& intersectionPoint) const noexcept {
    const Vector2 displacement = other.origin_ - origin_;
    const float determinant = direction_.cross(other.direction_);

    if (determinant != 0.0F) {
        const float alongThis = displacement.cross(other.direction_) / determinant;
        const float alongOther = displacement.cross(direction_) / determinant;
        if (alongThis >= 0.0F && alongThis <= 1.0F &&
            alongOther >= 0.0F && alongOther <= 1.0F) {
            intersectionPoint = origin_ + direction_ * alongThis;
            return IntersectionStatus::Point;
        }
        return IntersectionStatus::NonIntersecting;
    }

    // Parallel segments are collinear when the displacement has zero cross
    // product with this segment's direction.
    if (displacement.cross(direction_) != 0.0F) {
        return IntersectionStatus::ParallelNonIntersecting;
    }

    const float thisSquaredLength = direction_.dot(direction_);
    const float otherSquaredLength = other.direction_.dot(other.direction_);

    // Handle point-segments explicitly; the original C code divided by zero
    // for a zero direction and could return an uninitialized status.
    if (thisSquaredLength == 0.0F && otherSquaredLength == 0.0F) {
        if (origin_.x() == other.origin_.x() && origin_.y() == other.origin_.y()) {
            intersectionPoint = origin_;
            return IntersectionStatus::ColinearIntersecting;
        }
        return IntersectionStatus::ColinearNonIntersecting;
    }
    if (thisSquaredLength == 0.0F) {
        const Vector2 fromOther = origin_ - other.origin_;
        if (fromOther.cross(other.direction_) != 0.0F) {
            return IntersectionStatus::ColinearNonIntersecting;
        }
        const float t = fromOther.dot(other.direction_) / otherSquaredLength;
        if (t >= 0.0F && t <= 1.0F) {
            intersectionPoint = origin_;
            return IntersectionStatus::ColinearIntersecting;
        }
        return IntersectionStatus::ColinearNonIntersecting;
    }

    const float firstProjection = displacement.dot(direction_) / thisSquaredLength;
    const float secondProjection = firstProjection + other.direction_.dot(direction_) / thisSquaredLength;
    const float overlapStart = (firstProjection < secondProjection) ? firstProjection : secondProjection;
    const float overlapEnd = (firstProjection < secondProjection) ? secondProjection : firstProjection;
    const float clippedStart = overlapStart > 0.0F ? overlapStart : 0.0F;
    const float clippedEnd = overlapEnd < 1.0F ? overlapEnd : 1.0F;

    if (clippedStart <= clippedEnd) {
        intersectionPoint = origin_ + direction_ * clippedStart;
        return IntersectionStatus::ColinearIntersecting;
    }
    return IntersectionStatus::ColinearNonIntersecting;
}

const char* toString(IntersectionStatus status) noexcept {
    switch (status) {
    case IntersectionStatus::Point: return "POINT";
    case IntersectionStatus::ColinearIntersecting: return "COLINEAR_INTERSECTING";
    case IntersectionStatus::ColinearNonIntersecting: return "COLINEAR_NON_INTERSECTING";
    case IntersectionStatus::ParallelNonIntersecting: return "PARALLEL_NON_INTERSECTING";
    case IntersectionStatus::NonIntersecting: return "NON_INTERSECTING";
    }
    return "UNKNOWN";
}
