/**
 * @file SiUtil.hpp
 * @author paul
 * @date 17.07.20
 * Implementation of utilities for SI
 */
#ifndef SI_SIUTIL_HPP
#define SI_SIUTIL_HPP

#if __cpp_conditional_explicit
    #define EXPLICIT(expr) explicit(expr)
#else
    #define EXPLICIT(expr) explicit
#endif

namespace si { namespace util {
    template <typename T, bool trivialCopyable>
    struct CondCRefImpl {
        using type = T;
    };

    template <typename T>
    struct CondCRefImpl<T, false> {
        using type = const T&;
    };

    /**
     * Conditional const reference:
     * Returns T if sizeof(SIZE_T) is less than the word size of your system, else returns const T&
     * @tparam T the type to return
     * @tparam SIZE_T the type used for checking, is T by default, in some cases it is necessary to specify a different
     * type here.
     */
    template <typename T, typename SIZE_T = T>
    using CondCRef = CondCRefImpl<typename std::remove_reference<T>::type, sizeof(SIZE_T) <= sizeof(std::size_t)>::type;
}}

#endif
