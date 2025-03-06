#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"

void redirect_output(const char *path) {
	FILE *file = fopen(path, "w");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	if (dup2(fileno(file), STDOUT_FILENO) == -1) {
		perror("dup2");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	fclose(file); // Закрываем файл, так как dup2 создал копию дескриптора
}
