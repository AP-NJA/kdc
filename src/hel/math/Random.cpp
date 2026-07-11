#pragma peephole off
#include <hel/math/Random.hpp>

using hel::math::Random;

Random::Seed Random::Seed::Default() {
    Seed defaultSeed;
    defaultSeed.m_0 = 0x75BCD15;
    defaultSeed.m_4 = 0x159A55E5;
    defaultSeed.m_8 = 0x1F123BB5;
    defaultSeed.m_C = 0x5491333;
    return defaultSeed;
}

Random::Random(const Random::Seed& rSeed) : mSeed(rSeed) { }

bool Random::randBool(f32 max) {
    if (max == 0.0f) {
        return false;
    }

    return randCoreF32() <= max;
}

int Random::rand(int max) {
    return randS32(max);
}

int Random::rand(int min, int max) {
    return randS32(min, max);
}

f32 Random::randF(f32 min, f32 max) {
    return randF32(min, max);
}

s32 Random::randS32(s32 max) {
    s32 coreRand = randCoreU32();
    coreRand &= 0x7FFFFFFF;
    s32 coreDivided = coreRand / max;
    return coreRand - coreDivided * max;
}

s32 Random::randS32(s32 min, s32 max) {
    return min + randS32(max - min);
}

u32 Random::randU32(u32 max) {
    u32 coreRand = randCoreU32();
    u32 coreDivided = coreRand / max;
    return coreRand - coreDivided * max;
}

u32 Random::randU32(u32 min, u32 max) {
    u32 coreRand = randCoreU32();

    u32 paramDifference = max - min;
    u32 coreDivided = (coreRand / (paramDifference));
    return min + (coreRand - (coreDivided * paramDifference));
}

f32 Random::randF32(f32 min, f32 max) {
    f32 coreRand = randCoreF32();

    f32 firstValue = max - min;
    return firstValue * coreRand + min;
}

f32 Random::randNF() {
    return randCoreF32();
}

f32 Random::randAF() {
    return 2.0f * randCoreF32() + -1.0f;
}

u32 Random::randCoreU32() {
    u32 mSeed0 =  mSeed.m_0;
    mSeed0 ^= mSeed.m_0 << 11;
    mSeed.m_0 = mSeed.m_4;
    mSeed.m_4 = mSeed.m_8;
    mSeed.m_8 = mSeed.m_C;
    mSeed.m_C ^= mSeed.m_C >> 19;
    mSeed.m_C ^= mSeed0 ^ mSeed0 >> 8;
    return mSeed.m_C;
}

f32 Random::randCoreF32() {
    f32 randCore = randCoreU32() & 0xFFFF;
    return randCore / 65536.0f;
}

//NOTE: All functions below are code merged into others. Refer to the header for more details

int Random::operator()(int max) {
    return randS32(max);
}
