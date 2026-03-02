#include "scn/step/hero/IndiviUtil.h"
#include "param/JITParam.h"

using namespace scn::step::hero;

scn::step::common::Param* IndiviUtil::Param(const Hero& rHero) {
    switch (rHero.kind()) {
        case KIND_KIRBY_1:
        case KIND_KIRBY_2:
        case KIND_KIRBY_3:
        case KIND_KIRBY_4:
            return rHero.param()->indiviKirby();
        case KIND_META:
            return rHero.param()->indiviMeta();
        case KIND_DEDEDE:
            return rHero.param()->indiviDedede();
        case KIND_DEE:
            return rHero.param()->indiviDee();
        default:
            return rHero.param()->indiviKirby();
    }
}

void IndiviUtil::InitNodeAttach(NodeAttach& rNodeAttach, Kind kind) {
    // not decompiled
}

float IndiviUtil::CenterOffset(Kind kind) {
    switch (kind) {
        case KIND_KIRBY_1:
        case KIND_KIRBY_2:
        case KIND_KIRBY_3:
        case KIND_KIRBY_4:
            return 0.5f;
        case KIND_META:     return 0.5f;
        case KIND_DEDEDE:   return 0.75f;
        case KIND_DEE:      return 0.5f;
        default:            return 0.5f;
    }
}

void IndiviUtil::VacuumAttackerOffset() {
    m_0 = 0.0f;
    m_4 = 0.75f;
}

// https://decomp.me/scratch/HpNqE
bool IndiviUtil::IsKirby(Kind kind) {
    return kind < KIND_META;
}

bool IndiviUtil::IsMeta(Kind kind) {
    return kind == KIND_META;
}

bool IndiviUtil::IsDedede(Kind kind) {
    return kind == KIND_DEDEDE;
}

bool IndiviUtil::IsDee(Kind kind) {
    return kind == KIND_DEE;
}

bool IndiviUtil::CanHover(Kind kind) {
    if (IsKirby(kind)) {
        return true;
    }

    return IsDedede(kind);
}
