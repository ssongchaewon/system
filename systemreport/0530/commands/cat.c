/*
 * cat.c
 *
 * 설명:
 *  - 이 프로그램은 표준 입력(stdin)으로부터 텍스트를 한 줄씩 읽어서,
 *    그대로 표준 출력(stdout)으로 출력합니다.
 *  - UNIX의 기본 명령어인 `cat`과 유사한 동작을 하며,
 *    파일이 아닌 키보드 입력을 대상으로 동작합니다.
 *  - fgets() 함수를 이용해 한 줄씩 입력을 받고,
 *    fputs() 함수를 통해 해당 줄을 출력합니다.
 * 
 * 사용법:
 *  ./cat
 * 
 * 사용 예시:
 *  ./cat
 *  → 사용자가 입력한 내용을 출력함 (Ctrl+D로 입력 종료)
 * 
 *  echo "hello" | ./cat
 *  → 출력: hello
 */

#include <stdio.h>  // 표준 입출력 함수 사용을 위한 헤더 파일

int main(int argc, char *argv[]) {
    char buffer[1024];  // 입력된 한 줄을 저장할 버퍼 (최대 1023자 + 널 문자)

    // 표준 입력에서 한 줄씩 읽어서 표준 출력에 그대로 출력
    while (fgets(buffer, sizeof(buffer), stdin)) {
        // fgets:
        //  - 최대 sizeof(buffer) - 1 만큼 입력을 읽고,
        //  - 문자열 끝에 '\0'을 자동으로 붙여줌
        //  - 줄바꿈 문자('\n')도 포함하여 저장됨
        //  - 입력이 종료되면(NULL 반환) while문을 빠져나감

        fputs(buffer, stdout);
        // fputs:
        //  - 문자열을 출력 스트림(stdout)에 출력
        //  - 줄바꿈 문자가 포함된 문자열은 자동으로 줄바꿈됨
    }

    return 0;  // 프로그램 정상 종료
}
