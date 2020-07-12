/**
 * @file SiPrinter.cpp
 * @author paul
 * @date 11.07.20
 * Implementation of the specializations for the printer module.
 */
#include "SiPrinter.hpp"

namespace si {
    template<>
    void printHelper<0>(std::ostream &, const char *) {}

    template<>
    void printHelper<-1>(std::ostream &ostream, const char *name) {
        ostream << " / " << name;
    }

    template<>
    void printHelper<1>(std::ostream &ostream, const char *name) {
        ostream << " " << name;
    }
}
