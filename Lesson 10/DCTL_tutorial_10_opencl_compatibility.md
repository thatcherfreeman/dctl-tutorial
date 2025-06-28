# Making your code work on OpenCL

## `_mix()` considered unsafe
`_mix` is unsafe, need to declare `_mixf3()` and `mixf()` functions to avoid issues with ambiguity of `_mix`.

```c

__DEVICE__ float mixf(float x, float y, float a) {
    return x * (1.0 - a) + y * a;
}

__DEVICE__ float2 mixf2(float2 x, float2 y, float a) {
    return make_float2(mixf(x.x, y.x, a), mixf(x.y, y.y, a));
}

__DEVICE__ float3 mixf3(float3 x, float3 y, float a) {
    return make_float3(mixf(x.x, y.x, a), mixf(x.y, y.y, a), mixf(x.z, y.z, a));
}

__DEVICE__ float4 mixf4(float4 x, float4 y, float a) {
    return make_float4(mixf(x.x, y.x, a), mixf(x.y, y.y, a), mixf(x.z, y.z, a), mixf(x.w, y.w, a));
}
```

## `_fmaxf()` and some other functions is unsafe with double constant numbers
If you have code like `_fmaxf(x_float, 0.0)`, the OpenCL compiler chooses between several different versions of `_fmaxf` that have different types for each argument, IE `fmaxf(float x, float y)`, `fmaxf(double x, double y)`. It interprets `0.0` as a double, so when `x` is a single precision float variable and `y` is a double precision float, it gets confused and can't resolve a single version of `fmaxf` to use. I think this only occurs for built-in math functions that have multiple arguments.

This is true with several of the built in functions. Below is a non-exhaustive list:
 * `_powf()`
 * `_clampf()`
 * `_fmaxf()`
 * `_fminf()`
 * `_mix()`
 * `_fmod()`

#### Bad:
```c
float x = p_R;
_fmaxf(x, 1.0);
```

#### Good:
```c
// option 1
float x = p_R;
float y = 1.0; // implicitly casts the double 1.0 to a float.
_fmaxf(x, y);

// option 2
float x = p_R;
_fmaxf(x, 1.0f); // include an f so that it's deliberately a float

// option 3
__DEVICE__ float maxf(float x, float y) {
    return _fmaxf(x, y);
}
float x = p_R;
maxf(x, 1.0);
```

## Putting `enum` everywhere
Suppose you have some `enum` like:

```c
enum my_enum_e {
    VALUE1,
    VALUE2
};
```

All type specifiers must then have `enum` in it, IE:

```c
// Good
enum my_enum_e foo = VALUE2;

__DEVICE__ float do_something(enum my_enum_e param1)
```
Don't do the below:
```c
// Works on CUDA and Metal, but not OpenCL
my_enum_e foo = VALUE2;

__DEVICE__ float do_something(my_enum_e param1)
```

## Don't use the word `global`

As said in the title, OpenCL does not like variables named `global`, so watch out.

```c
// Don't do either of these:
float global = 1.0;
float foo = global;
```


## Don't declare variables with `__TEXTURE__`
You can have functions where an argument is a `__TEXTURE__`.

```c
// Okay
__DEVICE__ float do_something(__TEXTURE__ curr_chan, int p_X, int p_Y) { ... }

float foo = do_something(p_TexR, p_X, p_Y);
```

You can't make temporary variables like this though:
```c
// Bad
__TEXTURE__ curr_chan = p_TexR;
float foo = do_something(curr_chan, p_X, p_Y);
```

## Don't declare variables in a Switch Case block.
As title, don't do this:
```c
// Bad
switch (condition) {
    case 1:
        float foo = x;
        return foo;
}
```
However, if variables are declared in advance, prior to the switch statement, things seem to work okay
```c
// Okay
float foo;
switch (condition) {
    case 1:
        foo = x;
        return foo;
}
```

## Don't do arithmetic operations between float2, float3 and a double
Don't do this:
```c
float2 foo = make_float2(3.0, 4.0);
(foo + 1.0) * 0.5;
```

Do this:
```c
float2 foo = make_float2(3.0, 4.0);
(foo + 1.0f) * 0.5f;
```

## Don't override existing OpenCL functions
Don't do this:
```c
__DEVICE__ float abs(float x) {
    return x > 0 ? x : x * -1.0f;
}
```
Because `abs` is already defined in opencl. Instead, call the function something like `absf()`.
