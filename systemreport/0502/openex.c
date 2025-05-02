#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
int fd1,fd2,fd3;
fd1 = open(argv[1], O_RDWR);
printf("파일 %s 열기 성공 : %d\n", argv[1], fd1);
fd2 = open(argv[2], O_RDWR);
printf("파일 %s 열기 성공 : %d\n", argv[2], fd2);
fd3 = open(argv[3], O_RDWR);
printf("파일 %s 열기 성공 : %d\n", argv[3], fd3);
close(fd1);
close(fd2);
close(fd3);
exit(0);
} 