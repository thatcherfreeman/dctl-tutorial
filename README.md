# DCTL Tutorial
These are the supporting agenda and completed DCTL files for my DCTL Tutorial Series.

## DCTL Coding Best Practices:
Below is a short list of best practices when coding your DCTLs to make sure they operate correctly on all platforms. If there is something omitted from this list, feel free to create an Issue or a Pull Request and let me know!

1. Don't use `{ ... }` to initialize variables EXCEPT on a line where the variable is declared
1. Don't pass `{ ... }` into a function. Make maker functions for structs similar to make_float3.
1. Don't pass static strings into a function that expects a `char[]`. Assign that string to a `char[]` variable first.
1. Don't use the word `transform` anywhere except in the transform function name
1. Don't use the word `return` anywhere except in return statements
1. Declare pointers like `__PRIVATE__ int *foo` or they won't work on Mac
1. `_powf()` has different behaviors for negative base on Mac and windows, so make sure you wrap it in your own function to be explicit about what you want it to do for negative base
1. Make sure functions are always defined (or prototyped) before they are called
1. Don't break the `DEFINE_UI_PARAMS` statements into multiple lines
1. Don't break the `transform( ... )` function signature into multiple lines
1. Don't put parentheses in the names of your `DEFINE_UI_PARAMS` parameters
1. For the sake of my DCTL interpreter, don't pass integers into the built-in functions/macros that expect floats. Use `_log2f(3.0)` instead of `_log2f(3)`. The fusion devs forgot to typecast them
1. Preferably, avoid the use of `__CONSTANT__`, it's hard to get the type checking to allow passing these into functions