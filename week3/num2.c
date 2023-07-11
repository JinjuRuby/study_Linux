#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

char * get_next_command(void);
void panic(char *erorr);
char delim[] = "\t\n";
int main(int argc, char* argv[]) {
	int child_pid;
	char *cmd;
	int status;
	int bg;

	while(1) {
		cmd = get_next_command();
		if(strcmp(cmd,"exit") == 0)
			exit(1);
		child_pid = fork();
		bg = (cmd[strlen(cmd) -1] == '&');
		if(bg)
			cmd[strlen(cmd) - 1] = '\0';
		if(child_pid == 0) {
			if(execlp(cmd, cmd, NULL) == -1);
			panic("exec failed!");
		} else {
			if(bg != 1)
				wait(&child_pid);
			else {
				printf("PID : %d\n", getpid());
				waitpid(child_pid, &status, WNOHANG);
			}
		}
		free(cmd);
	}
	return 0;
}

char * get_next_command() {
	printf("-->> ");
	char input[100];
	scanf("%s", input);
	int len = strlen(input);
	char * commend = (char *)malloc(sizeof(char) * len);
	strcpy(commend, input);
	return commend;
}

void panic(char *error) {
	printf("%s\n",error);
	exit(1);
}
