# Assignment 3 for April 18th, 2023

The goal of this assignment is to get to know the basic functionality of OpenMP.

## Exercise 1 (1 Point)

### Description

This exercise consists of implementing the Monte Carlo Pi approximation of assignment 02 in OpenMP.    

### Tasks

- Implement parallel versions of the Monte Carlo Pi approximation of assignment 02 using OpenMP. In total, three different versions using the following OpenMP constructs should be provided:
    - `critical` section
    - `atomic` statement
    - `reduction` clause
- To increase the performance difference among these versions, make sure you increment the samples counter directly, without aggregating to private variables first.
- Benchmark your parallel implementations with 1, 2, 4, and 8 threads on LCC2 using n=500,000,000 using OpenMP's time measurement function. What can you observe? How do those results compare to your measurements in Assignment 02?
- The tool `/usr/bin/time` can be used to get useful information on the properties of a program's execution, e.g. its execution time or the maximum amount of main memory used. Measure the execution time of your OpenMP implementation using `/usr/bin/time -v <program_name>`. Take a look at the output, specifically "user time" and "elapsed (wall clock) time". How do they differ? Does either of them match the time measurement function of OpenMP?
- Add the wall clock time measurements for 8 threads on LCC2 to the comparison spreadsheet linked on Discord.

## Exercise 2 (1 Point)

### Description

This exercise deals with performance analysis and improvement of a given [code](ex2/ex2.c). The program reads a matrix size n from the command-line. Then two square matrices a and b of size n\*n are filled with random numbers. Finally, the program should print the sum of all elements of matrix c and the wall clock time after the matrix multiplication c=a\*b was conducted. 

### Tasks

- Are there any (performance) issues in the given code? Document your findings.
- Improve the performance of the given source code. 
- Benchmark your modification of the code and the original implementation with 1, 2, 4, and 8 threads on LCC2 using n=1,500. Has your effort paid off?
- Enter your shortest wall clock time for 8 threads and n=1,500 on LCC2 to the comparison spreadsheet linked on Discord.

## Exercise 3 (1 Point)

### Description

In this exercise, you are asked to investigate the effect of false sharing in multi-threaded programs.

### Tasks

- Implement (or copy from Exercise 1) a parallel Monte Carlo PI version that uses a local sum approach, i.e. that first aggregates to a per-thread private variable before using `atomic` to aggregate the entire sum of samples.
- Create a second version that does not rely on private variables but a single array where each thread gets one element for local sum storage. In memory, the data layout should then look like `[thread_0][thread_1][_thread_2][...]`.
- Create a third version that continues to use a single array but add padding to it, ensuring that the individual local sum storage locations are separated by unused data, e.g. `[thread_0][N_unused_bytes][thread_1][N_unused_bytes][thread_2][...]`. How you achieve this padding is up to you (there are several implementation possibilities). How large should the padding distance ideally be?
- Benchmark all three versions (private variable, array, array with padding) and document your results. Also check the L1 cache misses using `perf stat`. Feel free to also check for this effect on your local machines and report the data (including the CPU type!).
- Enter the wall clock time of each version for 8 threads for n=100,000,000 on LCC2 to the comparison spreadsheet linked on Discord.

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
