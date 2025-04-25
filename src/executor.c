#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "utils.h"
#include "constants.h"

int execute_cmd(char **args, int *bgps) {
	int i = 0;
	
	do {
		if (bgps[i] == -1) {
			break;
		}
		if (args[0] == NULL) {
			return 0;
		}
		if (strcmp(args[0], "exit") == 0) {
			return 1;
		}
		pid_t pid = fork();
		if (pid < 0) {
			perror("fork failed");
			return 1;
		}
		if (pid == 0) {
			execvp(args[0], args);
			perror("exec failed");
			return 1;
		} else {
			wait(NULL);
		}	
	} while (bgps != NULL && bgps[0] != -1);
	return 0;
}