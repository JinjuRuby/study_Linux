#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid1, pid2;
	int status;

	pid1 = fork();

	if (pid1 == 0) {
		for(int i = 0; i <= 100000; i++) {
			printf("A ");
		}
		return 0;
	}

	pid2 = fork();

	if(pid2 == 0) {
		for(int i=1; i <= 100000; i++) {
			printf("B ");
		}
	return 0;
	}


// 여기서는 waitpid보다 wait를 사용하는 것이 낫다. 왜냐하면 특정 함수를 기다리다가 다른 함수가 먼저 실행되는 상황이 발생할 수 있기 때문이다.
	if(pid1 != 0 && pid2 != 0) {
		wait(&status);
	printf("My children have gone.");
	}
	return 0;
}
