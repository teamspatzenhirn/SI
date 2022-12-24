/**
 * @file SiImpl.hpp
 * @author paul
 * @date 20.03.19
 * @brief Main implementation of the Si class which is the basis for all other functions.
 * @ingroup SI
 */

#ifndef SI_SIIMPL_HPP
#define SI_SIIMPL_HPP

#include <utility>

#if __cpp_conditional_explicit
    // NOLINTNEXTLINE(cppcoreguidelines-macro-usage) keyword can not be replaced by constexpr function
    #define EXPLICIT(expr) explicit(expr) ///< Condition explicit for C++20 and later.
#else
    // NOLINTNEXTLINE(cppcoreguidelines-macro-usage) keyword can not be replaced by constexpr function
    #define EXPLICIT(expr) explicit ///< Non condition explicit for older compilers.
#endif

#ifndef SI_DEFAULT_TYPE
    #define SI_DEFAULT_TYPE double ///< Default type of underlying numerical type.
#endif

namespace si {
    /**
     * Default type for all constants, literals and types.
     */
    using default_type = SI_DEFAULT_TYPE;

    /**
     * Type trait to check whether a type is an SI instance.
     * @tparam T the type to check.
     */
    template<typename T>
    struct IsSi {
        /**
         * Type is not a SI instance.
         */
        static constexpr auto val = false;
    };

    /**
     * Class to represent a number with unit.
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @tparam T the underlying numerical type
     */
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T = default_type>
    class Si {
        using ThisT = Si<m, kg, s, A, K, MOL, CD, T>;

        static constexpr bool isScalar = (m == 0 && kg == 0 && s == 0 && A == 0 && K == 0 && MOL == 0 && CD == 0);
        static_assert(!IsSi<T>::val, "Type T for SI is another instance of SI, your are not allowed to "
                                     "wrap SI in SI");

      public:
        static constexpr auto meter = m;     ///< Meter exponent
        static constexpr auto kilogram = kg; ///< Kilogram exponent
        static constexpr auto second = s;    ///< Second exponent
        static constexpr auto ampere = A;    ///< Ampere exponent
        static constexpr auto kelvin = K;    ///< Kelvin exponent
        static constexpr auto mole = MOL;    ///< Mole exponent
        static constexpr auto candela = CD;  ///< Candela exponent
        using type = T;                      ///< Underlying numerical type

        constexpr Si() noexcept = default;

        /**
         * CTor to create object from underlying type, for unitless arguments implicit conversion is allowed,
         * otherwise explicit conversion is required.
         *
         * @warning do not try to implement these functions below like all other functions, gcc (up to 10.1) is broken
         * and will completely ignore the EXPLICIT specifier!
         * @param val the numerical value.
         */
        constexpr EXPLICIT(!isScalar) Si(T val) noexcept : val{val} /* NOLINT(google-explicit-constructor) */ {
        }

        /**
         * Conversion operator to underlying type, for unitless arguments implicit conversion is allowed, otherwise
         * explicit conversion is required.
         * @return the underlying numerical value
         */
        constexpr EXPLICIT(!isScalar) operator T() const noexcept /* NOLINT(google-explicit-constructor) */ {
            return val;
        }

        /**
         * Conversion operator to other numerical type, conversion is performed via an explicit cast of the
         * underlying value to T_.
         * @tparam T_ the type to convert to.
         * @return the casted value
         */
        template<typename T_>
        constexpr explicit operator T_() const;

        /**
         * Conversion operator to SI with other numerical type, conversion is performed via an explicit cast of
         * the underlying value to T_.
         * @tparam T_  the underlying type to convert to
         * @return the casted SI object
         */
        template<typename T_>
        constexpr explicit operator Si<m, kg, s, A, K, MOL, CD, T_>() const;

        /**
         * Add object with SI object of same unit and type
         * @param rhs the object to add
         * @return the same of both values with same unit
         */
        constexpr auto operator+(ThisT rhs) const -> ThisT;

        /**
         * Increment object by SI object of same unit and type
         * @param rhs the object to add
         * @return the sum of both values with same unit
         */
        constexpr void operator+=(ThisT rhs);

