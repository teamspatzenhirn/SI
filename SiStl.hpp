/**
 * @file SiStl.hpp
 * @author paul
 * @date 03.04.20
 * Specialization of STL functions for SI types.
 */
#ifndef SI_SISTL_HPP
#define SI_SISTL_HPP

#include <cmath>
#include "SiImpl.hpp"

namespace std {
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto sqrt(si::Si<m, kg, s, A, K, MOL, CD, T> si) -> si::Si<m / 2, kg / 2, s / 2, A / 2, K / 2, MOL / 2, CD / 2, T> {
        static_assert(
                m % 2 == 0 && kg % 2 == 0 && s % 2 == 0 && A % 2 == 0 && K % 2 == 0 && MOL % 2 == 0 && CD % 2 == 0,
                "sqrt not possible as resulting type has unit with non integer power of unit");
        return si::Si<m / 2, kg / 2, s / 2, A / 2, K / 2, MOL / 2, CD / 2, T>{std::sqrt(static_cast<T>(si))};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto abs(si::Si<m, kg, s, A, K, MOL, CD, T> si) -> si::Si<m, kg, s, A, K, MOL, CD, T> {
        return si::Si<m, kg, s, A, K, MOL, CD, T>{std::abs(static_cast<T>(si))};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto round(si::Si<m, kg, s, A, K, MOL, CD, T> si) -> si::Si<m, kg, s, A, K, MOL, CD, T> {
        return si::Si<m, kg, s, A, K, MOL, CD, T>{std::round(static_cast<T>(si))};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto isnan(si::Si<m, kg, s, A, K, MOL, CD, T> si) -> bool {
        return std::isnan(static_cast<T>(si));
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    auto atan2(si::Si<m, kg, s, A, K, MOL, CD, T> y, si::Si<m, kg, s, A, K, MOL, CD, T> x) -> T {
        return std::atan2(static_cast<T>(y), static_cast<T>(x));
    }
}

#endif
