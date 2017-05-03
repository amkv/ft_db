# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 18:45:12 by akalmyko          #+#    #+#              #
#    Updated: 2017/05/03 15:38:02 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re o c v f

NAME = ft_db
SRCF = src/
PRJ = $(SRCF)project
LIBFT = $(SRCF)lib/
LIB = $(LIBFT)libft.a
CC = /usr/bin/gcc
# FLAGS = -Wall -Wextra -Werror -fsanitize=address
FLAGS = -Wall -Wextra -Werror
RMF = /bin/rm -rf
CFILES = $(shell find $(PRJ) -name "*.c")
OFILES = $(CFILES:$(PRJ)/%.c=%.o)
GRN = \033[1;32m
RED = \033[1;31m
WHT = \033[1;37m
CLN = \033[m

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@echo "$(NAME) compiling... \c"
	@$(CC) $(FLAGS) $(CFILES) -c
	@$(CC) $(FLAGS) $(OFILES) $(LIB) -o $(NAME)
	@echo "$(GRN)created$(CLN)"

clean:
	@make -C $(LIBFT) clean
	@echo "$(NAME) cleaning... \c"
	@$(RMF) $(OFILES)
	@echo "$(WHT)cleaned$(CLN)"

fclean:
	@make -C $(LIBFT) fclean
	@echo "$(NAME) fcleaning... \c"
	@$(RMF) $(OFILES)
	@$(RMF) $(NAME)
	@echo "$(WHT)fcleaned$(CLN)"

o:
	clear
	@$(RMF) $(NAME)
	@$(CC) $(FLAGS) $(CFILES) -c
	@$(CC) $(FLAGS) $(OFILES) $(LIB) -o $(NAME)
	make clean
	clear
	@echo "$(GRN)created$(CLN)"

c: o
	./$(NAME)

v: o
	~/goinfre/brew/bin/valgrind --suppressions=sup.txt ./$(NAME)

f: o
	~/goinfre/brew/bin/valgrind --leak-check=full --suppressions=sup.txt ./$(NAME)


re: fclean all

