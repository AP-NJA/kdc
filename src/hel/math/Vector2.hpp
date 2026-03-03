#ifndef HEL_MATH_VECTOR2_HPP
#define HEL_MATH_VECTOR2_HPP

#include <nw4r/math.h>

namespace hel { namespace math {
    class Vector2 {
    public:
        Vector2();
        Vector2(float _x, float _y)
            : x(_x)
            , y(_y)
        { }

        ~Vector2() { }

        float x;
        float y;
    };
} // math

} // hel

#endif
