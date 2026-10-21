#include "gobj/TargetDesc.hpp"

using namespace gobj;

// https://decomp.me/scratch/UaZO9
const TargetDesc TargetDesc::Create(bool rightDir)
{
    TargetDesc desc;
    desc.mIsRightDir = rightDir;
    return desc;
}
