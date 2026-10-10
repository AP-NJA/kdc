#ifndef DONUT_SCN_STEP_HERO_GUARD_HPP
#define DONUT_SCN_STEP_HERO_GUARD_HPP

#include <GX/GXTypes.h>
#include <types.h>

#include "scn/step/hero/Hero.hpp"

/* clang-format off */
namespace scn { namespace step { namespace hero {

class Guard
{
public:
    Guard(Hero &hero);
    // Gets merged into scn::IScene::~IScene()
    ~Guard();

    void update();
    // Gets merged into seq::SequenceGrandMenu::onChildSequenceEnd(seq::ISequence&)
    void resetAnimFrame();
    void setGuard(bool flag);
    // Gets merged into pause::ButtonPanel::isEnable() const
    bool isGuard() const;
    _GXColor getColor() const;
private:
    /* 0x00 */ Hero *mHero;
    /* 0x04 */ bool mEnableGuardState;
    /* 0x05 */ bool mEnableGuardFlash;
    /* 0x08 */ u32 mAnimFrame;
};

}}}

#endif
