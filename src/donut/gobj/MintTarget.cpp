#include "hel/common/PointerWrapper.hpp"
#include "gobj/MintTarget.hpp"

using namespace hel::common;
using namespace hel::math;

// TODO: Remove when implemented
namespace hel { namespace mint {
    class AddOnMathDirection3 {
    public:
        static void Set(const Direction3&);
    };
}}
using namespace hel::mint;

namespace gobj {

namespace {

static PointerWrapper<Target> t_obj = PointerWrapper<Target>();

} // unnamed

void MintTarget::Register(Target& move)
{
    t_obj.set(move);
}

void MintTarget::Unregister(Target& move)
{
    t_obj.unset();
}

bool MintTarget::IsRightDir()
{
    return t_obj->isRightDir();
}

void MintTarget::SetIsRightDir(bool rightDir)
{
    t_obj->setIsRightDir(rightDir);
}

f32 MintTarget::GetSign()
{
    return t_obj->getSign();
}

void MintTarget::Invert()
{
    t_obj->invert();
}

void MintTarget::LoadDirection3()
{
    AddOnMathDirection3::Set(t_obj->getDirection3());
}

} // gobj