        /**
         * Subtract object with SI object of same unit and type
         * @param rhs the object to subtract
         * @return the same of both values with same unit
         */
        constexpr auto operator-(ThisT rhs) const -> ThisT;

        /**
         * Decrement Increment object by SI object of same unit and type
         * @param rhs the object to subtract
         * @return the difference of both values with same unit
         */
        constexpr void operator-=(ThisT rhs);

        /**
         * Unary minus, apply unary minus to value and keep unit.
         * @return the negative of the current object.
         */
        constexpr auto operator-() const -> ThisT;

        /**
         * Calculates the operation SI*scalar, unit is kept, value is scaled with the argument.
         * @param rhs the factor to scale with
         * @return the scaled value
         */
        constexpr auto operator*(T rhs) const -> ThisT;

        /**
         * Calculates the operation SI *= scalar, unit is kept, value is scaled with the argument.
         * @param rhs the factor to scale with
         * @return the scaled value
         */
        constexpr auto operator*=(T rhs) -> ThisT &;

        /**
         * Calculates scalar * SI, unit is kept, value is scaled with the argument.
         * @tparam m_ the meter exponent
         * @tparam kg_ the kilogram exponent
         * @tparam s_ the second exponent
         * @tparam A_ the Ampere exponent
         * @tparam K_ the Kelvin exponent
         * @tparam MOL_ the Mol exponent
         * @tparam CD_ the Candela exponent
         * @tparam T_ the underlying numerical type
         * @param lhs the scalar value
         * @param rhs the SI value
         * @return the scaled value
         */
        template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_, typename T_>
        friend constexpr auto operator*(T_ lhs, Si<m_, kg_, s_, A_, K_, MOL_, CD_, T_> rhs)
                -> Si<m_, kg_, s_, A_, K_, MOL_, CD_, T_>;

        /**
         * Calculates the operation SI/scalar, unit is kept, value is scaled with 1/argument.
         * @param rhs the divisor
         * @return the scaled value
         */
        constexpr auto operator/(T rhs) const -> Si<m, kg, s, A, K, MOL, CD, T>;

        /**
         * Calculates the operation SI /= scalar, unit is kept, value is scaled with 1/argument.
         * @param rhs the factor to scale with
         * @return the scaled value
         */
        constexpr auto operator/=(T rhs) -> ThisT &;

        /**
         * Calculates scalar/SI, value and unit are inverted.
         * @tparam m_ the meter exponent
         * @tparam kg_ the kilogram exponent
         * @tparam s_ the second exponent
         * @tparam A_ the Ampere exponent
         * @tparam K_ the Kelvin exponent
         * @tparam MOL_ the Mol exponent
         * @tparam CD_ the Candela exponent
         * @tparam T_ the underlying numerical type
         * @param lhs the scalar value
         * @param rhs the SI value
         * @return the scaled value
         */
        template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_, typename T_>
        friend constexpr auto operator/(T_ lhs, Si<m_, kg_, s_, A_, K_, MOL_, CD_, T_> rhs)
                -> Si<-m_, -kg_, -s_, -A_, -K_, -MOL_, -CD_, T_>;

        /**
         * Calculate the product of two SI variables by summing the unit-exponents and multiplying the values.
         * @tparam m_ the other meter exponent
         * @tparam kg_ the other kilogram exponent
         * @tparam s_ the other second exponent
         * @tparam A_ the other Ampere exponent
         * @tparam K_ the other Kelvin exponent
         * @tparam MOL_ the other Mol exponent
         * @tparam CD_ the other Candela exponent
         * @param rhs the other SI variable
         * @return the product of the SI variables
         */
        template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_>
        constexpr auto operator*(Si<m_, kg_, s_, A_, K_, MOL_, CD_, T> rhs) const
                -> Si<m + m_, kg + kg_, s + s_, A + A_, K + K_, MOL + MOL_, CD + CD_, T>;

