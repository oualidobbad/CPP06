# CPP06

C++ Module 06: C++ casting operators — scalar type conversion, pointer serialization via `reinterpret_cast`, and runtime type identification with `dynamic_cast`.

## Project Overview
- What it does: explores the four C++ cast operators through three exercises covering type conversion, serialization, and RTTI.
- Core themes: `static_cast`, `dynamic_cast`, `reinterpret_cast`, type detection, edge case handling.

## Architecture & Design
- **ex00 (ScalarConverter)**: static `convert(std::string)` method detects input type (char/int/float/double/pseudo-literal) and prints conversions to all four scalar types.
  - Type detection via `enum type { CHAR, INTEGER, DOUBLE, FLOAT, PSEUDO_LITERAL, OUT_OF_RANGE, ... }`.
  - Handles special values: `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`.
  - Edge cases: non-displayable chars, overflow detection, precision formatting.
- **ex01 (Serializer)**: `static uintptr_t serialize(Data*)` via `reinterpret_cast`; `static Data* deserialize(uintptr_t)` — round-trip pointer serialization.
- **ex02 (Base/A/B/C)**: `Base` with virtual destructor; `generate()` randomly creates A, B, or C; `identify(Base*)` and `identify(Base&)` use `dynamic_cast` to determine the actual type.

## Core Concepts (with code)
- Scalar type detection and conversion:
```cpp
// ScalarConverter.hpp
class ScalarConverter {
public:
    static void convert(std::string str);  // non-instantiable utility
};
enum type { CHAR, INTEGER, DOUBLE, FLOAT, PSEUDO_LITERAL, OUT_OF_RANGE };
type getTypeOfString(std::string str);  // classifier
void converter(std::string str, scalarTypes& scalar, type typ);
```
- RTTI identification:
```cpp
// ex02 — identify via dynamic_cast
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A";
    else if (dynamic_cast<B*>(p)) std::cout << "B";
    else if (dynamic_cast<C*>(p)) std::cout << "C";
}
```

## Code Walkthrough
1) ex00: `getTypeOfString()` classifies input; `converter()` casts to target types; `print()` formats output with precision and edge markers (`impossible`, `Non displayable`).
2) ex01: `serialize()` = `reinterpret_cast<uintptr_t>(ptr)`; `deserialize()` = `reinterpret_cast<Data*>(raw)`. Verify original pointer == deserialized.
3) ex02: `generate()` uses `rand() % 3` to pick A/B/C; pointer-based identify uses NULL check; reference-based uses `try/catch` (failed `dynamic_cast<T&>` throws `std::bad_cast`).

## Installation & Setup
- `make` per exercise (C++98).
- `./convert <value>` for ex00.

## Technical Deep Dive
- `ScalarConverter` has private constructor — purely static utility class.
- `reinterpret_cast` is the only cast that converts between pointer and integer types.
- `dynamic_cast` requires polymorphic base (virtual destructor) and RTTI enabled.

## Improvements & Future Work
- Add `const_cast` exercise for completeness.
- Handle locale-specific decimal separators in ScalarConverter.

## Author
Oualid Obbad (@oualidobbad)