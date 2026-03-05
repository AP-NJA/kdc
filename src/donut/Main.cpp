#include "app/EntryPoint.hpp"

void main(int argc, char* argv[]) {
    const char* resetState = argc == 2 ? argv[1] : "";
    app::EntryPoint::Run(false, resetState);
}
