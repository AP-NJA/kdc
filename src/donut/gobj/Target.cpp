#include "gobj/Target.hpp"

using namespace gobj;
using namespace hel::math;

Target::Target(const TargetDesc& desc)
    : mIsRightDir(desc.mIsRightDir)
{ }

bool Target::isRightDir() const
{
    return mIsRightDir;
}

void Target::setIsRightDir(bool rightDir)
{
    mIsRightDir = rightDir;
}

f32 Target::getSign() const
{
    return mIsRightDir ? 1.0f : -1.0f;
}

// https://decomp.me/scratch/d4fT5
const Direction3 Target::getDirection3() const
{
    Direction3* axis = mIsRightDir
        ? &Direction3::FRONT_TO_RIGHT
        : &Direction3::FRONT_TO_LEFT;

    Direction3 outAxis = Direction3(); // inlined constructor?
    outAxis.mFront = axis->mFront;
    outAxis.mUp = axis->mUp;
    outAxis.mLeft = axis->mLeft;
    return outAxis;
}

void Target::invert()
{
    mIsRightDir = !mIsRightDir;
}
