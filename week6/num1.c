#include <stdio.h>
#include <pthread.h>

int data=0;

int func1(void);
int func2(void);

int main(int argc, char* argv[])
{
	pthread_t id1;
	pthread_t id2;
	int i;
	void *tret;

	pthread_create(&id1, NULL, func1, NULL);
	pthread_create(&id2, NULL, func2, NULL);

	printf("I'm main thread\n");

	pthread_join(id1, &tret);
	pthread_join(id2, &tret);

	printf("data: %d\n", data); // 스레드는 전역변수를 공유한다. 결과: 2000이 출력될 듯,  0이 나오면 공유가 안된다라는 것을 알 수 있다. (딱 2000은 안나온다)

	return 0;	
}

int func1(void)
{
	int i;

	for(i=0; i<1000; i++){
		data++;
		printf("t1:data=%d ", data);
	}
	return 0;
}

int func2(void)
{
	int i; 

	for(i=0; i<1000; i++){
		data++;
		printf("t2:data=%d ", data);
	}
	return 0;
}
