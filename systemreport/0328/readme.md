📁 파일 복사 명령어: cp (copy)
리눅스에서 cp 명령어는 파일이나 디렉터리를 복사할 때 사용됩니다.

📌 기본 사용법
bash
복사
편집
cp [옵션] <원본파일> <대상파일>
파일1을 파일2로 복사

덮어쓰기 방지 옵션 -i (interactive)

📂 파일 이동 및 이름 변경 명령어: mv (move)
리눅스에서 mv 명령어는 파일이나 디렉터리를 이동하거나 이름을 변경할 때 사용됩니다.

📌 기본 사용법
bash
복사
편집
mv [옵션] <원본> <대상>
파일1을 파일2로 이름 변경

또는 파일이나 디렉터리를 다른 위치로 이동

-i 옵션은 덮어쓰기 전 사용자 확인을 위한 대화형 옵션

🗑️ 파일 및 디렉터리 삭제 명령어: rm (remove)
리눅스에서 rm 명령어는 파일이나 디렉터리를 삭제할 때 사용됩니다.

📌 기본 사용법
bash
복사
편집
rm [옵션] <파일1> <파일2> ...
지정한 파일들을 삭제합니다.

-i: 삭제 전 확인하는 대화형 옵션(interactive)

📋 예제 1: 파일 삭제
bash
복사
편집
$ rm cs1.txt
$ rm cs1.txt cs3.txt
여러 개의 파일도 한 번에 삭제 가능

🔐 대화형 삭제: -i 옵션
bash
복사
편집
$ rm -i cs1.txt
rm: remove 'cs1.txt'? n
실수 방지를 위해 삭제 전 확인 요청

🧹 디렉터리 전체 삭제: -r 옵션
디렉터리와 그 내용 전체를 재귀적으로 삭제

❌ 단순 삭제 시 오류
bash
복사
편집
$ rm test
rm: cannot remove 'test': 디렉터리입니다
디렉터리는 rm으로 직접 삭제할 수 없음

❌ 빈 디렉터리만 삭제 가능 (rmdir)
bash
복사
편집
$ rmdir test
rmdir: failed to remove 'test': 디렉터리가 비어있지 않음
rmdir은 빈 디렉터리에만 사용 가능

🔗 리눅스 링크 (Link)
리눅스에서 링크는 기존 파일에 대한 또 하나의 이름을 생성하는 방식입니다. 대표적으로 두 가지 종류가 있습니다:

하드 링크 (Hard Link)

심볼릭 링크 (Symbolic Link, soft link)

📌 기본 사용법
bash
복사
편집
ln [옵션] <원본파일> <링크이름>
-s 옵션 없이 생성 → 하드 링크

-s 옵션 사용 시 → 심볼릭 링크

🪵 하드 링크 (Hard Link)
✅ 특징
기존 파일에 대한 새로운 이름

파일의 i-node를 공유 (데이터 영역을 함께 사용)

한 파일을 수정하면 다른 링크에도 반영됨

원본 파일이 삭제돼도 다른 링크가 존재하면 데이터는 유지됨

🧪 예시
bash
복사
편집
$ ln hello.txt hi.txt
$ ls -l
-rw------- 2 chang chang 15 11월 7 15:31 hello.txt
-rw------- 2 chang chang 15 11월 7 15:31 hi.txt
링크 수(2)가 증가

파일 내용 수정 시 서로 영향을 줌

하나를 삭제해도 다른 링크로 접근 가능

🧭 심볼릭 링크 (Symbolic Link)
✅ 특징
파일 경로명을 저장하는 특수한 파일

실제 파일을 가리키는 간접적인 포인터

원본 파일이 삭제되면 **링크는 끊어진 상태(broken link)**가 됨

디렉터리에도 링크 생성 가능

🧪 예시
bash
복사
편집
$ ln -s hello.txt hi.txt
$ ls -l
-rw------- 1 chang chang 15 11월 7 15:31 hello.txt
lrwxrwxrwx 1 chang chang 9 1월 24 12:56 hi.txt -> hello.txt
bash
복사
편집
$ ln -s /usr/bin/gcc cc
$ ls -l cc
lrwxrwxrwx. 1 chang chang 12 7월 21 20:09 cc -> /usr/bin/gcc
