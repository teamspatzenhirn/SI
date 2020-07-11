# SI
Library for providing unit support using the C++ type system. Similar to [Boost.Units](https://www.boost.org/doc/libs/1_65_0/doc/html/boost_units.html) but
without external dependencies and no added overhead (even during compilation) for features that are not used.

A unit can be uniquely represented by a 7-tuple of exponents for the basis units 
(second, metre, kilogram, ampere, kelvin, mol and candela). The SI library is based around this representation, additonally there is a template parameter
which specifies the underlying numerical type, the primary class (template) is defined as:
```c++
template<int m, int kg, int s, int A, int K, int MOL, int CD, typename T>
class Si {
    ...
};
```
All operations that are well-defined are implemented. Possible operation (non complete) are:
 * Addition/Subtraction: if both arguments have the same 7 exponents
 * Multiplikation/Division: always, the resulting type has the sum/difference of the individual exponents
 * Scaling with a unitless factor and unary minus (i.e. negative)
 * Equality: only for same exponents, then equality of the underlying type is used
 * Size-Relation: only for same exponents, then size relation of the underlying type is used
 * Some STL Function, for example `std::sqrt`, implementation depending on the function

## Examples
### Literals
There are literals for all base units and some derived units.
They can be used with both floating point and integer constants.

Examples:
```c++
auto v = 10_meter / 1_second;
auto strangeUnit = 1_kilogram / 10_ampere * 1_kelvin * 1_candela;
```

#### Unit Prefixes
[SI-Unit Prefixes](https://en.wikipedia.org/wiki/Metric_prefix) 
are supported as well for all units:
```c++
auto very_fast = 1_k_meter / 1_m_second; // Kilometer / Millisecond
auto rather_slow = 1_mu_meter / 1_Y_second; // Micrometer / Yotasecond
```

### Operations

### Printing Types

#### Support for well-known Units

### STL-Support

## Requirements
 * **Compiler:** The library requires a recent C++ compiler with support for C++17, for example GCC-7 or later. Preferably a compiler with support for C++20 is used to enable all features.
 * **Build System:** The library is intended to be built with CMake (Version 3.10 or later)


## Configuration
For the literals and the predefined constants the underlying type is fixed to type `si::default_type` which is `double` by default.
This can be changed by setting the `SI_DEFAULT_TYPE` define to another type. This can either be done manually before including any part of the library
or by setting it directly using a compiler flag (e.g. `-DSI_DEFAULT_TYPE=float`) or your build system.

## Known Problems
 * The library does not handle angles, as they are not part of the SI system
 * As Kilograms are a base unit with unit prefix the corresponding literals are strange: one million grams is `1_k_kilogram` for example.
 * Non-Integer Exponents are not supported, as template arguments can only be of integral type
