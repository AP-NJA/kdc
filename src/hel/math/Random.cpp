#include <math/Random.hpp>

using hel::math::Random;

Random::Seed Random::Seed::Default() {
    Seed defaultSeed;
    defaultSeed._0 = 0x75bcd15;
    defaultSeed._4 = 0x159a55e5;
    defaultSeed._8 = 0x1f123bb5;
    defaultSeed._C = 0x5491333;
    return defaultSeed;
}
