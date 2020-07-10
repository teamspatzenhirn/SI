# SI
Library for providing unit support using the C++ type system.

## Requirements
 * **Compiler:** The library requires a recent C++ compiler with support for C++17, for example GCC-7 or later. Preferably a compiler with support for C++20 is used to enable all features.
 * **Build System:** The library is intended to be built with CMake (Version 3.10 or later)

## Examples
### Literals

### Operations

### Printing Types

#### Support for well-known Units

### STL-Support

## Known Problems
 * The library does not handle angles, as they are not part of the SI system
 * As Kilograms are a base unit with unit prefix the corresponding literals are strange: one million grams is `1_k_kilogram` for example.
