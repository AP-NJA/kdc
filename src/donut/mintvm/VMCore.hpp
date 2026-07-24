#ifndef DONUT_MINTVM_VMCORE_HPP
#define DONUT_MINTVM_VMCORE_HPP

#include "mintvm/MintFuncProxy.hpp"

namespace mintvm {
    class VMCore {
    public:
        typedef void (*NativeFunction)(MintFuncProxy&);

        void addNativeFunction(const char* pNamespace, const char* pFuncName, NativeFunction pFunc);
    };
}

#endif
