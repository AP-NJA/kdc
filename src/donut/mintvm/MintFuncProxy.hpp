#ifndef DONUT_MINTVM_MINT_FUNC_PROXY_HPP
#define DONUT_MINTVM_MINT_FUNC_PROXY_HPP

#include <types.h>

namespace mintvm {
    class MintFuncProxy {
    public:
        void useRetVal();

        void* internal_getRet_addr() const;
        void* internal_getArg_addr(unsigned int) const;
    };
}

template <typename T>
class mint_wrapNative_helper {
public:
    mint_wrapNative_helper(T arg) DONT_INLINE : mType(arg) {
    }

public:
    /* 0x0 */ T mType;
};

template <typename T>
void mintCallWrappedFunc(T (*pFunc)(), mintvm::MintFuncProxy*);


#define MINT_CALL_WRAPPED_FUNC(type, func, name) \
    struct name { \
        static void Func(mintvm::MintFuncProxy& rProxy) { \
            mintCallWrappedFunc<type>(func, &rProxy); \
        } \
    };

// TODO: *returnAddr = mint_wrapNative_helper<retType>(returnValue); is incorrect (causes extra stack)
#define MINT_FUNC_2ARGS_RET(retType, arg0Type, arg1Type, fn, name) \
    struct name { \
        static void Func(mintvm::MintFuncProxy& rProxy) { \
            rProxy.useRetVal(); \
            mint_wrapNative_helper<retType>* returnAddr = (mint_wrapNative_helper<retType>*)rProxy.internal_getRet_addr(); \
            if (returnAddr != nullptr) { \
                arg1Type* arg1 = (arg1Type*)rProxy.internal_getArg_addr(1); \
                arg0Type* arg0 = (arg0Type*)rProxy.internal_getArg_addr(0); \
                retType returnValue = fn(*arg0, *arg1); \
                *returnAddr = mint_wrapNative_helper<retType>(returnValue); \
            } \
        } \
    };

// TODO: *returnAddr = mint_wrapNative_helper<retType>(returnValue); is incorrect (causes extra stack)
#define MINT_FUNC_1ARG_RET(retType, arg0Type, fn, name) \
    struct name { \
        static void Func(mintvm::MintFuncProxy& rProxy) { \
            rProxy.useRetVal(); \
            mint_wrapNative_helper<retType>* returnAddr = (mint_wrapNative_helper<retType>*)rProxy.internal_getRet_addr(); \
            if (returnAddr != nullptr) { \
                arg0Type* arg0 = (arg0Type*)rProxy.internal_getArg_addr(0); \
                retType returnValue = fn(*arg0); \
                *returnAddr = mint_wrapNative_helper<retType>(returnValue); \
            } \
        } \
    }; \

#endif
