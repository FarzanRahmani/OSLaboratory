#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"

void main(int argc, int *argv[]) {
    fork();
    fork();
    fork();
    printf("My ID is %d \t and my Parent Id is %d \n", getpid(), getppid());
}

