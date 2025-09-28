#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <sys/types.h>

int main() {

    struct timespec start, end;
    long seconds, nanoseconds;
    double elapsed;
    pid_t pid;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    asm volatile(
        "movq $39, %%rax\n\t"   // SYS_getpid = 39
        "syscall\n\t"
        "movl %%eax, %0\n\t"
        : "=r"(pid)
        :
        : "rax"
    );
    clock_gettime(CLOCK_MONOTONIC, &end);

    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;
    
    printf("getpid_asm耗时: %.9f 秒\n", elapsed);
    return 0;
}