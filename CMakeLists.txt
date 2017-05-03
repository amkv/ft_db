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
		src/project/ft_05_action_create.c
		src/project/ft_06_action_add.c
		src/project/ft_07_action_set.c
		src/project/ft_08_action_in.c
		src/project/ft_09_action_change.c
		src/project/ft_10_action_select.c
		src/project/ft_11_action_delete.c
		src/project/ft_12_action_print.c
		src/project/ft_13_actoin_print_db.c
		src/project/ft_14_action_dump.c
		src/project/ft_15_action_dump_db.c
		src/project/ft_16_action_flush.c
		src/project/ft_17_action_to.c
		src/project/ft_21_init_db.c
		src/project/ft_22_table.c
		src/project/ft_23_column.c
		src/project/ft_24_row.c
		src/project/ft_25_record.c
		)
add_executable(ft_db ${SOURCE_FILES})
target_link_libraries(
		ft_db
		${CMAKE_CURRENT_SOURCE_DIR}/src/lib/libft.a
)
