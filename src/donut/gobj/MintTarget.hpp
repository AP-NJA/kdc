#ifndef DONUT_GOBJ_MINTTARGET_HPP
#define DONUT_GOBJ_MINTTARGET_HPP

#include "gobj/Target.hpp"

namespace gobj {

class MintTarget {
public:
    static void Register(Target& target);
    static void Unregister(Target& target);

    static bool IsRightDir();
    static void SetIsRightDir(bool rightDir);
    
    static f32 GetSign();
    static void Invert();
    static void LoadDirection3();
};

}

#endif
