#include "scn/step/chara/Shake.hpp"

using namespace hel::math;
using namespace scn::step::chara;

namespace {
    struct TableEntry
    {
        u32 count;
        const f32* offsTable;
    };

    const f32 T_SHAKE_OFFS_TABLE_SSS[] = {
        -0.02f, 0.02f
    };

    const f32 T_SHAKE_OFFS_TABLE_SS[] = {
        -0.05f, 0.05f
    };

    const f32 T_SHAKE_OFFS_TABLE_S[] = {
        -0.075f, 0.075f,
        -0.02f, 0.02f
    };

    const f32 T_SHAKE_OFFS_TABLE_M[] = {
        -0.12f, 0.12f,
        -0.1f, 0.1f
    };

    const f32 T_SHAKE_OFFS_TABLE_L[] = {
        -0.13f, 0.13f,
        -0.12f, 0.12f,
        -0.1f, 0.1f
    };

    const f32 T_SHAKE_OFFS_TABLE_LL[] = {
        -0.13f, 0.13f,
        -0.13f, 0.13f,
        -0.13f, 0.13f,
        -0.13f, 0.13f,
        -0.12f, 0.12f,
        -0.1f, 0.1f
    };

    #define TABLE_ENTRY(arr) { ARRAY_SIZE(arr), arr }

    const TableEntry T_TABLE[] = {
        TABLE_ENTRY(T_SHAKE_OFFS_TABLE_SSS),
        TABLE_ENTRY(T_SHAKE_OFFS_TABLE_SS),
        TABLE_ENTRY(T_SHAKE_OFFS_TABLE_S),
        TABLE_ENTRY(T_SHAKE_OFFS_TABLE_M),
        TABLE_ENTRY(T_SHAKE_OFFS_TABLE_L),
        TABLE_ENTRY(T_SHAKE_OFFS_TABLE_LL)
    };
}

Shake::Shake()
    : mKind(ShakeKind_Invalid)
    , mFrame(0)
{ }

void Shake::request(ShakeKind kind)
{
    mKind = kind;
    mFrame = 0;
}

void Shake::clear()
{
    mKind = ShakeKind_Invalid;
    mFrame = 0;
}

void Shake::update()
{
    if (mKind == ShakeKind_Invalid)
    {
        return;
    }

    mFrame++;
    if (::T_TABLE[mKind].count << 1 <= mFrame)
    {
        mKind = ShakeKind_Invalid;
    }
}

Vector2 Shake::getOffset() const
{
    if (mKind == ShakeKind_Invalid)
    {
        return Vector2::ZERO;
    }
    
    const ::TableEntry* tbl = &::T_TABLE[mKind];
    
    Vector2 offset(0.0f, 0.0f);
    offset.y = 0.0f;
    offset.x = tbl->offsTable[mFrame << 1];
    if (mFrame >= 1)
    {
        offset.y = 0.75f * tbl->offsTable[mFrame - 1 << 1];
    }

    return offset;
}
