#ifndef DONUT_SCN_STEP_HERO_INDIVIUTIL_H
#define DONUT_SCN_STEP_HERO_INDIVIUTIL_H

#include "scn/step/common/Param.h"
#include "scn/step/hero/Hero.h"

#include <hel/math/Vector3.h>

namespace scn { namespace step { namespace hero {

struct NodeAttach { };

struct NodeAttachParam {
    /* 0x00 */ hel::math::Vector3 mOffset;
    /* 0x0C */ hel::math::Vector3 mRotate;
    /* 0x18 */ float mScale;
};

class IndiviUtil {
public:
    static common::Param* Param(const Hero& rHero);
    static float CenterOffset(Kind kind);
    static void InitNodeAttach(NodeAttach& rNodeAttach, Kind kind);
    static bool IsKirby(Kind kind);
    static bool IsMeta(Kind kind);
    static bool IsDedede(Kind kind);
    static bool IsDee(Kind kind);
    static bool CanHover(Kind kind);

    void VacuumAttackerOffset();
private:
    /* 0x0 */ float m_0;
    /* 0x4 */ float m_4;
};

} // hero
} // step
} // scn

#endif
