#include "app/Locale.hpp"

namespace {

const char* T_POSTS_US[] = {
    "US_JPN",
    "US_ENG",
    "US_GER",
    "US_FRA",
    "US_SPA",
    "US_ITA",
    "US_NED"
};

}

const char* app::Locale::FilePostfix() {
    return T_POSTS_US[1];
}
