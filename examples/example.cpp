/**
 * @file example.cpp
 * @author paul
 * @date 11.07.20
 * Description here TODO
 */

#include <SiBase.hpp>
#include <SiExtended.hpp>
#include <SiPrinter.hpp>
#include <SiPrinter.hpp>

int main() {
    using namespace si::literals;
    auto v = 1_meter / 10_second;
    v += 1_k_speed;
    std::cout << v << std::endl;
}
