#ifndef HEL_COMMON_COLORF_HPP
#define HEL_COMMON_COLORF_HPP

#include <types.h>

namespace hel { namespace common {

class ColorF
{
    // Everything in this class seems to be inlined

public:
    ColorF()
    {
        mR = 0.0f;
        mG = 0.0f;
        mB = 0.0f;
        mA = 0.0f;
    }

    // Gets merged into nw4r::ut::Rect::Rect(const nw4r::ut::Rect&)
    ColorF(const ColorF& color)
    {
        mR = color.mR;
        mG = color.mG;
        mB = color.mB;
        mA = color.mA;
    }
    ColorF(const _GXColor& color);

    // Gets merged into nw4r::ut::Rect::Rect(const nw4r::ut::Rect&)
    void operator=(const ColorF& rOther)
    {
        mR = rOther.mR;
        mG = rOther.mG;
        mB = rOther.mB;
        mA = rOther.mA;
    }
    void operator*=(f32 rOther);
    bool operator!=(const ColorF& rOther);
    _GXColor toGXColorAsNormal() const;

    f32 mR;
    f32 mG;
    f32 mB;
    f32 mA;
};

} // common
} // hel


#endif
