# Этот проект представляет собой консольную утилиту, разработанную на языке C.

## Программа обрабатывает аргументы командной строки и выполняет следующие действия:
- Выводит список пользователей и их домашних директорий.
- Перенаправляет вывод и ошибки в указанные файлы.

## Требования:
Для сборки и запуска программы понадобятся:
- Компилятор C (например, gcc).
- CMake (версия 3.10 или выше).
- Операционная система *Astra Linux* или другая *Unix-подобная система*.

## Сборка проекта
### Клонируйте репозиторий:
**git clone git@github.com:pVaprog/pr2.git**
**cd pr2**

### Создайте папку для сборки:
**mkdir .build**
**cd .build**

### Запустите CMake для настройки проекта:
**cmake ..**

### Соберите проект:
**make**

После успешной сборки в папке *.build* появится исполняемый файл *MyProject*.

## Использование программы
Программа поддерживает следующие аргументы командной строки:

Аргумент Описание
-u Выводит список пользователей и их домашних директорий.
-p Выводит список запущенных процессов, отсортированных по PID.
-h Выводит справку с описанием всех доступных аргументов.
-l PATH Перенаправляет вывод в файл по указанному пути PATH.
-e PATH Перенаправляет ошибки в файл по указанному пути PATH.
