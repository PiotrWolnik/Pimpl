#include "widget.hpp"
#include <cstdlib>

int main() {

    Gadget g1{};
    Gadget g2{};
    std::cout << g1;
    std::cout << std::boolalpha;
    std::cout << (g1 == g2);
    return EXIT_SUCCESS;
}
