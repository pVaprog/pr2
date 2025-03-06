#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log.h"
#include "errors.h"

int main(int argc, char *argv[]) {
	int opt;
	char *log_path = NULL;
	char *error_path = NULL;
	int users_flag = 0, processes_flag = 0;

	if (argc < 2) {
		fprintf(stderr, "No arguments provided. Use -h for help.\n");
		exit(EXIT_FAILURE);
	}

	while ((opt = getopt(argc, argv, "u:p:hl:e:")) != -1) {
		switch (opt) {
			case 'u':
				users_flag = 1;
				break;
			case 'p':
				processes_flag = 1;
				break;
			case 'h':
				print_help();
				exit(0);
			case 'l':
				log_path = optarg;
				redirect_output(log_path);
				break;
			case 'e':
				error_path = optarg;
				redirect_errors(error_path);
				break;
			default:
				fprintf(stderr, "Unknown option: %c\n", opt);
				exit(EXIT_FAILURE);
		}
	}

	// Выполняем действия после обработки всех опций
	if (users_flag) {
		list_users();
	}
	if (processes_flag) {
		list_processes();
	}

	return 0;
}
