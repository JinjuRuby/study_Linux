#include <stdio.h>
#include <pthread.h>

void func1(void);
void func2(void);
int withdraw(int amount);
int deposit(int amount);
int get_balance(void);
void put_balance(int balance);

int money=1000;


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
		deposit(10); // 돈을 저축
		withdraw(10); // 돈을 인출
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

	balance = get_balance();
	balance = balance - amount;
	put_balance(balance);

	return balance;
}

int deposit(int amount){
	int balance;

	balance = get_balance();
	balance = balance + amount;
	put_balance(balance);

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
