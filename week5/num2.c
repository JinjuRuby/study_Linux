#include <stdio.h>
#include <pthread.h>

int func1(void);
int func2(void);

int main(void) {
	pthread_t id;
	int i = 0;

	pthread_create(&id, NULL, func1, NULL);
	pthread_create(&id, NULL, func2, NULL);

	while(i < 10000) {
		printf("M ");
		i++;
	}

	sleep(5);
	return 0;
}

int func1(void) {
	int i = 0;
	while(i < 10000) {
		printf("A ");
		i++;
	}

	return 0;
}

int func2(void) {
	int i = 0;
	while(i < 10000) {
		printf("B ");
		i++;
	}

	return 0;
}
