#include "math/Vector2.hpp"
#pragma peephole off
#include <math/Math.hpp>
#include <geo/Rect.hpp>

using hel::geo::Rect;
using hel::math::Vector2;

Rect::Rect()
    : mMinY(0.0f)
    , mMaxY(0.0f)
    , mMinX(0.0f)
    , mMaxX(0.0f)
{
    set(0.0f, 0.0f, 0.0f, 0.0f);
}

Rect::Rect(float minY, float maxY, float minX, float maxX)
    : mMinY(0.0f)
    , mMaxY(0.0f)
    , mMinX(0.0f)
    , mMaxX(0.0f)
{
    set(minY, maxY, minX, maxX);
}

Rect::Rect(const Rect& rOther)
    : mMinY(0.0f)
    , mMaxY(0.0f)
    , mMinX(0.0f)
    , mMaxX(0.0f)
{
    set(rOther.mMinY, rOther.mMaxY, rOther.mMinX, rOther.mMaxX);
}

Rect::~Rect() { }

void Rect::trans(float x, float y) {
    mMinY += y;
    mMaxY += y;
    mMinX += x;
    mMaxX += x;
}

const Vector2 Rect::getCenter() const {
    return Vector2(
        0.5f * (mMinX + mMaxX),
        0.5f * (mMinY + mMaxY)
    );
}

float Rect::getWidth() const {
    return math::Math::Abs<float>(mMaxX - mMinX);
}

float Rect::getHeight() const {
    return math::Math::Abs<float>(mMaxY - mMinY);
}

bool Rect::isInclude(float x, float y) const {
    bool within = false;

    if (mMinX <= x && x <= mMaxX && mMaxY <= y && y <= mMinY) {
        within = true;
    }

    return within;
}

bool Rect::isIntersect(const Rect& rOther) const {
    if (mMinX > rOther.mMaxX) {
        return false;
    }

    if (mMaxX < rOther.mMinX) {
        return false;
    }

    if (mMinY < rOther.mMaxY) {
        return false;
    }

    if (mMaxY > rOther.mMinY) {
        return false;
    }

    return true;
}

void Rect::adjustAspectShrink(float arg1) {
    Vector2 center = getCenter();
    float width = getWidth();
    float height = getHeight();
    height *= arg1;

    if (height > width) {
        width *= 1.0f / arg1;
        mMaxY = -(0.5f * width - center.y);
        mMinY = 0.5f * width + center.y;
    } else {
        mMinX = -(0.5f * height - center.x);
        mMaxX = 0.5f * height + center.x;
    }
}

void Rect::transInternal(const Rect& rOther) {
    if (getWidth() > rOther.getWidth()) {
        mMinX = rOther.mMinX;
        mMaxX = rOther.mMaxX;
    }

    if (getHeight() > rOther.getHeight()) {
        mMinY = rOther.mMinY;
        mMaxY = rOther.mMaxY;
    }

    float diff = mMinY - rOther.mMinY;

    if (diff > 0.0f) {
        mMinY -= diff;
        mMaxY -= diff;
    }

    diff = mMaxY - rOther.mMaxY;

    if (diff < 0.0f) {
        mMinY -= diff;
        mMaxY -= diff;
    }

    diff = mMinX - rOther.mMinX;

    if (diff < 0.0f) {
        mMinX -= diff;
        mMaxX -= diff;
    }

    diff = mMaxX - rOther.mMaxX;

    if (diff > 0.0f) {
        mMinX -= diff;
        mMaxX -= diff;
    }
}

void Rect::margeUnion(const Rect& rOther) {
    if (rOther.mMinX < mMinX) {
        mMinX = rOther.mMinX;
    }

    if (rOther.mMaxX > mMaxX) {
        mMaxX = rOther.mMaxX;
    }

    if (rOther.mMaxY < mMaxY) {
        mMaxY = rOther.mMaxY;
    }

    if (rOther.mMinY > mMinY) {
        mMinY = rOther.mMinY;
    }
}
