#!/bin/bash
uname -r
cd ~/OS/homework1

gcc -o open_glibc open_glibc.c
gcc -o open_sys open_sys.c
gcc -o open_asm open_asm.c
gcc -o getpid_glibc getpid_glibc.c
gcc -o getpid_sys getpid_sys.c
gcc -o getpid_asm getpid_asm.c

count=1000
sum=0

for ((i=1; i<=count; i++))
do
    elapsed=$(./open_glibc | grep "open_glibc耗时" | awk '{print $2}')
    sum=$(echo "$sum + $elapsed" | bc)
done

average=$(echo "scale=9; $sum / $count" | bc)
echo "open_glibc平均耗时: 0$average 秒"

sum=0

for ((i=1; i<=count; i++))
do
    elapsed=$(./open_sys | grep "open_syscall耗时" | awk '{print $2}')
    sum=$(echo "$sum + $elapsed" | bc)
done

average=$(echo "scale=9; $sum / $count" | bc)
echo "open_syscall平均耗时: 0$average 秒"

sum=0
for ((i=1; i<=count; i++))
do
    elapsed=$(./open_asm | grep "open_asm耗时" | awk '{print $2}')
    sum=$(echo "$sum + $elapsed" | bc)
done

average=$(echo "scale=9; $sum / $count" | bc)
echo "open_asm平均耗时: 0$average 秒"

sum=0
for ((i=1; i<=count; i++))
do
    elapsed=$(./getpid_glibc | grep "getpid_glibc耗时" | awk '{print $2}')
    sum=$(echo "$sum + $elapsed" | bc)
done
average=$(echo "scale=9; $sum / $count" | bc)
echo "getpid_glibc平均耗时: 0$average 秒"

sum=0
for ((i=1; i<=count; i++))
do
    elapsed=$(./getpid_sys | grep "getpid_syscall耗时" | awk '{print $2}')
    sum=$(echo "$sum + $elapsed" | bc)
done
average=$(echo "scale=9; $sum / $count" | bc)
echo "getpid_syscall平均耗时: 0$average 秒"

sum=0
for ((i=1; i<=count; i++))
do
    elapsed=$(./getpid_asm | grep "getpid_asm耗时" | awk '{print $2}')
    sum=$(echo "$sum + $elapsed" | bc)
done
average=$(echo "scale=9; $sum / $count" | bc)
echo "getpid_asm平均耗时: 0$average 秒"
