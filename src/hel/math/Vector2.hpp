#ifndef HEL_MATH_VECTOR2_HPP
#define HEL_MATH_VECTOR2_HPP

#include <nw4r/math.h>

namespace hel { namespace math {
    class Vector3;

    class Vector2 {
    public:

        static Vector2 ZERO;
        static Vector2 ALL_ONE;
        static Vector2 BASIS_X;
        static Vector2 BASIS_Y;

        Vector2();

        //merged into set
        Vector2(float _x, float _y)
            : x(_x)
            , y(_y)
        { }

        //merged into nw4r::VEC2::operator=
        Vector2(const Vector2& rOther);

        ~Vector2() { }

        //merged into nw4r::VEC2::operator=
        void operator=(const Vector2& rOther);
        inline Vector2 operator+(const Vector2& rOther) const;
        Vector2 operator*(float scalar) const;
        void operator-=(const Vector2& rOther);
        void operator+=(const Vector2& rOther);
        void operator*=(f32 scalar);
        void operator/=(f32 scalar);

        f32 length() const;
        f32 squareLength() const;
        f32 dot(const Vector2& rOther) const;
        f32 normalize();
        f32 setLength(f32);
        f32 cos(const Vector2& rOther) const;
        f32 signedAngle(const Vector2& rOther) const;
        void rotate(f32);
        Vector2 getNormalized() const;
        Vector3 toVector3() const;
        Vector3 toVector3XOY() const;
        void set(f32 x, f32 y);

        /* 0x0 */ float x;
        /* 0x4 */ float y;
    };

    // function definitions
    inline Vector2 Vector2::operator+(const Vector2& rOther) const {
        Vector2 v;
        v.x = x + rOther.x;
        v.y = y + rOther.y;
        return v;
    }
} // math

} // hel

#endif
