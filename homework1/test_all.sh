#!/bin/bash
uname -a
cd ~/OS/homework1

gcc -o open_glibc open_glibc.c
gcc -o open_sys open_sys.c
gcc -o open_asm open_asm.c
gcc -o getpid_glibc getpid_glibc.c
gcc -o getpid_sys getpid_sys.c
gcc -o getpid_asm getpid_asm.c

count=1000
warmup=100  
sum=0

# Function to calculate average time
calculate_average() {
    local binary=$1
    local label=$2
    sum=0

    # Warm-up runs
    for ((i=1; i<=warmup; i++))
    do
        ./$binary > /dev/null
    done

    # Actual runs
    for ((i=1; i<=count; i++))
    do
        elapsed=$(./$binary | grep "$label" | awk '{print $2}')
        sum=$(echo "$sum + $elapsed" | bc)
    done

    average=$(echo "scale=9; $sum / $count" | bc)
    echo "$label平均耗时: 0$average 秒"
}

# Run tests and calculate averages
calculate_average "open_glibc" "open_glibc耗时"
calculate_average "open_sys" "open_syscall耗时"
calculate_average "open_asm" "open_asm耗时"
calculate_average "getpid_glibc" "getpid_glibc耗时"
calculate_average "getpid_sys" "getpid_syscall耗时"
calculate_average "getpid_asm" "getpid_asm耗时"