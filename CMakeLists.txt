set(TARGET MyProject)

project(${TARGET} C)

set(CMAKE_C_STANDARD 99)

# Добавление исполняемого файла
add_executable(${TARGET})

# Добавление исходных файлов для компиляции проекта
target_sources(${TARGET} PRIVATE
	src/main.c
	src/users.c
	src/processes.c
	src/help.c
	src/log.c
	src/errors.c
)
