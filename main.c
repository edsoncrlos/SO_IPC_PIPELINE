#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define TRUE 1
#define BUFFER 20

void producer(int []);
void consumer(int []);

int main () {
	int fd[2];
	pid_t pid;

	if (pipe(fd) < 0) {
		perror("pipe error");
		exit(EXIT_FAILURE);
	}

	pid = fork();

	if (pid < 0) {
		perror("fork error");
		exit(EXIT_FAILURE);
	} else if (pid > 0) {	// Parent process
		producer(fd);
	} else {                      // Child process
		consumer(fd);
	}

	return 0;
}

void producer(int fd[]) {
	close(fd[0]); // close read pipe
	
	sleep(3); // show that the consumer waits for the producer

	for (int i = 0; i < 13; i++) {
		char msg[20];
		snprintf(msg, sizeof(msg), "Mensagem %d", i+1);

		if (write(fd[1],  msg, strlen(msg)) == -1) {
			perror("write error in pipe");
			exit(EXIT_FAILURE);
		}
		sleep(1);
    }

	close(fd[1]);
	exit(EXIT_SUCCESS);
}

void consumer(int fd[]) {
	close(fd[1]); // close write pipe
	char receive_str[BUFFER];
	int bytes_read;

	while (TRUE) {
		bytes_read = read(fd[0], receive_str, BUFFER);
		
		if (bytes_read == -1) {
			perror("error read");
		}

		if (bytes_read == 0) {
			break;
		}
		printf("%.*s\n",  bytes_read,  receive_str);
		
	}

	close(fd[0]);
	exit(EXIT_SUCCESS);
}
