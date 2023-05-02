# Assignment 6 for May 9th, 2023

The goal of this assignment is to gain more experience in parallelizing programs with OpenMP that are not embarrassingly parallel.

## Exercise 1 (1 Point)

### Description

In this exercise, you are asked to implement a program that computes the exclusive prefix sum for arrays of type `int32_t *`. The following snippet computes the exclusive prefix sum. 
```C
b[0] = 0;
for (int i = 1; i < n; i++) {
    b[i] = b[i - 1] + a[i - 1];
}
```
For example, the exclusive prefix sum of `[2, 1, 5, 6, 3]` is `[0, 2, 3, 8, 14]`. The input for your program should be the size `n` of the array `a`. Then the array `a` is filled with `n` ones, the exclusive prefix sum is computed and, finally, the execution time and the last value of array `b` is printed to `stdout`.


### Tasks
- Implement the sequential program.
- Implement a parallel version of the program. 
- Benchmark the sequential implementation against the parallel version with 8 threads on LCC2. Has your effort paid off?
- Enter the wall clock time of the sequential version and the parallel version for 1 and 8 threads for N=1e9 on LCC2 to the comparison spreadsheet linked on Discord.

## Exercise 2 (2 Points)

### Description

The [N-Queens problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle) is a puzzle in which n queens must be placed on an n\*n chessboard such that the queens do not threaten each other (e.g., there is at most one queen in each row, column, and diagonal). 

### Tasks
- Implement a sequential version that calculates the number of solutions to the N-Queens problem. The input parameter for the program is the number N, and its output is the number of possible solutions. 
- Create a parallel version of the sequential program using OpenMP.
- Benchmark the sequential and the parallel version with 1, 2, 4, and 8 threads on LCC2 using the sizes 8, 10, and 12. Has your effort paid off?
- Enter the wall clock time of the sequential version and the parallel version for 1 and 8 threads for N=12 on LCC2 to the comparison spreadsheet linked on Discord.


## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.