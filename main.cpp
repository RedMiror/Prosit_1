#include "Point2.h"
#include "Segment2.h"
#include "Vector2.h"

#include <cstdlib>

int main() {
    const Point2 p1(0.0F, 0.0F);
    const Point2 p2(1.0F, 2.0F);

    const Vector2 v1(1.0F, 1.0F);
    const Vector2 v2(2.0F, 4.0F);

    const Segment2 s1(p1, v1);
    const Segment2 s2(p2, v2);

    // Like the original C main, this sample constructs two segments and
    // exits successfully without printing anything.
    (void)s1;
    (void)s2;
    return EXIT_SUCCESS;
}