        /**
         * Calculate the division of two SI variables by taking the difference of the unit-exponents and dividing
         * the values.
         * @tparam m_ the other meter exponent
         * @tparam kg_ the other kilogram exponent
         * @tparam s_ the other second exponent
         * @tparam A_ the other Ampere exponent
         * @tparam K_ the other Kelvin exponent
         * @tparam MOL_ the other Mol exponent
         * @tparam CD_ the other Candela exponent
         * @param rhs the SI variable by which to divide
         * @return the division of the SI variables
         */
        template<int m_, int kg_, int s_, int A_, int K_, int MOL_, int CD_>
        constexpr auto operator/(Si<m_, kg_, s_, A_, K_, MOL_, CD_, T> rhs) const
                -> Si<m - m_, kg - kg_, s - s_, A - A_, K - K_, MOL - MOL_, CD - CD_, T>;

#ifndef __cpp_impl_three_way_comparison
        /**
         * Equality operator for SI types. Requires same unit, then performs comparison by value.
         * @param rhs the other value
         * @return true if the values are equal, otherwise false
         */
        constexpr auto operator==(ThisT rhs) const;

        /**
         * Non-Equality operator for SI types. Requires same unit, then performs comparison by value.
         * @param rhs the other value
         * @return true if the values are not equal, otherwise false
         */
        constexpr auto operator!=(ThisT rhs) const;

        /**
         * Less than operator for SI types. Requires same unit, then performs comparison by value.
         * @param rhs the other value
         * @return true if this is less than rhs
         */
        constexpr auto operator<(ThisT rhs) const -> bool;

        /**
         * Greater than operator for SI types. Requires same unit, then performs comparison by value.
         * @param rhs the other value
         * @return true if this is greater than rhs
         */
        constexpr auto operator>(ThisT rhs) const -> bool;

        /**
         * Less than-equal operator for SI types. Requires same unit, then performs comparison by value.
         * @param rhs the other value
         * @return true if this is less or equal than rhs
         */
        constexpr auto operator<=(ThisT rhs) const -> bool;

        /**
         * Greater than-equal operator for SI types. Requires same unit, then performs comparison by value.
         * @param rhs the other value
         * @return true if this is greater or equal than rhs
         */
        constexpr auto operator>=(ThisT rhs) const -> bool;
#else
        /**
         * Three way comparison operator (i.e <,>,<=,>=,== and !=) for SI types. Requires same unit, then performs
         * comparison by value.
         * @param rhs the other value
         * @return 0 if equal, 1 if this is greater than rhs, -1 if this is less than rhs
         */
        constexpr auto operator<=>(const ThisT &rhs) const = default;
#endif

      private:
        T val;
    };

    /**
     * Specialization of type trait to check wheter a type is an SI instance for SI instances.
     * @tparam m the meter exponent
     * @tparam kg the kilogram exponent
     * @tparam s the second exponent
     * @tparam A the Ampere exponent
     * @tparam K the Kelvin exponent
     * @tparam MOL the Mol exponent
     * @tparam CD the Candela exponent
     * @tparam T the underlying numerical type
     */
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    struct IsSi<Si<m, kg, s, A, K, MOL, CD, T>> {
        /**
         * Type is a SI instance.
         */
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
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator*(T rhs) const -> ThisT {
        return Si<m, kg, s, A, K, MOL, CD, decltype(this->val * rhs)>{this->val * rhs};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator*=(T rhs) -> ThisT & {
        this->val *= rhs;
        return *this;
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T_>
    constexpr auto operator*(T_ lhs, Si<m, kg, s, A, K, MOL, CD, T_> rhs) -> Si<m, kg, s, A, K, MOL, CD, T_> {
        return Si<m, kg, s, A, K, MOL, CD, T_>{lhs * rhs.val};
    }

    // Divide by scalar
    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator/(T rhs) const -> Si<m, kg, s, A, K, MOL, CD, T> {
        return Si<m, kg, s, A, K, MOL, CD, decltype(this->val * rhs)>{this->val / rhs};
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
    constexpr auto Si<m, kg, s, A, K, MOL, CD, T>::operator/=(T rhs) -> ThisT & {
        this->val /= rhs;
        return *this;
    }

    template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T_>
    constexpr auto operator/(T_ lhs, Si<m, kg, s, A, K, MOL, CD, T_> rhs) -> Si<-m, -kg, -s, -A, -K, -MOL, -CD, T_> {
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

} // namespace si

#endif
