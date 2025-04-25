#ifndef PARSER_H
#define PARSER_H
void parse_input(char *input, char **args, int *bgps);
int execute_cmd(char **args, int *bgps);
#endif