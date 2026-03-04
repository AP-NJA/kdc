#ifndef DONUT_OCOLL_ATTACKDATA_HPP
#define DONUT_OCOLL_ATTACKDATA_HPP

#include <types.h>
#include "scn/step/ocoll/Flag.hpp"

namespace ocoll {

struct AttackData {
    struct Pow {
        u16 mPower;
        u16 mPowerForDead;
    };

    struct Type {
        u8 mElement;
        u8 mSmashType;
        u8 mSoundType;
    };

    struct Frame {
        u8 mHitStopFrameAttack;
        u8 mHitStopFrameWait;
        u8 mSerialHitFrame;
    };

    struct Chain {
        u8 mChainPhase;
        u8 mChainType;
    };

    struct Option {
        bool mBlockBreakLv0;
        bool mBlockBreakLv1;
        bool mBlockBreakLv2;
        bool mIsSuper;
        bool mDenude;
        bool mIsHitSameTeam;
    };

    /* 0x00 */ Pow mPow;
    /* 0x04 */ Type mType;
    /* 0x08 */ Frame mFrame;
    /* 0x0C */ float mAngle;
    /* 0x10 */ float mAngleRandRange;
    /* 0x14 */ float mSpeed;
    /* 0x18 */ float mPassRate;
    /* 0x1C */ Chain mChain;
    /* 0x20 */ scn::step::ocoll::Flag mFlag;
    /* 0x24 */ Option mOption;
};

}

#endif
