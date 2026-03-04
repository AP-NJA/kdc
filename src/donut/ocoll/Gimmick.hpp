#ifndef DONUT_OCOLL_GIMMICK_HPP
#define DONUT_OCOLL_GIMMICK_HPP

#include "ocoll/AttackData.hpp"
#include "scn/step/gimmick/block/BlockAttackArg.hpp"

namespace ocoll {

class Manager { };
class AttackRoot { };
class AttackResultGimmick { };

class Gimmick {
public:
    Gimmick(Manager& rManager);
    void chkCollide(AttackRoot& rAttackRoot, AttackResultGimmick& rAttackResultGimmick);
    bool mfIsBreakFire(const AttackData& rAttackData) const;
    bool mfIsBreakFireWeak(const AttackData& rAttackData) const;
    bool mfIsBreakHard(const AttackData& rAttackData) const;
    bool mfIsBreakIce(const AttackData& rAttackData) const;
    bool mfIsBreakGold(const AttackData& rAttackData) const;
private:
    /* 0x0 */ Manager& mManager;
    /* 0x4 */ scn::step::gimmick::block::BlockAttackArg* mBlockAttackArg;
};

}

#endif
