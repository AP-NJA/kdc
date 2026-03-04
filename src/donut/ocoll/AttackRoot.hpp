#ifndef DONUT_OCOLL_ATTACKROOT_HPP
#define DONUT_OCOLL_ATTACKROOT_HPP

#include <types.h>
#include "ocoll/Manager.hpp"
namespace ocoll {

class AttackRoot {
public:

private:
    /* 0x00 */ Manager* mManager;
    /* 0x04 */ STRUCT_FILL(0x34);
    /* 0x38 */ u32 mIndex;
};

}

#endif
