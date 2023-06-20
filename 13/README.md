# Assignment 13 for June 27th, 2023

The goal of this assignment is to revisit matrix multiplication.

## Exercise 1 (3 Points)

### Description

Your goal is to parallelize and optimize matrix multiplication with all the knowledge acquired during this semester.

### Tasks

- Examine the given sequential implementation [mm.c](mm.c) and parallelize it using OpenMP.
- Optimize the parallel implementation with all the knowledge acquired during this semester. Include at least:
    1) loop transformations (1 Point)
    2) vectorization (1 Point) - note that auto-vectorization of the compiler does not count!
    3) thread parallelism-specific optimizations (1 Point)
- For each of the sub-tasks above, state a) which improvements you expect, b) check whether the optimization is applied successfully, and c) provide measurements that show the benefit. This can either be measured individually (only one optimization at a time) or incrementally.
- Use the already provided time measurement functions in the code and do not alter them.
- Benchmark the sequential program and the parallelized version using N=2048 for 8 threads on LCC2 and enter the results in the comparison spreadsheet linked on Discord. Fast solutions under 5.5 seconds will get 1 extra point, for solutions under 3.5 seconds you will even get a total of 2 extra points.

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
