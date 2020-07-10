/**
 * @file SiBase.hpp
 * @author paul
 * @date 21.03.19
 * @brief SiBase @TODO
 */

#ifndef SI_SILITERALS_HPP
#define SI_SILITERALS_HPP

#include "Si.hpp"

// ...
#define CREATE_ALL_PREFIX(BASE_NAME, a, b, c, d, e, f, g) \
constexpr Si<a,b,c,d,e,f,g> operator "" _Y_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E24)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _Z_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E21)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _E_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E18)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _P_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E15)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _T_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E12)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _G_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E9)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _M_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E6)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _k_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E3)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _h_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E2)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _da_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E1)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _d_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-1)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _c_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-2)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _m_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-3)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _mu_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-6)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _n_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-9)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _p_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-12)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _f_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-15)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _a_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-18)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _z_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-21)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _y_##BASE_NAME(long double t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-24)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _Y_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E24)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _Z_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E21)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _E_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E18)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _P_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E15)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _T_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E12)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _G_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E9)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _M_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E6)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _k_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E3)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _h_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E2)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _da_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E1)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _d_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-1)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _c_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-2)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _m_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-3)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _mu_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-6)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _n_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-9)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _p_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-12)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _f_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-15)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _a_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-18)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _z_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-21)}; } \
constexpr Si<a,b,c,d,e,f,g> operator "" _y_##BASE_NAME(unsigned long long t) { return Si<a,b,c,d,e,f,g>{static_cast<si::default_type>(t * 1E-24)}; }

namespace si {
    // Base types
    template<typename T = si::default_type>
    using Scalar = Si<0, 0, 0, 0, 0, 0, 0, T>;
    template<typename T = si::default_type>
    using Meter = Si<1, 0, 0, 0, 0, 0, 0, T>;
    template<typename T = si::default_type>
    using Kilogram = Si<0, 1, 0, 0, 0, 0, 0, T>;
    template<typename T = si::default_type>
    using Second = Si<0, 0, 1, 0, 0, 0, 0, T>;
    template<typename T = si::default_type>
    using Ampere = Si<0, 0, 0, 1, 0, 0, 0, T>;
    template<typename T = si::default_type>
    using Kelvin = Si<0, 0, 0, 0, 1, 0, 0, T>;
    template<typename T = si::default_type>
    using Mole = Si<0, 0, 0, 0, 0, 1, 0, T>;
    template<typename T = si::default_type>
    using Candela = Si<0, 0, 0, 0, 0, 0, 1, T>;

    // Base units
    constexpr Scalar<> scalar{1};
    constexpr Meter<> meter{1};
    constexpr Kilogram<> kilogram{1};
    constexpr Second<> second{1};
    constexpr Ampere<> ampere{1};
    constexpr Kelvin<> kelvin{1};
    constexpr Mole<> mole{1};
    constexpr Candela<> candela{1};
}

namespace si::literals {
    CREATE_ALL_PREFIX(meter, 1, 0, 0, 0, 0, 0, 0)

    CREATE_ALL_PREFIX(kilogram, 0, 1, 0, 0, 0, 0, 0)

    CREATE_ALL_PREFIX(second, 0, 0, 1, 0, 0, 0, 0)

    CREATE_ALL_PREFIX(ampere, 0, 0, 0, 1, 0, 0, 0)

    CREATE_ALL_PREFIX(kelvin, 0, 0, 0, 0, 1, 0, 0)

    CREATE_ALL_PREFIX(mole, 0, 0, 0, 0, 0, 1, 0)

    CREATE_ALL_PREFIX(candela, 0, 0, 0, 0, 0, 0, 1)

    // Prefix for double
    constexpr Scalar<> operator "" _Y(long double t) { return t * 1E24; }

    constexpr Scalar<> operator "" _Z(long double t) { return t * 1E21; }

    constexpr Scalar<> operator "" _E(long double t) { return t * 1E18; }

    constexpr Scalar<> operator "" _P(long double t) { return t * 1E15; }

    constexpr Scalar<> operator "" _T(long double t) { return t * 1E12; }

    constexpr Scalar<> operator "" _G(long double t) { return t * 1E9; }

    constexpr Scalar<> operator "" _M(long double t) { return t * 1E6; }

    constexpr Scalar<> operator "" _k(long double t) { return t * 1E3; }

    constexpr Scalar<> operator "" _h(long double t) { return t * 1E2; }

    constexpr Scalar<> operator "" _da(long double t) { return t * 1E1; }

    constexpr Scalar<> operator "" _d(long double t) { return t * 1E-1; }

    constexpr Scalar<> operator "" _c(long double t) { return t * 1E-2; }

    constexpr Scalar<> operator "" _m(long double t) { return t * 1E-3; }

    constexpr Scalar<> operator "" _mu(long double t) { return t * 1E-6; }

    constexpr Scalar<> operator "" _n(long double t) { return t * 1E-9; }

    constexpr Scalar<> operator "" _p(long double t) { return t * 1E-12; }

    constexpr Scalar<> operator "" _f(long double t) { return t * 1E-15; }

    constexpr Scalar<> operator "" _a(long double t) { return t * 1E-18; }

    constexpr Scalar<> operator "" _z(long double t) { return t * 1E-21; }

    constexpr Scalar<> operator "" _y(long double t) { return t * 1E-24; }

    // Prefix for int
    constexpr Scalar<> operator "" _Y(unsigned long long t) { return t * 1E24; }

    constexpr Scalar<> operator "" _Z(unsigned long long t) { return t * 1E21; }

    constexpr Scalar<> operator "" _E(unsigned long long t) { return t * 1E18; }

    constexpr Scalar<> operator "" _P(unsigned long long t) { return t * 1E15; }

    constexpr Scalar<> operator "" _T(unsigned long long t) { return t * 1E12; }

    constexpr Scalar<> operator "" _G(unsigned long long t) { return t * 1E9; }

    constexpr Scalar<> operator "" _M(unsigned long long t) { return t * 1E6; }

    constexpr Scalar<> operator "" _k(unsigned long long t) { return t * 1E3; }

    constexpr Scalar<> operator "" _h(unsigned long long t) { return t * 1E2; }

    constexpr Scalar<> operator "" _da(unsigned long long t) { return t * 1E1; }

    constexpr Scalar<> operator "" _d(unsigned long long t) { return t * 1E-1; }

    constexpr Scalar<> operator "" _c(unsigned long long t) { return t * 1E-2; }

    constexpr Scalar<> operator "" _m(unsigned long long t) { return t * 1E-3; }

    constexpr Scalar<> operator "" _mu(unsigned long long t) { return t * 1E-6; }

    constexpr Scalar<> operator "" _n(unsigned long long t) { return t * 1E-9; }

    constexpr Scalar<> operator "" _p(unsigned long long t) { return t * 1E-12; }

    constexpr Scalar<> operator "" _f(unsigned long long t) { return t * 1E-15; }

    constexpr Scalar<> operator "" _a(unsigned long long t) { return t * 1E-18; }

    constexpr Scalar<> operator "" _z(unsigned long long t) { return t * 1E-21; }

    constexpr Scalar<> operator "" _y(unsigned long long t) { return t * 1E-24; }
}

//#undef CREATE_ALL_PREFIX
#endif
