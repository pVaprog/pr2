#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <fcntl.h>
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

    // Определение длинных арг-тов
    static struct option long_options[] = {
        {"users",    no_argument,       0, 'u'},  // --users эквивалентно -u
        {"processes", no_argument,      0, 'p'},  // --processes эквивалентно -p
        {"help",     no_argument,       0, 'h'},  // --help эквивалентно -h
        {"log",      required_argument, 0, 'l'},  // --log эквивалентно -l
        {"errors",   required_argument, 0, 'e'},  // --errors эквивалентно -e
        {0, 0, 0, 0}  // Завершающий элемент массива
    };

    if (argc < 2) {
        fprintf(stderr, "No arguments provided. Use -h or --help for help.\n");
        exit(EXIT_FAILURE);
    }

    int option_index = 0;  // Индекс текущего длинного аргумента
    while ((opt = getopt_long(argc, argv, "uphl:e:", long_options, &option_index)) != -1) {
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

                // Если stdout не перенаправлен, перенаправляем его в /dev/null
                if (log_path == NULL) {
                    int dev_null = open("/dev/null", O_WRONLY);
                    if (dev_null == -1) {
                        perror("open");
                        exit(EXIT_FAILURE);
                    }
                    if (dup2(dev_null, STDOUT_FILENO) == -1) {
                        perror("dup2");
                        close(dev_null);
                        exit(EXIT_FAILURE);
                    }
                    close(dev_null);
                }
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
