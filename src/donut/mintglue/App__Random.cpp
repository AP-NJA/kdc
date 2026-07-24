#include "mintglue/App__Random.hpp"
#include "app/Random.hpp"

namespace mintglue { namespace App__Random {
    // General Scratch For Macro funcs (use objdiff) https://decomp.me/scratch/qug7o

    void AddOn(mintvm::VMCore& rCore) {
        MINT_CALL_WRAPPED_FUNC(f32, app::Random::RandNF, Mint_RandNF_0)
        MINT_CALL_WRAPPED_FUNC(f32, app::Random::RandAF, Mint_RandAF_0)
        MINT_FUNC_2ARGS_RET(f32, f32, f32, app::Random::RandF, Mint_RandF_0)
        MINT_FUNC_2ARGS_RET(int, int, int, app::Random::Rand, Mint_Rand_0)
        MINT_FUNC_1ARG_RET(int, int, app::Random::Rand, Mint_Rand_0_2)
        MINT_FUNC_1ARG_RET(bool, f32, app::Random::RandBool, Mint_RandBool_0)

        rCore.addNativeFunction("App.Random", "bool RandBool(float)", Mint_RandBool_0::Func);
        rCore.addNativeFunction("App.Random", "int Rand(int)", Mint_Rand_0_2::Func);
        rCore.addNativeFunction("App.Random", "int Rand(int,int)", Mint_Rand_0::Func);
        rCore.addNativeFunction("App.Random", "float RandF(float,float)", Mint_RandF_0::Func);
        rCore.addNativeFunction("App.Random", "float RandNF()", Mint_RandNF_0::Func);
        rCore.addNativeFunction("App.Random", "float RandAF()", Mint_RandAF_0::Func);
    }

}}

// Leftover strings from MintFuncProxy.hpp
const char* MintFuncProxyAssertionString = "Assertion failed.\n";
const char* MintFuncProxyFileString = "MintFuncProxy.hpp";
const char* MintArrayAssertionString = "index = %d, count = %d\n";
const char* MintArrayFileString = "MArray.hpp";
