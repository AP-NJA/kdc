#include "app/Random.hpp"
#include "app/Application.hpp"

namespace app {
    namespace Random {
        bool RandBool(f32 max) {
            return Obj().randBool(max);
        }

        int Rand(int max) {
            return Obj().rand(max); // could be operator()
        }

        int Rand(int min, int max) {
            return Obj().rand(min, max);
        }

        f32 RandF(f32 min, f32 max) {
            return Obj().randF(min, max);
        }

        u32 RandU32(u32 max) {
            return Obj().randU32(max);
        }

        u32 RandU32(u32 min, u32 max) {
            return Obj().randU32(min, max);
        }

        f32 RandF32(f32 min, f32 max) {
            return Obj().randF32(min, max);
        }

        f32 RandNF() {
            return Obj().randNF();
        }

        f32 RandAF() {
            return Obj().randAF();
        }

        void Reset() {
            Obj() = hel::math::Random(hel::math::Random::Seed::Default());
        }

        hel::math::Random& Obj() {
            return app::Application::Instance->random();
        }
    }
}
