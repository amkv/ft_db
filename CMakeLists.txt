cmake_minimum_required(VERSION 3.6)
project(ft_db)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")


set(SOURCE_FILES
		src/project/main.c
		src/project/ft_01_ft_db.c
		src/project/ft_02_parser.c
		src/project/ft_03_query.c
		src/project/ft_04_action.c
		src/project/ft_05_init_db.c
		src/project/ft_06_table.c
		src/project/ft_07_column.c
		src/project/ft_09_record.c
		src/project/ft_08_row.c
		src/project/ft_10_print_db.c
		)
add_executable(ft_db ${SOURCE_FILES})
target_link_libraries(
		ft_db
		${CMAKE_CURRENT_SOURCE_DIR}/src/lib/libft.a
)
