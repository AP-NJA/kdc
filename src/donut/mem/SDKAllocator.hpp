#ifndef DONUT_MEM_SDKALLOCATOR_HPP
#define DONUT_MEM_SDKALLOCATOR_HPP

#include <revolution/MEM.h>

struct IAllocator;

namespace mem {

class SDKAllocator {
public:
    SDKAllocator(IAllocator& rAllocator, int);
    void Alloc(MEMAllocator* pAllocator, size_t size);
    void Free(MEMAllocator* pAllocator, void* pPtr);
private:
    /* 0x0 */ int m_0;
    /* 0x4 */ IAllocator& mAllocator;
    /* 0x8 */ void* mAllocatorFuncs;
    /* 0xC */ int m_C;
};
}

#endif
