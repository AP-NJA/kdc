#include "hel/common/Color.hpp"

using namespace hel::common;

Color Color::BLACK   = Color(0, 0, 0, 255);
Color Color::GRAY    = Color(128, 128, 128, 255);
Color Color::WHITE   = Color(255, 255, 255, 255);
Color Color::RED     = Color(255, 0, 0, 255);
Color Color::GREEN   = Color(0, 255, 0, 255);
Color Color::BLUE    = Color(0, 0, 255, 255);
Color Color::YELLOW  = Color(255, 255, 0, 255);
Color Color::MAGENTA = Color(255, 0, 255, 255);
Color Color::CYAN    = Color(0, 255, 255, 255);

// .sbss isn't 100% due to 4 bytes of extra padding for some reason, but otherwise matches

Color::Color(u8 r, u8 g, u8 b, u8 a)
{
    mR = r;
    mG = g;
    mB = b;
    mA = a;
}
