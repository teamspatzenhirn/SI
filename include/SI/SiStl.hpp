/**
 * @file SiStl.hpp
 * @author paul
 * @date 03.04.20
 * @brief Specialization of STL functions for SI types.
 * @ingroup SI
 */
#ifndef SI_SISTL_HPP
#define SI_SISTL_HPP

#include <cmath>

#include "SiImpl.hpp"

namespace std {
    /**
     * Implementation of the square root function for SI types, required that all exponents are multiple of 2.
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @tparam T the underlying numerical type
     * @param si the si variable
     * @return an SI object with unit as sqrt(unit) and value as sqrt(value)
     */
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto sqrt(si::Si<m, kg, s, A, K, MOL, CD, T> si) -> si::Si<m / 2, kg / 2, s / 2, A / 2, K / 2, MOL / 2, CD / 2, T> {
        static_assert(m % 2 == 0 && kg % 2 == 0 && s % 2 == 0 && A % 2 == 0 && K % 2 == 0 && MOL % 2 == 0 &&
                              CD % 2 == 0,
                      "sqrt not possible as resulting type has unit with non integer power of unit");
        return si::Si<m / 2, kg / 2, s / 2, A / 2, K / 2, MOL / 2, CD / 2, T>{std::sqrt(static_cast<T>(si))};
    }

    /**
     * Implementation of the absolute function for SI types.
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @tparam T the underlying numerical type
     * @param si the si variable
     * @return an SI object with unit as the original unit and value as abs(value)
     */
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto abs(si::Si<m, kg, s, A, K, MOL, CD, T> si) -> si::Si<m, kg, s, A, K, MOL, CD, T> {
        return si::Si<m, kg, s, A, K, MOL, CD, T>{std::abs(static_cast<T>(si))};
    }

    /**
     * Implementation of the round function for SI types.
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @tparam T the underlying numerical type
     * @param si the si variable
     * @return an SI object with unit as the original unit and value as round(value)
     */
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto round(si::Si<m, kg, s, A, K, MOL, CD, T> si) -> si::Si<m, kg, s, A, K, MOL, CD, T> {
        return si::Si<m, kg, s, A, K, MOL, CD, T>{std::round(static_cast<T>(si))};
    }

    /**
     * Implementation of the isnan function for SI types.
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @tparam T the underlying numerical type
     * @param si the si variable
     * @return isnan of the underlying type.
     */
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto isnan(si::Si<m, kg, s, A, K, MOL, CD, T> si) -> bool {
        return std::isnan(static_cast<T>(si));
    }

    /**
     * Implementation of the atan2 functions for two variable of identical unit.
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @tparam T the underlying numerical type
     * @param y the y variable of std::atan2
     * @param x the y variable of std::atan2
     * @return a unitless angle of the same type as the underlying type of the arguments.
     */
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto atan2(si::Si<m, kg, s, A, K, MOL, CD, T> y, si::Si<m, kg, s, A, K, MOL, CD, T> x) -> T {
        return std::atan2(static_cast<T>(y), static_cast<T>(x));
    }
} // namespace std

#endif
