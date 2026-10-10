#ifndef HEL_COMMON_COLOR_HPP
#define HEL_COMMON_COLOR_HPP

#include <types.h>

namespace hel { namespace common {

class Color
{
public:
    static Color BLACK;
    static Color GRAY;
    static Color WHITE;
    static Color RED;
    static Color GREEN;
    static Color BLUE;
    static Color YELLOW;
    static Color MAGENTA;
    static Color CYAN;

    // Gets merged into nw4r::ut::Color::Color(const nw4r::ut::Color&)
    Color(const Color& color);
    Color(u8 r, u8 g, u8 b, u8 a);

    // void* toShortString() const; // UNUSED, 0x24 bytes long; most likely returns FixedString

    u8 mR;
    u8 mG;
    u8 mB;
    u8 mA;
};

} // common
} // hel


#endif
