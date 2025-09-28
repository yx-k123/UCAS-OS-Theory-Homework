# System Call Performance Benchmarking

## Overview

This project benchmarks the performance of different implementations of system calls (`open` and `getpid`) using:

- **glibc**: Standard library implementation.
- **syscall**: Direct system call using the `syscall` function.
- **asm**: Inline assembly to directly invoke the system call.

The script `test_all.sh` automates the compilation and execution of the benchmarks, and calculates the average execution time for each implementation.

## Files

- **`open_glibc.c`**: Benchmark for `open` using glibc.
- **`open_sys.c`**: Benchmark for `open` using `syscall`.
- **`open_asm.c`**: Benchmark for `open` using inline assembly.
- **`getpid_glibc.c`**: Benchmark for `getpid` using glibc.
- **`getpid_sys.c`**: Benchmark for `getpid` using `syscall`.
- **`getpid_asm.c`**: Benchmark for `getpid` using inline assembly.
- **`test_all.sh`**: Script to compile, execute, and calculate average execution times.

## Usage

   ```bash
   cd ~/OS/homework1
   source test_all.sh
   ```
