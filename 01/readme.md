# Assignment 1 for March 21st 2023

The goal of this assignment is to get a first grasp on the scaling characteristics of parallel programs.

## Exercise 1 (1.5 Points)

### Description

Amdahl's law is one of the most important properties of parallel programs.

### Tasks

- How is the speedup of a parallel program defined?
- What is the formal definition of Amdahl's law and what relationship does it describe for parallel programs (explain in your own words)? Why/How is this significant?
- Compute the theoretical speedup of a program that spends 10% of its time in unparallelizable, sequential regions for 6 cores and for a hypothetically unlimited number of cores.
- Compute the theoretical speedup of a program that spends 20% of its time in unparallelizable, sequential regions for 6 cores and for a hypothetically unlimited number of cores.
- Given an algorithm of time complexity O(n^3). How large (in %) can the unparallelizable, sequential region be at most, such that a speedup of 10 can be achieved using 64 cores?

## Exercise 2 (1.5 Points)

This exercise consists in running and comparing two parallel implementations of the same algorithm.

### Description

There are usually multiple implementations to choose from the putting an algorithm into source code. In this exercise, we will compare the behavior of three different parallel implementations that all do the same thing: They simply sum up numbers, measure the time required to do so, and finally both print the calculated sum and the time.

### Tasks

- Compile the three given source codes `slow.c`, `medium.c`, and `fast.c` with the compiler flag `-fopenmp` to enable OpenMP parallelism.
- Vary the number of cores by setting the environment variable `OMP_NUM_THREADS` before running the program, e.g. `OMP_NUM_THREADS=1 ./slow`. Measure the execution times of all three programs for all numbers of cores your personal computing system (e.g. PC or laptop) offers.
- See if you can reduce the execution times even further by trying out different compiler flags (optimization flags).
- Create a table and figures that illustrate the measured data and study them. What effects can you observe?
- How stable are the measurements when running the experiments multiple times?
- Enter the shortest execution times for 1 and 8 threads measured on the LCC2 cluster for each code to the performance comparison sheet linked on Discord.

## General Notes

All the material required by the tasks above (e.g. code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your own measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
