#include "scn/step/hero/Invincible.hpp"
#include "scn/step/chara/Invincible.hpp"

using namespace scn::step::hero;

Invincible::Invincible(Hero &rHero)
    : mHero(&rHero)
{
    mEnableIntangibleFlash = false;
    mCandyMightyEffect = false;
    mCandySparkleEffect = false;
    mCandyTimer = 0;
    mEndRainbowTimer = 0;
    mRainbowCycle = 0;
    mUnk24 = false;
}

// https://decomp.me/scratch/o4KB6
void Invincible::update()
{
}

// https://decomp.me/scratch/czXHB
void Invincible::set(u32 frames)
{
}

void Invincible::setNoFlash(u32 frames)
{
    set(frames);
    mUnk24 = true;
}

// https://decomp.me/scratch/vaDRx
void Invincible::setPerm()
{
}

void Invincible::setPermNoFlash()
{
    setPerm();
    mUnk24 = true;
}

void Invincible::unsetPerm()
{
    if (mInvincible.mUsingIntangibleMove)
    {
        mInvincible.mUsingIntangibleMove = false;
        mUnk24 = false;
    }
}

void Invincible::setMighty()
{
    common::Param *pParam = mHero->param()->common();
    setMighty(pParam->mUnk4F8);
}

// https://decomp.me/scratch/Jx8Qa
void Invincible::setMighty(u32 frames)
{
    mInvincible.clear();
    mInvincible.mIsCandyActive = false;
}

// https://decomp.me/scratch/sL4T1
void Invincible::setMightyAfter(u32 frames)
{
	mInvincible.clear();
	mInvincible.mIsCandyActive = true;
}

// https://decomp.me/scratch/JGVWa
void Invincible::clearMighty()
{
	bool isMighty = mInvincible.isMighty();
}

// https://decomp.me/scratch/D5HLU
void Invincible::clear()
{
	mInvincible.clear();
	setBodyCollStateNormalIfNotMighty();

	mEnableIntangibleFlash = false;
	mUnk24 = false;
}

bool Invincible::getFlashOp() const
{	
	
}

