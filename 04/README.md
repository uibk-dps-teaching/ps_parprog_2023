# Assignment 4 for April 25th, 2023

The goal of this assignment is to gain more experience in parallelizing programs with OpenMP.

## Exercise 1 (1 Point)

### Description

This exercise consists of exploring the effects of OpenMP thread affinity.

### Tasks

- Write an OpenMP program that atomically increments an `int` in a parallel loop for a large number of iterations, i.e. such that the program takes at least 2 seconds to execute. Have the program print the time required to process the entire loop. Compile your program with gcc 10.3.0 and optimization level `-O3`.
- Run your program with 4 threads. Explore the affinity features of OpenMP 4.0 to change the way threads are mapped to cores, e.g. using a single CPU only or using both CPUs. Explain the affinity settings that you chose.
- Benchmark your program with these affinity settings. What can you observe?

## Exercise 2 (1 Point)

### Description

This exercise deals with the OpenMP flush directive and why it can be necessary.

### Tasks

- Examine [flush.c](flush.c) and explain what the code does from an abstract, high-level perspective. What should happen here?
- Compile this code with optimization level `-O3`. Run it in an interactive job (e.g. using `salloc --exclusive --tasks-per-node=1 --cpus-per-task=1 srun --pty bash`) in a loop many times (e.g. write a loop in bash that executes it 1000 times). Run this loop repeatedly. What can you observe? **Note: Please quit your interactive job once you are done!**
- Does this code require any `#pragma omp flush` directives? If it does, where are they necessary? If it does not, why not?

## Exercise 3 (1 Point)

### Description

In this exercise, you will implement and parallelize merge sort.

### Tasks

- Write an implementation of merge sort. Provide both a sequential and a parallel version.
- Explain the OpenMP constructs you used for parallelization and why. Be precise, address every pragma and explain why it is necessary and what it does.
- Benchmark your program for several numbers of threads and problem sizes. What can you observe?
- Enter the wall clock time of the sequential version, and the parallel version for 1 and 8 threads for n=100,000,000 on LCC2 to the comparison spreadsheet linked on Discord. 

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
