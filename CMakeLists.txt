cmake_minimum_required(VERSION 3.6)
project(ft_db)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")


set(SOURCE_FILES
		src/project/main.c
		src/project/ft_01_init_db.c
		src/project/ft_02_table.c
		src/project/ft_03_column.c
		)
add_executable(ft_db ${SOURCE_FILES})
target_link_libraries(
		ft_db
		${CMAKE_CURRENT_SOURCE_DIR}/src/lib/libft.a
)
