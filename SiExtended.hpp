/**
 * @file SiExtended.hpp
 * @author paul
 * @date 23.03.19
 * @brief Definition of the types, constants and literals for derived types.
 */

#ifndef SI_SIEXTENDED_HPP
#define SI_SIEXTENDED_HPP

#include <iostream>

#include "SiImpl.hpp"
#include "SiGenerator.hpp"

SI_CREATE_UNIT(Speed, speed, 1, 0, -1, 0, 0, 0, 0)
SI_CREATE_UNIT(Acceleration, acceleration, 1, 0, -2, 0, 0, 0, 0)
SI_CREATE_UNIT(Volt, volt, 2, 1, -3, -1, 0, 0, 0)
SI_CREATE_UNIT(Hertz, hertz, 0, 0, -1, 0, 0, 0, 0)

#endif
