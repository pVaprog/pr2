#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "processes.h"

// Функция для сравнения PID (для qsort)
int compare_pids(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

void list_processes()
{
	DIR *dir;
	struct dirent *entry;
	int pids[1024];
	int count = 0;

	dir = opendir("/proc");
	if (dir == NULL) {
		perror("opendir");
		return;
	}

	// Собираем PID процессов
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR)
		{
		    int pid = atoi(entry->d_name);
		    if (pid > 0)
			{
		        pids[count++] = pid;
		    }
		}
	}
	closedir(dir);

	// Сортируем PID
	qsort(pids, count, sizeof(int), compare_pids);

	// Выводим отсортированный список
	for (int i = 0; i < count; i++) {
		printf("PID: %d\n", pids[i]);
		fflush(stdout);  // Сброс буфера stdout
	}
}
