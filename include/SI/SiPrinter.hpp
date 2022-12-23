/**
 * @file SiPrinter.hpp
 * @author paul
 * @date 11.07.20
 * @brief Declaration of all functions related to printing Si instances together with their respective unit.
 */
#ifndef SI_SIPRINTER_HPP
#define SI_SIPRINTER_HPP

#include <iostream>
#include <sstream>

#include "SiImpl.hpp"

namespace si {
    /**
     * Helper to print a single base unit with non trivial exponent.
     * @tparam exp the exponent for the unit
     * @param ostream the output stream to print to
     * @param name the name of the unit
     */
    template<int exp>
    void printHelper(std::ostream &ostream, const char *name) {
        ostream << " " << name << "^" << exp;
    }

    /**
     * Helper to print a single base unit with exponent 0 (i.e. not part of the compound unit).
     * @see printHelper
     */
    template<>
    void printHelper<0>(std::ostream & /*ostream*/, const char * /*name*/);

    /**
     * Helper to print a single base unit with exponent 1 (i.e. 1/[unit]).
     * @see printHelper
     * @param ostream the output stream to print to
     * @param name the name of the unit
     */
    template<>
    void printHelper<-1>(std::ostream &ostream, const char *name);

    /**
     * Helper to print a single base unit with exponent 1 (i.e. [unit]).
     * @see printHelper
     * @param ostream the output stream to print to
     * @param name the name of the unit
     */
    template<>
    void printHelper<1>(std::ostream &ostream, const char *name);

    /**
     * Helper function to convert a unit-type to a string
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @param ostream the stream to write to
     */
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

    /**
     * Operator to print any SI variable.
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @param ostream the stream to write to
     * @param si the SI variable
     * @return the ostream with the variable printed to it
     */
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    std::ostream &operator<<(std::ostream &ostream, const Si<m, kg, s, A, K, MOL, CD, T> &si) {
        auto val = static_cast<T>(si);
        ostream << val;
        unitToString<m, kg, s, A, K, MOL, CD>(ostream);
        return ostream;
    }
} // namespace si

#endif
