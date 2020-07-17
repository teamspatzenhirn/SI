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
 * Multiplication/Division: always, the resulting type has the sum/difference of the individual exponents
 * Scaling with a unitless factor and unary minus (i.e. negative)
 * Equality: only for same exponents, then equality of the underlying type is used
 * Size-Relation: only for same exponents, then size relation of the underlying type is used
 * Some STL Function, for example `std::sqrt`, implementation depending on the function

## Examples
If you only require certain features it is sufficient to only include the headers listed in the respective section.
For convenience there is also a `Si.hpp` header which includes all headers and simplifies the includes, the
downside is additional compilation time for features that you might not use.

### Basic usage
There are types and constants for all base units and some derived units. For only the base units include
`SiBase.hpp`, for the derived units include `SiExtended.hpp`.

Example
```c++
Meter<> dist = 1 * meter + 2 * meter;
Speed<> v = dist / (3 * second);
Second<> time = v * 10 * second;
```
### Literals
There are additonally literals for all base units and some derived units.
They can be used with both floating point and integer constants.

Examples:
```c++
using namespace si::literals;

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

### Scalars
There is also a `Scalar` type for seamless interaction with unitless types:
```c++
Scalar<> s = 1_scalar + 1 * scalar;
auto normalVariable = static_cast<si::default_type>(s); // By default of type double
```

If your compiler supports C++20 and 
"[`explicit(bool)`](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0892r2.html)" you do not need the explicit
casts. The example simplifies to:
```c++
Scalar<> s = 1 + 1;
double normalVariable = s;
```

### Printing Types
SI natively supports printing variables with their respective unit. The `std::ostream operator<<` is
overloaded for the types. For printing types include the `SiPrinter.hpp` header.

```c++
auto v = 10_meter / 1_second;
auto density =  2_kilogram / (3_meter * 4_meter * 5_meter);
std::cout << v << std::endl; // Prints: 10 m / s
std::cout << density << std::endl; // Prints: 30 m^3 / kg
```

### STL-Support
Some STL functions are overloaded for SI types. In their implementation the
functions use the respective functions of the underlying type so these functions
need to exist. Include `SiStl.hpp` to use the functions. Namely the functions
are:
 * `std::sqrt` requires for all unit exponents to be dividable by two
 * `std::abs` works for all SI types
 * `std::round` works for all SI types
 * `std::isnan` works for all SI types
 * `std::atan2` requires that both arguments are of the same type
 
New functions can be easily added in the `SiStl.hpp` header (feel free to create a pull request!).

Example:
```c++
auto v_x = 10_meter / 1_second;
auto v_y = -20_meter / 1_second;

auto v_y_abs = std::abs(v_y);
auto v = std::sqrt(v_x * v_x + v_y * v_y); 
```

### Adding more units
If a unit is used multiple times it can be comfortable to add a custom type for this unit, for this use the 
`SiGenerator.hpp` header which provides macros for this. The macro `SI_CREATE_UNIT(Name, name, m, kg, s, A, K, Mol, CD)`
takes `Name` (used for the type), `name` used for the literals and constants and the seven exponents as arguments to 
create the correct type, constant and literals for all unit-prefixes. When using the macro be sure to not be in any 
namespace as this will put the type in this namespace as well.

Feel free to add the unit to `SiExtended.hpp` and create a pull request!

### Printing custom types
Many units have well known names which could be printed instead of using the canonical form consisting only of
base units. For example instead of the the unit `1 m^2 kg s^-3` (which you probably did not recognize as  a volt), 
one would prefer to print `1 V`.

For this there is another set of macros to make it as easy as possible to add new types. Before adding the printer functions
be sure that the type is added to the `SiExtended.hpp` function. Next open the file `SiPrinterExtended.hpp` and add
the line `SI_CUSTOM_PRINTER_DEC(Volt)` this will generate the correct declaration for your type, the argument,
`Volt` in this case, is the name of the type you defined earlier. Next add the line `SI_CUSTOM_PRINTER_IMPL(Volt, "V")`
to `SiPrinterExtended.cpp`. The first argument is, once again, the type, the second argument is the name of your
type, so the string that is printed.

Be sure to include `SiPrinterExtended.hpp` (or `Si.hpp` for all headers like explained above) to use this specialization, 
and recompile the code library if this is not automatically done by your build system. 
Once again: feel free to create a pull request!

## Requirements
 * **Compiler:** The library requires a recent C++ compiler with support for C++17, preferably a compiler with support 
    for C++20 is used to enable all features.
    
    Supported compilers are:
    * GCC >= 7
    * Clang >= 6
 * **Build System:** The library is intended to be built with CMake (Version 3.12 or later)


## Configuration
For the literals and the predefined constants the underlying type is fixed to type `si::default_type` which is `double` by default.
This can be changed by setting the `SI_DEFAULT_TYPE` define to another type. This can either be done manually before including any part of the library
or by setting it directly using a compiler flag (e.g. `-DSI_DEFAULT_TYPE=float`) either directly or via
your build system of choice.

## Known Problems (that will not get fixed)
 * The library does not handle angles, as they are not part of the SI system
 * As Kilograms are a base unit with unit prefix the corresponding literals are strange: one million grams is `1_k_kilogram` for example.
 * Non-Integer Exponents are not supported, as template arguments can only be of integral type
