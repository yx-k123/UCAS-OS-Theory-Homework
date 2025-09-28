#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct timespec start, end;
    long seconds, nanoseconds;
    double elapsed;
    int fd;

    const char *filename = "test_open.txt";
    int flags = O_RDONLY;

    clock_gettime(CLOCK_MONOTONIC, &start);

    asm volatile(
        "movq $2, %%rax\n\t"        // SYS_openat
        "movl $-100, %%edi\n\t"       // AT_FDCWD 
        "movq %1, %%rsi\n\t"          // filename
        "movl %2, %%edx\n\t"          // flags
        "movl $0, %%r10d\n\t"         // mode (0, 因为只读)
        "syscall\n\t"
        "movl %%eax, %0\n\t"
        : "=r"(fd)
        : "r"(filename), "r"(flags)
        : "rax", "rdi", "rsi", "rdx", "r10"
    );

    clock_gettime(CLOCK_MONOTONIC, &end);

    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;

    if (fd == -1) {
        perror("asm syscall openat");
        return 1;
    }
    close(fd);

    printf("open_asm耗时耗时: %.9f 秒\n", elapsed);

    return 0;
}