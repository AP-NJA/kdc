#ifndef HEL_MATH_RANDOM_HPP
#define HEL_MATH_RANDOM_HPP

#include <nw4r/math.h>

namespace hel  { namespace math {
    class Random {
    public:
        class Seed {
        public:
            static Seed Default();

            int _0;
            int _4;
            int _8;
            int _C;
        };
    private:
        u32 randCoreU32();
        f32 randCoreF32();
    public:
        Random(const Seed&);
        bool randBool(float);
        int rand(int);
        int rand(int, int);
        float randF(float, float);
        s32 randS32(s32);
        s32 randS32(s32, s32);
        u32 randU32(u32);
        s32 randU32(u32, u32);
        f32 randF32(f32, f32);
        f32 randNF();
        f32 randAF();

        int operator()(int seed);

        Seed mSeed;
    };

} //namespace math

} //namespace hel
#endif
