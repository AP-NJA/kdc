#ifndef DONUT_APP_RANDOM_HPP
#define DONUT_APP_RANDOM_HPP

#include <types.h>

namespace hel { namespace math {
    class Random;
}};

namespace app {
    namespace Random {
        bool RandBool(f32 max);
        int Rand(int max);
        int Rand(int min, int max);
        f32 RandF(f32 min, f32 max);
        u32 RandU32(u32 max);
        u32 RandU32(u32 min, u32 max);
        f32 RandF32(f32 min, f32 max);
        f32 RandNF();
        f32 RandAF();
        void Reset();
        hel::math::Random& Obj();
    }
}

#endif
