# SI
Library for providing unit support using the C++ type system. A unit can be uniquely represented by a 7-tuple of exponents for the basis units 
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

## Requirements
 * **Compiler:** The library requires a recent C++ compiler with support for C++17, for example GCC-7 or later. Preferably a compiler with support for C++20 is used to enable all features.
 * **Build System:** The library is intended to be built with CMake (Version 3.10 or later)

## Examples
### Literals

#### Unit Prefixes

### Operations

### Printing Types

#### Support for well-known Units

### STL-Support

## Configuration
default_type

## Known Problems
 * The library does not handle angles, as they are not part of the SI system
 * As Kilograms are a base unit with unit prefix the corresponding literals are strange: one million grams is `1_k_kilogram` for example.
 * Non-Integer Exponents, as template arguments can only be of integral type
