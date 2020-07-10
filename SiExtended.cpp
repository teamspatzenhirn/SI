/**
 * @file SiExtended.cpp
 * @author paul
 * @date 01.04.20
 * Description here TODO
 */
#include "SiExtended.hpp"

namespace si {
    template<>
    void printHelper<0>(std::ostream &, const char *) {}

    template<>
    void printHelper<-1>(std::ostream &ostream, const char *name) {
        ostream << "/" << name;
    }

    template<>
    void printHelper<1>(std::ostream &ostream, const char *name) {
        ostream << name;
    }
}
