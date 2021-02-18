/**
 * @file SiGenerator.hpp
 * @author paul
 * @date 11.07.20
 * Header file with the definitions for the macros for generating code for new units. This code consists
 * of the type definition, the definition of a constant and the literals (both with and without prefixes).
 */
#ifndef SI_SIGENERATOR_HPP
#define SI_SIGENERATOR_HPP

#define SI_CREATE_ALL_PREFIX(BASE_NAME, m, kg, s, A, K, Mol, CD)                                                       \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _Y_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E24)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _Z_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E21)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _E_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E18)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _P_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E15)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _T_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E12)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _G_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E9)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _M_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E6)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _k_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E3)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _h_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E2)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _da_##BASE_NAME(long double t) {                                  \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E1)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _##BASE_NAME(long double t) {                                     \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t)};                                          \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _d_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-1)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _c_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-2)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _m_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-3)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _mu_##BASE_NAME(long double t) {                                  \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-6)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _n_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-9)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _p_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-12)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _f_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-15)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _a_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-18)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _z_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-21)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _y_##BASE_NAME(long double t) {                                   \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-24)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _Y_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E24)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _Z_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E21)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _E_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E18)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _P_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E15)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _T_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E12)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _G_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E9)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _M_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E6)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _k_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E3)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _h_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E2)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _da_##BASE_NAME(unsigned long long t) {                           \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E1)};                                    \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _##BASE_NAME(unsigned long long t) {                              \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t)};                                          \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _d_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-1)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _c_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-2)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _m_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-3)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _mu_##BASE_NAME(unsigned long long t) {                           \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-6)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _n_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-9)};                                   \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _p_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-12)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _f_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-15)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _a_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-18)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _z_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-21)};                                  \
    }                                                                                                                  \
    constexpr Si<m, kg, s, A, K, Mol, CD> operator"" _y_##BASE_NAME(unsigned long long t) {                            \
        return Si<m, kg, s, A, K, Mol, CD>{static_cast<si::default_type>(t * 1E-24)};                                  \
    }

#define SI_CREATE_UNIT(Name, name, m, kg, s, A, K, Mol, CD)                                                            \
    namespace si {                                                                                                     \
        template<typename T = si::default_type>                                                                        \
        using Name = Si<m, kg, s, A, K, Mol, CD, T>;                                                                   \
        constexpr Name<> name{static_cast<si::default_type>(1)};                                                       \
        namespace literals {                                                                                           \
            SI_CREATE_ALL_PREFIX(name, m, kg, s, A, K, Mol, CD)                                                        \
        }                                                                                                              \
    }

#define SI_CUSTOM_PRINTER_IMPL(Type, name)                                                                             \
    namespace si {                                                                                                     \
        template<>                                                                                                     \
        void unitToString<Type<>::meter, Type<>::kilogram, Type<>::second, Type<>::ampere, Type<>::kelvin,             \
                          Type<>::mole, Type<>::candela>(std::ostream & ostream) {                                     \
            ostream << " " << name;                                                                                    \
        }                                                                                                              \
    }

#define SI_CUSTOM_PRINTER_DEC(Type)                                                                                    \
    namespace si {                                                                                                     \
        template<>                                                                                                     \
        void unitToString<Type<>::meter, Type<>::kilogram, Type<>::second, Type<>::ampere, Type<>::kelvin,             \
                          Type<>::mole, Type<>::candela>(std::ostream & ostream);                                      \
    }

#endif
