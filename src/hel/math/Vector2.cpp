#pragma peephole off
#include <hel/math/Vector2.hpp>
#include <hel/math/Vector3.hpp>

//TODO: Move define to a better place
#define NW4R_ASSERT
#include <nw4r/NW4RAssert.hpp>
#include <nw4r/math/math_arithmetic.h>

using hel::math::Vector2;
using hel::math::Vector3;

Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
Vector2 Vector2::ALL_ONE = Vector2(1.0f, 1.0f);
Vector2 Vector2::BASIS_X = Vector2(1.0f, 0.0f);
Vector2 Vector2::BASIS_Y = Vector2(0.0f, 1.0f);

f32 Vector2::length() const {
    f32 sqLength = squareLength();

    if (!(sqLength >= 0.0f)) {
        NW4RWarningMessage_FileLine("arithmetic.h", 627, "FSqrt: Input is out of the domain.");
    }

    if (sqLength <= 0.0f) {
        return 0.0f;
    }

    return sqLength * nw4r::math::FrSqrt(sqLength);
}

f32 Vector2::squareLength() const {
    return dot(*this);
}

void Vector2::operator=(const Vector2& rOther) {
    x = rOther.x;
    y = rOther.y;
}

f32 Vector2::dot(const Vector2& rOther) const {
    return x * rOther.x + y * rOther.y;
}

void Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
}

f32 Vector2::normalize() {
    f32 lengthVal = length();
    if (lengthVal == 0.0f) {
        return lengthVal;
    }
    *this /= lengthVal;

    if (1.0f <= x) {
        x = 1.0f;
        y = 0.0f;
    }
    else if (x <= -1.0f) {
        x = -1.0f;
        y = 0.0f;
    }
    else if (1.0f <= y) {
        y = 1.0f;
        x = 0.0f;
    }
    else if (y <= -1.0f) {
        y = -1.0f;
        x = 0.0f;
    }
    return lengthVal;
}

void Vector2::operator/=(float scalar) {
    *this *= 1.0f / scalar;
}

f32 Vector2::setLength(f32 arg1) {
    f32 lengthVar = length();

    if (lengthVar == 0.0f) {
        *this = ZERO;
    } else {
        *this *= (arg1 / lengthVar);
    }
    return lengthVar;
}

f32 Vector2::cos(const Vector2& rOther) const {
    f32 lengthVar = length() *  rOther.length();
    if (lengthVar == 0.0f) {
        return 0.0f;
    }
    f32 cos = dot(rOther) / lengthVar;

    if (1.0f < cos) {
        return 1.0f;
    }
    else if (cos < -1.0f) {
        return -1.0f;
    }
    return cos;
}

f32 Vector2::signedAngle(const Vector2& rOther) const {
    f32 lengthVar = length() * rOther.length();
    if (lengthVar < 0.0000099999997f) {
        return 0.0f;
    }
    f32 cos = dot(rOther) / lengthVar;

    if (cos > 1.0f) {
        return 0.0f;
    }
    else if (cos < -1.0f) {
        return 3.1415927f;
    }

    if (this->x * rOther.y - this->y * rOther.x < 0.0f) {
        return -acosf(cos);
    } else {
        return acosf(cos);
    }
    return cos;
}

//https://decomp.me/scratch/YhKOO
void Vector2::rotate(f32 angle) {
    float sin = sinf(angle);
    float cos = cosf(angle);
    Vector2 rotatedAngle(x * cos - y * sin, x * sin + y * cos);
    set(rotatedAngle.x, rotatedAngle.y);
}

void Vector2::set(f32 _x, f32 _y) {
    x  = _x;
    y = _y;
}

Vector2 Vector2::getNormalized() const {
    Vector2 vec(*this);
    vec.normalize();
    return vec;
}

void Vector2::operator+=(const Vector2& rOther) {
    x += rOther.x;
    y += rOther.y;
}

Vector3 Vector2::toVector3() const {
    return Vector3(x, y, 0.0f);
}

Vector3 Vector2::toVector3XOY() const {
    return Vector3(x, 0.0f, y);
}

//Can't use initializer list due to y being set before x
Vector2::Vector2() {
    y = 0.0f;
    x = 0.0f;
}

void Vector2::operator-=(const Vector2& rOther) {
    x -= rOther.x;
    y -= rOther.y;
}

//https://decomp.me/scratch/dwoS1
Vector2 Vector2::operator*(float scalar) const {
    Vector2 v(*this);
    v *= scalar;
    return v;
}


Vector2::Vector2(const Vector2& rOther)
    : x(rOther.x)
    , y(rOther.y)
{ }
