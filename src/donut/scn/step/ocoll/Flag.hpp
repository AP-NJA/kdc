#ifndef DONUT_SCN_STEP_OCOLL_FLAG_HPP
#define DONUT_SCN_STEP_OCOLL_FLAG_HPP

namespace scn { namespace step { namespace ocoll {
    enum Flag {
        OCOLL_FLAG_NORMAL           = 1 << 0,
        OCOLL_FLAG_SUPER            = 1 << 1,
        OCOLL_FLAG_GIMMICK_ONLY     = 1 << 2,
    };
}}}

#endif
