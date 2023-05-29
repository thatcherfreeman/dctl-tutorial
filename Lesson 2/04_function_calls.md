# Function Calls

If you want to declare a function in a DCTL, you have to write a function signature. Functions in DCTLs require a few things. They typically look something like this:

```c
__DEVICE__ float tone_map(float x, float a, float b, float c) { ... }
```

Let's go through each word there.

* `__DEVICE__` is simply required at the start of any function signature

* The `float` following `__DEVICE__` is the return type of the function.

* `tone_map` is the name of the function that you'll use whenever you call the function.

* `float x, float a, float b, float c` are the parameters of the function. These are variables that can be used within the function, and indicates that you need to pass four floats into the function when you call it.

* `{ ... }` You must then wrap the statements within the function with some curly braces, and make sure that you return a `float` type variable by the end of the function.

Assuming `input_f` is a `float` declared earlier, this function would then be called something like:

```c
float tone_mapped_result = tone_map(input_f, 1.0, 0.0, 1.0);
```