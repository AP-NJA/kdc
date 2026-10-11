#ifndef DONUT_SCN_STEP_CHARA_INVINCIBLE_HPP
#define DONUT_SCN_STEP_CHARA_INVINCIBLE_HPP

#include <types.h>

/* clang-format off */
namespace scn { namespace step { namespace chara {

const u32 T_ALPHA_ANIM_TABLE[10] = {
    0xF0,
    0x50,
    0xA0,
    0x14,
    0x8C,
    0x0A,
    0x78,
    0x00,
    0x64,
    0x00
};

class Invincible
{
public:
    Invincible();
    void update();
    bool isInvincible() const;
    void set(u32 frames);
    void clear();
    void setPerm();
    void unsetMighty();
    bool isMighty() const;
    u32 getFlashAlpha() const;
    void updateFrame();
public:
    /* 0x00 */ u32 mInvincibleFrames;
    /* 0x04 */ u32 mFlashCycle;
    /* 0x08 */ bool mUsingIntangibleMove;
    /* 0x09 */ bool mIsCandyActive;
};

}}}

/* clang-format on */

#endif
