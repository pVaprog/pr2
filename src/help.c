#include <stdio.h>
#include "help.h"

void print_help() {
	printf("Usage: my_program [options]\n");
	printf("Options:\n");
	printf("  -u, --users         List users and their home directories\n");
	printf("  -p, --processes     List running processes sorted by PID\n");
	printf("  -h, --help          Show this help message\n");
	printf("  -l PATH             Redirect output to the specified file\n");
	printf("  -e PATH             Redirect errors to the specified file\n");
}
