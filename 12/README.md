# Assignment 12 for June 20th, 2023

The goal of this assignment is to study program optimizations of scalar architectures.


## Exercise 1 (1.5 Points)    

### Description

Assume that during testing of your program on a scalar architecture, you found that the execution time is too high, and you have to optimize it. You suppose that the following extracts significantly impact the execution time of your program.


**a)** `c1` is of type `unsigned`:
```C
unsigned c2 = 32 * c1;
```

**b)** `c1` is of type `unsigned`:
```C
unsigned c2 = 15 * c1;
```

**c)** `c1` is of type `unsigned`:
```C
unsigned c2 = 96 * c1;
```
_Hint_: use shift(s) and addition(s) to replace the multiplication

**d)** `c1` is of type `unsigned`:
```C
unsigned c2 = 0.125 * c1;
```

**e)** `a` is of type `unsigned *`:
```C
unsigned sum_fifth = 0;

for (int i = 0; i < N / 5; ++i) {
    sum_fifth += a[5 * i];
}
```

**f)** `a` is of type `double *`:
```C
for (int i = 0; i < N; ++i) {
    a[i] += i / 5.3;
}
```

**g)** `c1` is of type `float`:
```C
float c2 = -1 * c1;
```
_Hint_: Inquire how IEEE 754 single-precision floating-point numbers are represented in memory.

### Tasks

- Apply strength reduction.
- State under which circumstances the transformation should be applied (e.g. if the cost of performing two additions is less than one multiplication).
- After you have applied strength reduction, compare the assembly code of the original snippets with your transformation. Investigate how the compiler (`gcc`) optimizes the snippets when using `-O3` and whether the compiler uses your transformation or applies another optimization on top of it. You can use [Compiler Explorer](https://godbolt.org/) to carry out this task. The given examples are already available at https://godbolt.org/z/NxEBrD. Note that you can easily navigate to the assembler code for a given input source line by right-clicking, but be aware that the source for one line might be distributed among interleaved instructions.


## Exercise 2 (1.5 Points)

### Description

For each loop iteration instructions such as compare and add operations have to be performed. If the number of executions is sufficiently large this can have an impact on the performance of the program. Investigate the following given code examples along with their task and, for each example, study why the transformation may or may not be beneficial. \
Furthermore, for each example, you are asked to compare the performance counters of the original and the transformed code. Therefore, you should create a small test program for each configuration, compile it with `gcc` using `-O3`, and profile it with `perf` on LCC2.
Note that if not stated otherwise, variables and array elements are of type `int`.

### Tasks

- Apply loop unrolling, increase the workload per iteration. \
Note that you can assume that `N` is odd.
```C
for (int i = 0; i < N - 1; ++i) {
    a[i] = b[i] + b[i + 1];
}
```

- Apply loop-invariant code motion, reduce the number of function calls.\
`a` is of type `double *`
```C
for (int i = 0; i < N; ++i) {
    a[i] *= hypot(0.3, 0.4);
}
```

- Apply loop unswitching, eliminate the if clause inside the loop.
```C
for (int i = 0; i < N; ++i) {
    if (N % 2) {
        a[i] = b[i] + 5;
    } else {
        a[i] = c[i] + 5;
    }
}
```

- Apply loop fission/distribution, reduce the number of instructions per iteration. \
Does this transformation have an impact on the number of cache misses?
```C
for (int i = 0; i < N; ++i) {
    sum_a += a[i];
    sum_b += b[i];
    sum_c += c[i];
}
```

- Apply loop peeling and loop fusion/combination, combine the snippet into a single loop. \
Note that `N` is larger than `0`.
```C
int min = a[0];
for (int i = 1; i < N; ++i) {
    min = (a[i] < min) ? a[i] : min;
}
for (int i = 0; i < N; ++i) {
    sum += a[i];
}
```

- Apply loop splitting, reduce the number of compare instructions per iteration.
```C
for (int i = 0; i < N; ++i) {
    if (i % 2) {
        a[i] = b[i] + 4;
    } else {
        a[i] = c[i] + 5;
    }
}
```

- Apply loop tiling, when addresses are accessed multiple times it is beneficial to work in blocks of the same length as the cache line size. Add loops so that the read and write accesses are limited to one block at a time.\
 You can assume that a macro `BLOCK_SIZE`, which is defined in some boilerplate code, defines a suitable block size for tiling (e.g., `#define BLOCK_SIZE 64 / sizeof(double)`). \
`a`, `b`, and `c` are of type `double`
```C
for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
            c[i][j] = a[i][k] * b[k][j];
        }
    }
}
```

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.