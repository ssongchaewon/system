#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid, child, status;

    printf("[%d] 부모 프로세스 시작\n", getpid());

    pid = fork();
    if (pid == 0) {
        printf("[%d] 자식 프로세스 시작\n", getpid());
        exit(1);
    }

    child = wait(&status);
    printf("[%d] 자식 프로세스 %d 종료\n", getpid(), child);
    printf("\t종료 코드 %d\n", status >> 8);

    return 0;
}