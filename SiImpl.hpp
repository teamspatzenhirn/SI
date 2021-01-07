/**
 * @file Si.hpp
 * @author paul
 * @date 20.03.19
 * @brief Main implementation of the Si class which is the basis for all other functions.
 */

#ifndef SI_SIIMPL_HPP
#define SI_SIIMPL_HPP

#include <utility>

#if __cpp_conditional_explicit
    #define EXPLICIT(expr) explicit(expr)
#else
    #define EXPLICIT(expr) explicit
#endif

namespace si {
#ifndef SI_DEFAULT_TYPE
    using default_type = double;
#else
    using default_type = SI_DEFAULT_TYPE;
#endif

    template<typename T>
    struct IsSi {
        static constexpr auto val = false;
    };

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T = default_type>
    class Si {
            using ThisT = Si<m, kg, s, A, K, MOL, CD, T>;

            static constexpr bool isScalar = (m == 0 && kg == 0 && s == 0 && A == 0 && K == 0 && MOL == 0 && CD == 0);
            static_assert(!IsSi<T>::val, "Type T for SI is another instance of SI, your are not allowed to "
                                         "wrap SI in SI");
        public:
            static constexpr auto meter = m;
            static constexpr auto kilogram = kg;
            static constexpr auto second = s;
            static constexpr auto ampere = A;
            static constexpr auto kelvin = K;
            static constexpr auto mole = MOL;
            static constexpr auto candela = CD;

            using type = T;

            constexpr Si() noexcept = default;

            /*
             * DO NOT TRY TO IMPLEMENT THESE FUNCTIONS BELOW LIKE ALL OTHER FUNCTIONS, GCC (UP TO 10.1)
             * IS BROKEN AND WILL COMPLETELY IGNORE THE explicit SPECIFIER!
             */
            constexpr EXPLICIT(!isScalar) Si(T val) noexcept: val{val} {}

            constexpr EXPLICIT(!isScalar) operator T() const noexcept { return val; }

            template<typename T_>
            constexpr explicit operator T_() const;

            template<typename T_>
            constexpr explicit operator Si<m, kg, s, A, K, MOL, CD, T_>() const;

            // Add (only same units)
            constexpr auto operator+(ThisT rhs) const -> ThisT;

            constexpr void operator+=(ThisT rhs);

            // Subtract (only same units)
            constexpr auto operator-(ThisT rhs) const -> ThisT;

            constexpr void operator-=(ThisT rhs);

            // Unary minus
            constexpr auto operator-() const -> ThisT;

            // Multiply with Unitless
            constexpr auto operator*(T rhs) const -> Si<m, kg, s, A, K, MOL, CD, T>;

            constexpr auto operator*=(T rhs) -> ThisT &;

            template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_, typename T_>
            friend constexpr auto operator*(T_ lhs, Si<m_, kg_, s_, A_, K_, MOL_, CD_, T_> rhs)
            -> Si<m_, kg_, s_, A_, K_, MOL_, CD_, T_>;

            // Divide by Unitless
            constexpr auto operator/(T rhs) const
            -> Si<m, kg, s, A, K, MOL, CD, T>;

            constexpr auto operator/=(T rhs) -> ThisT &;

            template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_, typename T_>
            friend constexpr auto operator/(T_ lhs, Si<m_, kg_, s_, A_, K_, MOL_, CD_, T_> rhs)
            -> Si<-m_, -kg_, -s_, -A_, -K_, -MOL_, -CD_, T_>;

            // Multiply with Unit
            template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_>
            constexpr auto operator*(Si<m_, kg_, s_, A_, K_, MOL_, CD_, T> rhs) const
            -> Si<m + m_, kg + kg_, s + s_, A + A_, K + K_, MOL + MOL_, CD + CD_, T>;

            // Divide by Unit
            template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_>
            constexpr auto operator/(Si<m_, kg_, s_, A_, K_, MOL_, CD_, T> rhs) const
            -> Si<m - m_, kg - kg_, s - s_, A - A_, K - K_, MOL - MOL_, CD - CD_, T>;

#ifndef __cpp_impl_three_way_comparison
            // Equal
            constexpr auto operator==(ThisT rhs) const;

            constexpr auto operator!=(ThisT rhs) const;

            // Size relation
            constexpr auto operator<(ThisT rhs) const -> bool;

            constexpr auto operator>(ThisT rhs) const -> bool;

            constexpr auto operator<=(ThisT rhs) const -> bool;

