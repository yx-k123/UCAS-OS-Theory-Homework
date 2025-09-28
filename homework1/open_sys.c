#define _POSIX_C_SOURCE 199309L
#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>


int main()
{
    struct timespec start, end;
    long seconds, nanoseconds;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);
    int fd = syscall(SYS_open, "test_open.txt", O_RDONLY);
    clock_gettime(CLOCK_MONOTONIC, &end);

    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;

    if (fd == -1) {
        perror("syscall SYS_open");
        return 1; // Error opening file
    }
    close(fd);

    printf("open_syscall耗时: %.9f 秒\n", elapsed);

    return 0;
}