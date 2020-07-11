/**
 * @file SiBase.hpp
 * @author paul
 * @date 21.03.19
 * @brief SiBase @TODO
 */

#ifndef SI_SIBASE_HPP
#define SI_SIBASE_HPP

#include "Si.hpp"
#include "SiGenerator.hpp"

SI_CREATE_UNIT(Scalar, scalar, 0, 0, 0, 0, 0, 0, 0)
SI_CREATE_UNIT(Meter, meter, 1, 0, 0, 0, 0, 0, 0)
SI_CREATE_UNIT(Kilogram, kilogram, 0, 1, 0, 0, 0 , 0, 0)
SI_CREATE_UNIT(Second, second, 0, 0, 1, 0, 0, 0, 0)
SI_CREATE_UNIT(Ampere, ampere, 0, 0, 0, 1, 0, 0, 0)
SI_CREATE_UNIT(Kelvin, kelvin, 0, 0, 0, 0, 1, 0, 0)
SI_CREATE_UNIT(Mole, mole, 0, 0, 0, 0, 0, 1, 0)
SI_CREATE_UNIT(Candela, candela, 0, 0, 0, 0, 0, 0, 1)


namespace si { namespace literals {
    // Prefix for double
    constexpr Scalar<> operator "" _Y(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E24)}; }

    constexpr Scalar<> operator "" _Z(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E21)}; }

    constexpr Scalar<> operator "" _E(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E18)}; }

    constexpr Scalar<> operator "" _P(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E15)}; }

    constexpr Scalar<> operator "" _T(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E12)}; }

    constexpr Scalar<> operator "" _G(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E9)}; }

    constexpr Scalar<> operator "" _M(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E6)}; }

    constexpr Scalar<> operator "" _k(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E3)}; }

    constexpr Scalar<> operator "" _h(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E2)}; }

    constexpr Scalar<> operator "" _da(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E1)}; }

    constexpr Scalar<> operator "" _d(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-1)}; }

    constexpr Scalar<> operator "" _c(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-2)}; }

    constexpr Scalar<> operator "" _m(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-3)}; }

    constexpr Scalar<> operator "" _mu(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-6)}; }

    constexpr Scalar<> operator "" _n(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-9)}; }

    constexpr Scalar<> operator "" _p(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-12)}; }

    constexpr Scalar<> operator "" _f(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-15)}; }

    constexpr Scalar<> operator "" _a(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-18)}; }

    constexpr Scalar<> operator "" _z(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-21)}; }

    constexpr Scalar<> operator "" _y(long double t) { return Scalar<>{static_cast<si::default_type>(t * 1E-24)}; }

    // Prefix for int
    constexpr Scalar<> operator "" _Y(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E24)}; }

    constexpr Scalar<> operator "" _Z(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E21)}; }

    constexpr Scalar<> operator "" _E(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E18)}; }

    constexpr Scalar<> operator "" _P(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E15)}; }

    constexpr Scalar<> operator "" _T(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E12)}; }

    constexpr Scalar<> operator "" _G(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E9)}; }

    constexpr Scalar<> operator "" _M(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E6)}; }

    constexpr Scalar<> operator "" _k(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E3)}; }

    constexpr Scalar<> operator "" _h(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E2)}; }

    constexpr Scalar<> operator "" _da(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E1)}; }

    constexpr Scalar<> operator "" _d(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-1)}; }

    constexpr Scalar<> operator "" _c(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-2)}; }

    constexpr Scalar<> operator "" _m(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-3)}; }

    constexpr Scalar<> operator "" _mu(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-6)}; }

    constexpr Scalar<> operator "" _n(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-9)}; }

    constexpr Scalar<> operator "" _p(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-12)}; }

    constexpr Scalar<> operator "" _f(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-15)}; }

    constexpr Scalar<> operator "" _a(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-18)}; }

    constexpr Scalar<> operator "" _z(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-21)}; }

    constexpr Scalar<> operator "" _y(unsigned long long t) { return Scalar<>{static_cast<si::default_type>(t * 1E-24)}; }
} }

#endif
