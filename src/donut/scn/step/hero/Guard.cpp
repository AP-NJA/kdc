#include "scn/step/hero/Guard.hpp"

using namespace scn::step::hero;

Guard::Guard(Hero &hero)
    : mHero(&hero)
{
    mEnableGuardState = false;
    mEnableGuardFlash = false;
    mGuardFlashCycle = 0;
}

void Guard::update()
{
    if (mEnableGuardState != false)
    {
        u32 guardFlashCycle = mGuardFlashCycle + 1;
        mGuardFlashCycle = guardFlashCycle;

        if (guardFlashCycle >= 20)
        {
            mGuardFlashCycle = 12;
        }
    }

    mEnableGuardFlash = mEnableGuardState;
}

void Guard::setGuard(bool flag)
{
    mEnableGuardState = flag;

    if (mEnableGuardFlash != false)
    {
        return;
    }

    if (mEnableGuardState != true)
    {
        return;
    }

    mGuardFlashCycle = 0;
}

#pragma peephole off
_GXColor Guard::getColor() const
{
    _GXColor color;
    u32 alpha = 0;

    if (mEnableGuardState != false)
    {
        alpha = T_ALPHA_TABLE[mGuardFlashCycle];
    }

    color.r = 0xFF;
    color.g = 0xFF;
    color.b = 0xFF;
    color.a = alpha;

    return color;
}
