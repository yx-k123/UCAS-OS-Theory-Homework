#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    struct timespec start, end;
    long seconds, nanoseconds;
    double elapsed;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    pid_t pid = getpid();
    clock_gettime(CLOCK_MONOTONIC, &end);

    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;
    
    printf("getpid_glibc耗时: %.9f 秒\n", elapsed);
    return 0;
}