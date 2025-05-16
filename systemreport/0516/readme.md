  getopt()와 getopt_long()

  ✅ 요약
사용 방식	함수	특징
짧은 옵션 (-a)	getopt	POSIX 표준, 간단한 옵션만 가능
긴 옵션 (--alpha)	getopt_long	GNU 확장, 롱 옵션 지원

프로세스 ID
 각 프로세스는 프로세스를 구별하는 번호인 프로세스 ID를 갖는다.
 각 프로세스는 자신을 생성해준 부모 프로세스가 있다.
30
#include <unistd.h>
int getpid( ); 프로세스의 ID를 리턴한다.
int getppid( ); 부모 프로세스의 ID를 리턴한다.
