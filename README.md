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

- ';'로 명령어 분리
- **'**와 **"** 구현(멀티라인 X)
- 리다이렉션, 파이프, 환경변수($), 최근 실행함수 결과값($?)
- Ctrl-C, Ctrl-D, Ctrl-\

- 보너스:
	+ &&, ||
	+ 와일드카드 *


> ##### 허용 함수
>
> ```c
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
>