            constexpr auto operator>=(ThisT rhs) const -> bool;
#else

            constexpr auto operator<=>(const ThisT &rhs) const = default;

#endif

        private:
            T val;
    };

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    struct IsSi<Si<m, kg, s, A, K, MOL, CD, T>> {
        static constexpr auto val = true;
    };

    // CTor, Conversion
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    template<typename T_>
    constexpr Si<m, kg, s, A, K, MOL, CD, T>::operator T_() const {
        return static_cast<T_>(val);
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    template<typename T_>
    constexpr Si<m, kg, s, A, K, MOL, CD, T>::operator Si<m, kg, s, A, K, MOL, CD, T_>() const {
        return Si<m, kg, s, A, K, MOL, CD, T_>{static_cast<T_>(this->val)};
    }

    // Add
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator+(Si::ThisT rhs) const -> Si::ThisT {
        return ThisT{this->val + rhs.val};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr void Si<m, kg, s, A, K, MOL, CD, T>::operator+=(Si::ThisT rhs) {
        this->val += rhs.val;
    }

    // Subtract
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator-(Si::ThisT rhs) const -> Si::ThisT {
        return ThisT{this->val - rhs.val};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr void Si<m, kg, s, A, K, MOL, CD, T>::operator-=(Si::ThisT rhs) {
        this->val -= rhs.val;
    }

    // Unary minus
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator-() const -> Si::ThisT {
        return ThisT{-val};
    }

    // Multiply by scalar
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator*(T rhs) const
    -> Si<m, kg, s, A, K, MOL, CD, T> {
        return Si<m, kg, s, A, K, MOL, CD, decltype(this->val * rhs)>{this->val * rhs};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator*=(T rhs) -> ThisT & {
        this->val *= rhs;
        return *this;
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T_>
    constexpr auto operator*(T_ lhs, Si<m, kg, s, A, K, MOL, CD, T_> rhs)
    -> Si<m, kg, s, A, K, MOL, CD, T_> {
        return Si<m, kg, s, A, K, MOL, CD, T_>{lhs * rhs.val};
    }

    // Divide by scalar
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator/(T rhs) const
    -> Si<m, kg, s, A, K, MOL, CD, T> {
        return Si<m, kg, s, A, K, MOL, CD, decltype(this->val * rhs)>{this->val / rhs};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator/=(T rhs) -> ThisT & {
        this->val /= rhs;
        return *this;
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T_>
    constexpr auto operator/(T_ lhs, Si<m, kg, s, A, K, MOL, CD, T_> rhs)
    -> Si<-m, -kg, -s, -A, -K, -MOL, -CD, T_> {
        return Si<-m, -kg, -s, -A, -K, -MOL, -CD, T_>{lhs / static_cast<T_>(rhs)};
    }

    // Multiply with different type
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator*(Si<m_, kg_, s_, A_, K_, MOL_, CD_, T> rhs) const
    -> Si<m + m_, kg + kg_, s + s_, A + A_, K + K_, MOL + MOL_, CD + CD_, T> {
        return Si<m + m_, kg + kg_, s + s_, A + A_, K + K_, MOL + MOL_, CD + CD_, T>{this->val * static_cast<T>(rhs)};
    }

    // Divide by different type
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator/(Si<m_, kg_, s_, A_, K_, MOL_, CD_, T> rhs) const
    -> Si<m - m_, kg - kg_, s - s_, A - A_, K - K_, MOL - MOL_, CD - CD_, T> {
        return Si<m - m_, kg - kg_, s - s_, A - A_, K - K_, MOL - MOL_, CD - CD_, T>{this->val / static_cast<T>(rhs)};
    }


#ifndef __cpp_impl_three_way_comparison
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator==(Si::ThisT rhs) const {
        return this->val == static_cast<T>(rhs);
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator!=(Si::ThisT rhs) const {
        return !((*this) == rhs);
    }

    // Size comparison
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator<(Si::ThisT rhs) const -> bool {
        return this->val < static_cast<T>(rhs);
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator>(Si::ThisT rhs) const -> bool {
        return this->val > static_cast<T>(rhs);
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator<=(Si::ThisT rhs) const -> bool {
        return this->val <= static_cast<T>(rhs);
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator>=(Si::ThisT rhs) const -> bool {
        return this->val >= static_cast<T>(rhs);
    }
#endif

}

#endif
