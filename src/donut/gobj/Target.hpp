#ifndef DONUT_GOBJ_TARGET_HPP
#define DONUT_GOBJ_TARGET_HPP

#include "gobj/TargetDesc.hpp"
#include "hel/math/Direction3.hpp"

namespace gobj {

class Target {
public:
    Target(const TargetDesc& desc);

    // Gets merged into effect::detail::GenContext::dataType() const
    bool isRightDir() const;
    // Gets merged into mint_wrapNative_helper<bool>::mint_wrapNative_helper(bool)
    void setIsRightDir(bool rightDir);

    f32 getSign() const;
    const hel::math::Direction3 getDirection3() const;

    void invert();

private:
    /* 0x0 */ bool mIsRightDir;
};

} // gobj

#endif
