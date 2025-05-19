물론입니다! 아래는 요청하신 내용을 **Markdown (`.md`) 형식**으로 정리한 것입니다:

---

````markdown
# 파일 시스템 관련 시스템 호출 및 개념 정리

## 📦 데이터 블록 포인터 (i-node 구조)

- **직접 블록 포인터**: 12개  
- **간접 블록 포인터**: 1개  
- **이중 간접 블록 포인터**: 1개  
- **삼중 간접 블록 포인터**: 1개  

📌 최대 가리킬 수 있는 데이터 블록 수는 파일 시스템의 블록 크기에 따라 달라짐

---

## 🧾 파일 상태 정보: `stat()`

파일에 대한 메타데이터(i-node 정보 포함)를 가져오는 함수들

```c
#include <sys/types.h>
#include <sys/stat.h>

int stat(const char *filename, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *filename, struct stat *buf);
````

* 성공: 0 리턴
* 실패: -1 리턴

---

## 🔐 접근 권한 변경: `chmod()`, `fchmod()`

```c
#include <sys/stat.h>

int chmod(const char *path, mode_t mode);
int fchmod(int fd, mode_t mode);
```

* 권한은 **8진수**로 지정 (예: `0644`)
* 성공: 0, 실패: -1

---

## ⏱ 접근 및 수정 시간 변경: `utime()`

```c
#include <utime.h>

int utime(const char *filename, const struct utimbuf *times);
```

* `times == NULL`일 경우 현재 시간으로 설정
* 성공: 0, 실패: -1

---

## 👤 소유자 변경: `chown()`, `fchown()`, `lchown()`

```c
#include <unistd.h>

int chown(const char *path, uid_t owner, gid_t group);
int fchown(int fd, uid_t owner, gid_t group);
int lchown(const char *path, uid_t owner, gid_t group);
```

* **Super-user만 변경 가능**
* 성공: 0, 실패: -1

---

## 🔒 파일 잠금 (Locking)

### `flock()` — 전체 파일에 잠금 설정

```c
#include <sys/file.h>

int flock(int fd, int operation);
```

| 명령어       | 설명                                 |
| --------- | ---------------------------------- |
| `LOCK_SH` | 공유 잠금 (다수 프로세스 접근 허용)              |
| `LOCK_EX` | 배타 잠금 (단일 프로세스 접근만 허용)             |
| `LOCK_UN` | 잠금 해제                              |
| `LOCK_NB` | 논블로킹 (잠금 중이면 즉시 실패, `EWOULDBLOCK`) |

### `fcntl()` — 레코드 잠금 (부분 잠금 가능)

```c
int fcntl(int fd, int cmd, struct flock *lock);
```

| cmd        | 설명                  |
| ---------- | ------------------- |
| `F_GETLK`  | 잠금 여부 검사            |
| `F_SETLK`  | 잠금 설정 또는 해제         |
| `F_SETLKW` | 잠금 설정 (blocking 버전) |

* 공유 잠금은 다수 프로세스가 공유 가능
* 배타 잠금은 하나의 프로세스만 가능

---

## 📌 핵심 개념 요약

* **stat()**: 파일 상태 정보 확인
* **chmod() / chown()**: 권한 및 소유자 변경
* **utime()**: 최종 접근/수정 시간 변경
* **flock() / fcntl()**: 파일/레코드 단위 잠금
* **공유 잠금**: 다수 프로세스 접근 가능
* **배타 잠금**: 단일 프로세스만 접근 가능
* **강제 잠금**: 잠금 무시 불가
* **권고 잠금**: 잠금 무시 가능

```

---

이 내용을 복사해 `.md` 파일로 저장하면 깔끔하게 마크다운 문서로 활용하실 수 있습니다. 더 정리하거나 이어서 내용 추가할 게 있다면 언제든지 말씀해 주세요!
```

