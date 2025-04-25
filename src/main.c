#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "constants.h"

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
	int bgps[MAX_BG_PS];  // Background processes.
	int rc;
    while (1) {
        printf("mini-shell> ");
		fflush(stdout);  // Ensure the prompt is displayed immediately.
		if (fgets(input, MAX_INPUT, stdin) == NULL) {
			// Exit on EOF.
            break;
        }
        parse_input(input, args, bgps);
        if((rc = execute_cmd(args, bgps)) != 0) {
			break;
		}
    }
    printf("Exiting mini-shell.\n");
    return 0;
}
