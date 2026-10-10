#include "scn/step/hero/Guard.hpp"

using namespace scn::step::hero;

namespace {
    const u32 T_ALPHA_TABLE[20] = {
        0xC0,
        0xC0,
        0xA0,
        0x90,
        0x80,
        0x60,
        0x40,
        0x20,
        0x00,
        0x00,
        0x00,
        0x00,
        0x40,
        0x60,
        0x40,
        0x20,
        0x00,
        0x00,
        0x00,
        0x00
    };
}

Guard::Guard(Hero &hero)
    : mHero(&hero)
{
    mEnableGuardState = false;
    mEnableGuardFlash = false;
    mAnimFrame = 0;
}

void Guard::update()
{
    if (mEnableGuardState != false)
    {
        u32 guardFlashCycle = mAnimFrame + 1;
        mAnimFrame = guardFlashCycle;

        if (guardFlashCycle >= 20)
        {
            mAnimFrame = 12;
        }
    }

    mEnableGuardFlash = mEnableGuardState;
}

void Guard::resetAnimFrame()
{
    mAnimFrame = 0;
}

void Guard::setGuard(bool flag)
{
    mEnableGuardState = flag;

    if (mEnableGuardFlash)
    {
        return;
    }

    if (mEnableGuardState != true)
    {
        return;
    }

    resetAnimFrame();
}

bool Guard::isGuard() const
{
    return mEnableGuardState;
}

#pragma peephole off
_GXColor Guard::getColor() const
{
    _GXColor color;
    u32 alpha = 0;

    if (mEnableGuardState != false)
    {
        alpha = T_ALPHA_TABLE[mAnimFrame];
    }

    color.r = 0xFF;
    color.g = 0xFF;
    color.b = 0xFF;
    color.a = alpha;

    return color;
}
