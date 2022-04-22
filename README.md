# MINISHELL

### MANDATORY

#### 요구 사항

- 유닉스 인터프리터 구현
- 명령 프롬프트를 띄우고, 엔터를 누를때까지 대기함
- 프롬프트는 명령이 완료된 후 다시 표시
- PATH 변수, 상대/절대 경로의 파일을 찾아 실행하고, 실행 파일을 찾을 수 없을 경우 오류메세지 표시 후 프롬프트 다시 표시

> ##### 구현 함수
>	- echo [-n]
>	- cd
>	- pwd
>	- export
>	- unset
>	- env
>	- exit
>

- ';'로 명령어 분리, 파이프와 리다이렉션으로 명령어를 구분
- **'**와 **"** 구현(멀티라인 X)
- 환경변수($), 최근 실행함수 결과값($?)
- Ctrl-C, Ctrl-D, Ctrl-\

- 보너스:
	+ &&, ||
	+ 와일드카드 *


##### 허용 함수

 ```c
readline
rl_on_new_line
rl_replace_line
rl_redisplay
add_history
printf
malloc
free
write
open
read
close
fork
wait
waitpid
wait3
wait4
signal
kill
exit
getcwd
chdir
stat
lstat
fstat
unlink
execve
dup
dup2
pipe
opendir
readdir
closedir
strerror
errno
isatty
ttyname
ttyslot
ioctl
getenv
tcsetattr
tcgetattr
tgetent
tgetflag
tgetnum
tgetstr
tgoto
tputs

+ Libft
```
</hr>

## C API

##### readline
> ```c
> char *readline(const char *prompt)
> ```
> 읽어온 텍스트에서 개행 제거 -> 힙에 저장 -> 문자열 시작 주소 반환
> EOF, 프롬프트가 NULL, 빈 문자열인 경
> malloc으로 문자열 할당해줘서 free 해줘야 함

##### add_history
	```c
	void add_history(char *line)
	```
	readline으로 읽어온 char *를 인자로 받아 "readline/history.h"의 history 구조체에 추가

	```c
	/*
	*		히스토리 헤더(나중에 정리함)
	*/
	
	/* list of readline stuff supported by editline library's readline wrapper */
	
	/* typedefs */
	typedef int	  Function(const char *, int);
	typedef void	  VFunction(void);
	typedef void	  VCPFunction(char *);
	typedef char	 *CPFunction(const char *, int);
	typedef char	**CPPFunction(const char *, int, int);
	typedef char     *rl_compentry_func_t(const char *, int);
	typedef int	  rl_command_func_t(int, int);
	
	/* only supports length */
	typedef struct {
		int length;
	} HISTORY_STATE;
	
	typedef void *histdata_t;
	
	typedef struct _hist_entry {
		const char	*line;
		histdata_t 	 data;
	} HIST_ENTRY;
	
	// 구조체 내부에 디파인은 머임?
	typedef struct _keymap_entry {
		char type;
	#define ISFUNC	0
	#define ISKMAP	1
	#define ISMACR	2
		Function *function;
	} KEYMAP_ENTRY;
	
	#define KEYMAP_SIZE	256
	
	typedef KEYMAP_ENTRY KEYMAP_ENTRY_ARRAY[KEYMAP_SIZE];
	typedef KEYMAP_ENTRY *Keymap;
	
	#define control_character_threshold	0x20
	#define control_character_bit		0x40
	
	#ifndef CTRL
	#include <sys/ioctl.h>
	#if !defined(__sun) && !defined(__hpux) && !defined(_AIX)
	#include <sys/ttydefaults.h>
	#endif
	#ifndef CTRL
	#define CTRL(c)		((c) & 037)
	#endif
	#endif
	#ifndef UNCTRL
	#define UNCTRL(c)	(((c) - 'a' + 'A')|control_character_bit)
	#endif
	
	#define RUBOUT		0x7f
	#define ABORT_CHAR	CTRL('G')
	#define RL_READLINE_VERSION 	0x0402
	#define RL_PROMPT_START_IGNORE	'\1'
	#define RL_PROMPT_END_IGNORE	'\2'
	```

### rl_on_new_line
	```c
	int rl_on_new_line(void)
	```
	
