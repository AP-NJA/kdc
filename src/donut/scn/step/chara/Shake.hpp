#ifndef DONUT_SCN_STEP_CHARA_SHAKE_HPP
#define DONUT_SCN_STEP_CHARA_SHAKE_HPP

#include <types.h>
#include "hel/math/Vector2.hpp"

/* clang-format off */
namespace scn { namespace step { namespace chara {

// RtDL DX's Basil exposes this enum
enum ShakeKind
{
    ShakeKind_SSS = 0,
    ShakeKind_SS,
    ShakeKind_S,
    ShakeKind_M,
    ShakeKind_L,
    ShakeKind_LL,
    ShakeKind_Invalid
};

class Shake {
public:
    Shake();

    // Gets merged into ocoll::Gimmick::Gimmick(ocoll::Manager&)
    void request(ShakeKind kind);
    // UNUSED, 0x14 bytes
    void clear();
    void update();
    hel::math::Vector2 getOffset() const;

private:
    /* 0x0 */ ShakeKind mKind;
    /* 0x4 */ u32 mFrame;
};

}}}

#endif
