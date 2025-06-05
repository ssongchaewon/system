/* 
 * touch.c: 파일이 존재하지 않으면 생성하고, 존재하면 수정 시간을 현재 시각으로 갱신
 *   - open으로 O_CREAT | O_WRONLY 플래그 사용
 *   - utime으로 시간 갱신
 */

#include <stdio.h>
#include <utime.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    // 파일을 없으면 생성, 있으면 쓰기 모드로 열기
    int fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
    if (fd >= 0) close(fd);
    utime(argv[1], NULL);  // 수정 시간 현재 시각으로 갱신
    return 0;
}
