/**
 * @file SiPrinter.cpp
 * @author paul
 * @date 11.07.20
 * @brief Implementation of the specializations for the printer module.
 */
#include "SI/SiPrinter.hpp"

namespace si {
    template<>
    void printHelper<0>(std::ostream & /*ostream*/, const char * /*name*/) {
    }

    template<>
    void printHelper<-1>(std::ostream &ostream, const char *name) {
        ostream << " / " << name;
    }

    template<>
    void printHelper<1>(std::ostream &ostream, const char *name) {
        ostream << " " << name;
    }
} // namespace si
