# Pointer Tips
HINT: For declarations of Pointers in DCTLs need to use the `__PRIVATE__` qualifier.

## Example 1: Function Arguments
In C, you might write:
```c
float some_func(float *param) { ... }
```

In DCTL we will instead write:
```c
__DEVICE__ float some_func(__PRIVATE__ float *param) { ... }
```


## Example 2: Casts and Variable Declarations
If we were to make a cast:

C would look like:
```c
float bar = 5.0;
float *foo = (float *) &bar;
float out = some_func(foo);
```

DCTL:
```c
float bar = 5.0;
__PRIVATE__ float *foo = (__PRIVATE__ float *) &bar;
float out = some_func(foo);
```
