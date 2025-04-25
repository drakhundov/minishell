#include <stdlib.h>
#include <string.h>

#include "utils.h"

void parse_input(char *input, char **args, int bgps[]) {
    int i = 0, bgi = 0;
    bgps[0] = -1;
    args[i] = strtok(input, " \n");
    while (args[i] != NULL) {
        args[++i] = strtok(NULL, " \n");

        if (args[i - 1] == '&') {
            bgps[bgi++] = i - 1;
        }
    }
    bgps[bgi] == -1;
}