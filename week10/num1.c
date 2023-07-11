#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

void func1();
void func2();
int withdraw(int amount);
int deposit(int amount);
int get_balance();
void put_balance(int balance);

int money=1000;
sem_t mutex;

int main(void)
{	
	pthread_t id1;
	pthread_t id2;

	sem_init(&mutex, 0, 1);
	void *tret;

	printf("I'm main thread\n");
	pthread_create(&id1, NULL, func1, NULL);
	pthread_create(&id2, NULL, func2, NULL);

	pthread_join(id1, &tret);
	pthread_join(id2, &tret);

	printf("money: %d\n", money);
	sem_destroy(&mutex);
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
	sem_wait(&mutex);

	balance = get_balance();
	balance = balance - amount;
	put_balance(balance);

	sem_post(&mutex);
	return balance;
}

int deposit(int amount){
	int balance;
	sem_wait(&mutex);

	balance = get_balance();
	balance = balance + amount;
	put_balance(balance);

	sem_post(&mutex);
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
