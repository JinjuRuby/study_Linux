#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

	int child_pid1 = fork();
	if(child_pid1 == 0) {
		for(int i=1;i<=100000;i++) {
			printf("A ");
		}	
	return 0;
	}

	int child_pid2 = fork();
	if(child_pid2 == 0) {
		for(int i=1;i<=100000;i++) {
			printf("B ");
		}
		return 0;
	}
	if(child_pid1 != 0 && child_pid2 != 0) {
		for(int i=1;i<=100000;i++) {
			printf("P ");
		}
	}
	return 0;
}

