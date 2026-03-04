#ifndef DONUT_SCN_STEP_GIMMICK_BLOCK_BLOCKMANAGER_HPP
#define DONUT_SCN_STEP_GIMMICK_BLOCK_BLOCKMANAGER_HPP

#include "scn/step/gimmick/block/BlockAttackArg.hpp"

using namespace scn::step::gimmick::block;

namespace scn { namespace step { namespace gimmick { namespace block {

class BlockManager {
public:
    void attack(const BlockAttackArg& rBlockAttackArg);
};

}}}}

#endif
