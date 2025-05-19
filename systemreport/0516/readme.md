🧠 프로세스 개념 및 사용자/그룹 ID 관리
📌 프로세스란?
실행 중인 프로그램

프로그램 실행 시 메모리에 적재되어 프로세스 이미지를 구성

쉘(shell)은 명령어를 입력받아 이를 처리하는 명령어 인터프리터

🔍 프로세스 식별
구분	설명
getpid()	현재 프로세스의 ID를 반환
getppid()	부모 프로세스의 ID를 반환

📄 예제 코드: pid.c
c
복사
편집
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("나의 프로세스 번호 : [%d] \n", getpid());
    printf("내 부모 프로세스 번호 : [%d] \n", getppid());
}
👤 사용자 및 그룹 ID
항목	설명
실제 사용자 ID	프로그램을 실행한 사용자의 ID
유효 사용자 ID	파일 접근 권한 등에서 사용되는 ID
실제 그룹 ID	사용자가 속한 그룹의 ID
유효 그룹 ID	유효 사용자 ID와 유사한 개념으로 접근 권한 결정에 사용됨

🔧 사용자 및 그룹 ID 변경 함수
c
복사
편집
#include <sys/types.h>
#include <unistd.h>

int setuid(uid_t uid);    // 실제 사용자 ID 설정
int seteuid(uid_t uid);   // 유효 사용자 ID 설정
int setgid(gid_t gid);    // 실제 그룹 ID 설정
int setegid(gid_t gid);   // 유효 그룹 ID 설정
🔐 Set-user-ID (SUID)
실행 파일에 특별 권한 비트(SUID)가 설정된 경우, 실행 시 유효 사용자 ID가 파일 소유자로 변경됨

보안상 중요한 작업에 사용됨

예: /bin/passwd
bash
복사
편집
$ ls -l /bin/passwd
-rwsr-xr-x 1 root root ...
일반 사용자가 실행해도, 유효 사용자 ID가 root로 설정되어 /etc/shadow 등 시스템 파일 수정 가능

🧱 프로세스 이미지 구성
영역	설명
텍스트	실행 코드 (명령어)
데이터	전역 변수, 정적 변수
힙	동적 메모리 할당 공간 (malloc)
스택	함수 호출 시 사용하는 공간
U-영역	파일 디스크립터, 현재 디렉토리 등 프로세스 관련 정보

🛑 프로세스 종료
함수	설명
exit()	후처리 후 정상 종료 (exit handler 호출)
_exit()	후처리 없이 즉시 종료

✅ 핵심 요약
프로세스는 실행 중인 프로그램

각각 고유의 PID, PPID, UID, GID를 가짐

사용자/그룹 ID는 접근 제어 및 권한 관리에 필수

setuid, seteuid 등으로 ID 변경 가능

SUID는 보안상 중요한 명령어 실행 시 사용됨 (passwd, sudo 등)

🧩 getopt()와 getopt_long() / 프로세스 ID
✅ 요약: 옵션 처리 함수 비교
구분	함수	특징
짧은 옵션	getopt()	POSIX 표준, -a, -b 형식의 단순 옵션 처리
긴 옵션	getopt_long()	GNU 확장, --alpha, --beta 등 롱 옵션 지원

📌 헤더 파일
c
복사
편집
#include <unistd.h>       // getopt
#include <getopt.h>       // getopt_long
🧠 프로세스 ID 관련 함수
모든 프로세스는 **고유한 프로세스 ID(PID)**를 갖는다.

각 프로세스는 자신을 생성한 부모 프로세스가 존재한다.

📄 관련 함수
c
복사
편집
#include <unistd.h>

int getpid(void);   // 현재 프로세스의 PID 반환
int getppid(void);  // 부모 프로세스의 PID 반환
🖥️ 예제 코드
c
복사
편집
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("나의 프로세스 번호 : [%d]\n", getpid());
    printf("내 부모 프로세스 번호 : [%d]\n", getppid());
    return 0;
}
