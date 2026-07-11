#ifndef HEL_MATH_RANDOM_HPP
#define HEL_MATH_RANDOM_HPP

#include <nw4r/math.h>

namespace hel  { namespace math {
    class Random {
    public:
        class Seed {
        public:
            static Seed Default();

            /* 0x0 */ s32 m_0;
            /* 0x4 */ s32 m_4;
            /* 0x8 */ s32 m_8;
            /* 0xC */ u32 m_C;
        };

        Random(const Seed& rSeed);

        // NOTE: Is merged into rand(int)
        int operator()(int arg1);

        bool randBool(f32 max);
        int rand(int max);
        int rand(int min, int max);
        f32 randF(f32 min, f32 max);
        s32 randS32(s32 max);
        s32 randS32(s32 min, s32 max);
        u32 randU32(u32 max);
        u32 randU32(u32 min, u32 max);
        f32 randF32(f32 min, f32 max);
        f32 randNF();
        f32 randAF();
private:
        u32 randCoreU32();
        f32 randCoreF32();

        /* 0x0 */ Seed mSeed;
    };

} //namespace math

} //namespace hel
#endif
