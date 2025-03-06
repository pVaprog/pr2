#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>
#include "users.h"

// Функция для сравнения имен пользователей (для qsort)
int compare_users(const void *a, const void *b) {
	return strcmp(((struct passwd *)a)->pw_name, ((struct passwd *)b)->pw_name);
}

void list_users() {
	struct passwd *pw;
	struct passwd *users[1024];
	int count = 0;

	// Собираем пользователей в массив
	while ((pw = getpwent()) != NULL) {
		users[count++] = pw;
	}
	endpwent();

	// Сортируем пользователей по алфавиту
	qsort(users, count, sizeof(struct passwd *), compare_users);

	// Выводим отсортированный список
	for (int i = 0; i < count; i++) {
		printf("%s: %s\n", users[i]->pw_name, users[i]->pw_dir);
	}
}
