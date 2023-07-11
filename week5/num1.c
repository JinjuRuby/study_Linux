#include <stdio.h>
#include <pthread.h>

int hello(void);
int func1(void);

int main(void) {
	pthread_t id; // 스레드 타입

	pthread_create(&id, NULL, func1, NULL); // main 스레드가 자식 스레드를 생성, &id는 id의 주소값을 넙겨주는 것을 의미한다. func1의 기능을 수행하도록 한다.(main 프로세스 안에는 스레드 2개 존재- main스레드, 자식 스레드)
	printf("I'm main thread\n");
	hello();
	sleep(3); // main스레드 수행하다가 자식 스레드 수행 <- sleep을 하는 이유
	return 0;
}

int hello(void) {
	pid_t pid; // 프로세스 id
	pthread_t tid; // 스레드 id

	pid = getpid(); // 자기 자신의 프로세스 id를 리턴
	tid = pthread_self(); // 자기 자신의 스레드 id를 리턴
	printf("pid %u tid %u\n", (unsigned int)pid, (unsigned int)tid);

	return 0;
}

int func1(void) { // 자식 스레드
	printf("I'm child thread\n");
	hello();
	return 0;
}
// main 스레드와 자식 스레드가 찍어주는 스레드 id는 다르고 포르세스 id는 같다.
// 스레드는 부모건 자식이건 왔다갔다하기 때문에 출력 순서와 결과가 매번 다를 수 있다.
