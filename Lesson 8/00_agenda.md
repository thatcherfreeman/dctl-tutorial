# Other DCTL Features

* `.h` files
* `__CONSTANT__`
* `#define`
* `DEFINE_LUT`

## Header Files
Pros:
* Helps you maintain your code, reduce code duplication, organize code into different files

Cons:
* Makes your DCTL less portable as a single file
* May require others to maintain the same directory structure as you.

## CONSTANT
Pros:
* Allows you to declare global variables that are read-only

Cons:
* Sometimes it's hard to understand code when it's referencing global variables defined somewhere else.
* Global variables use up some memory, not a huge concern usually though.

## Define
Pros:
* Zero cost abstraction, code is substituted in at compile time.
* Can help you keep your code very short and write type-agnostic macros

Cons:
* Very easy to introduce bugs if you're not super careful.
* Bugs usually result in cryptic error messages.

## DEFINE_LUT
Pros:
* Allows you to include a Cube LUT in your code.

Cons:
* Cube LUTs are hard to interpret
* Inline LUTs make your DCTL enormous
* Reference LUTs (where you specify a path to a LUT) require that your DCTL and that LUT maintain a certain relative directory structure.