#define _POSIX_C_SOURCE 199309L
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    struct timespec start, end;
    long seconds, nanoseconds;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);
    int fd = open("test_open.txt", O_RDONLY);
    clock_gettime(CLOCK_MONOTONIC, &end);

    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;

    if (fd == -1) {
        perror("open");
        return 1; // Error opening file
    }
    close(fd);

    printf("open_glibc耗时: %.9f 秒\n", elapsed);

    return 0;
}