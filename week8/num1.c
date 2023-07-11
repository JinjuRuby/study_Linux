#include <stdio.h>
#include <pthread.h>

#define FALSE 0
#define TRUE 1
#define N 2

void func1();
void func2();
int withdraw(int amount);
int deposit(int amount);
int get_balance();
void put_balance(int balance);

int money=1000;

int turn = FALSE;
int interested[N] = {FALSE, FALSE};
void enter_region(int process);
void leave_region(int process);

int main(void)
{
	pthread_t id1;
	pthread_t id2;
	void *tret;

	printf("I'm main thread\n");

	pthread_create(&id1, NULL, func1, NULL);
	pthread_create(&id2, NULL, func2, NULL);

	pthread_join(id1, &tret);
	pthread_join(id2, &tret);

	printf("money: %d\n", money);
}

void func1(void){
	for(int i=0; i<10000; i++){
		deposit(10);
		withdraw(10);
	}
}

void func2(void){
	for(int i=0; i<10000; i++){
		deposit(10);
		withdraw(10);
	}
}

int withdraw(int amount){
	int balance;
	enter_region(turn);

	balance = get_balance();
	balance = balance - amount;
	put_balance(balance);

	leave_region(turn);
	return balance;
}

int deposit(int amount){
	int balance;
	enter_region(turn);

	balance = get_balance();
	balance = balance + amount;
	put_balance(balance);

	leave_region(turn);
	return balance;
}

int get_balance(void)
{
	return money;
}

void put_balance(int balance)
{
	money = balance;
}

void enter_region(int process) {
	int other = 1 - process;

	interested[process] = TRUE;
	turn = process;
	while (turn == process && interested[other] == TRUE);
}

void leave_region(int process) {
	interested[process] = FALSE;
}
