#include <stdio.h>
#include <pthread.h>

int func1(void);
int func2(void);

int main(void) {
	pthread_t id1, id2;
	void *tret;
	pthread_create(&id1, NULL, func1, NULL);
	pthread_create(&id2, NULL, func2, NULL);
	pthread_join(id1, &tret);
	pthread_join(id2, &tret);
	printf("\nMY children have gone.\n");
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
