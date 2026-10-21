#ifndef DONUT_GOBJ_TARGETDESC_HPP
#define DONUT_GOBJ_TARGETDESC_HPP

namespace gobj {

struct TargetDesc {
public:
    static const TargetDesc Create(bool rightDir);

    /* 0x0 */ bool mIsRightDir;
};

} // gobj

#endif
