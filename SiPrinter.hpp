/**
 * @file SiPrinter.hpp
 * @author paul
 * @date 11.07.20
 * Declaration of all functions related to printing Si instances together with their respective unit.
 */
#ifndef SI_SIPRINTER_HPP
#define SI_SIPRINTER_HPP

#include <iostream>
#include <sstream>

#include "SiImpl.hpp"

namespace si {
    template<int exp>
    void printHelper(std::ostream &ostream, const char *name) {
        ostream << " " << name << "^" << exp;
    }

    template<>
    void printHelper<0>(std::ostream &, const char *);

    template<>
    void printHelper<-1>(std::ostream &ostream, const char *name);

    template<>
    void printHelper<1>(std::ostream &ostream, const char *name);

    template<int m, int kg, int s, int A, int K, int MOL, int CD>
    void unitToString(std::ostream &ostream) {
        printHelper<m>(ostream, "m");
        printHelper<kg>(ostream, "kg");
        printHelper<s>(ostream, "s");
        printHelper<A>(ostream, "A");
        printHelper<K>(ostream, "K");
        printHelper<MOL>(ostream, "Mol");
        printHelper<CD>(ostream, "Cd");
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    std::ostream &operator<<(std::ostream &ostream, const Si<m, kg, s, A, K, MOL, CD, T> &si) {
        auto val = static_cast<T>(si);
        ostream << val;
        unitToString<m, kg, s, A, K, MOL, CD>(ostream);
        return ostream;
    }
}

#endif
