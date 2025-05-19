📂 파일 입출력 시스템 호출 정리
📄 파일 열기: open()
c
복사
편집
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *path, int oflag, [mode_t mode]);
기능: 파일을 열고, 성공 시 파일 디스크립터(fd)를 반환

리턴값:

성공: 파일 디스크립터 (정수)

실패: -1

🔧 주요 플래그 (oflag)
플래그	설명
O_RDONLY	읽기 전용
O_WRONLY	쓰기 전용
O_RDWR	읽기/쓰기
O_CREAT	파일이 없으면 새로 생성
O_TRUNC	기존 파일 내용 삭제 후 열기

🆕 파일 생성: creat()
c
복사
편집
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int creat(const char *path, mode_t mode);
기능: 새 파일 생성 및 쓰기 전용 열기

리턴값:

성공: 파일 디스크립터

실패: -1

⚠️ 내부적으로 다음과 동일
c
복사
편집
open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
❌ 파일 닫기: close()
c
복사
편집
#include <unistd.h>

int close(int fd);
기능: 열린 파일 디스크립터 닫기

리턴값:

성공: 0

실패: -1

📥 데이터 읽기: read()
c
복사
편집
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t nbytes);
기능: 파일 디스크립터 fd에서 최대 nbytes 바이트 읽어 buf에 저장

리턴값:

성공: 읽은 바이트 수

파일 끝: 0

실패: -1

📤 데이터 쓰기: write()
c
복사
편집
#include <unistd.h>

ssize_t write(int fd, void *buf, size_t nbytes);
기능: buf에 있는 데이터를 fd가 나타내는 파일에 nbytes만큼 씀

리턴값:

성공: 실제로 쓰여진 바이트 수

실패: -1

📌 파일 위치 포인터 이동: lseek()
c
복사
편집
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);
기능: 파일의 읽기/쓰기 위치(offset)를 임의로 이동

리턴값:

성공: 이동 후 현재 위치

실패: -1

🔧 whence 옵션
옵션	설명
SEEK_SET	파일의 처음부터 offset 이동
SEEK_CUR	현재 위치에서 offset 이동
SEEK_END	파일 끝에서 offset 이동
