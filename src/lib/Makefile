# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 14:50:24 by akalmyko          #+#    #+#              #
#    Updated: 2017/02/20 17:06:06 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re compile

NAME = libft.a
CCFLAGS = -Wall -Wextra -Werror -c
CC = gcc $(CCFLAGS)
RM = /bin/rm -rf
L = libft
E = ft_extra
P = ft_printf
GRN = \033[1;32m
RED = \033[1;31m
WHT = \033[1;37m
CLN = \033[m

LC = $(shell find $(L) -type f -follow -print | grep "\.c")
PC = $(shell find $(P) -type f -follow -print | grep "\.c")
EC = $(shell find $(E) -type f -follow -print | grep "\.c")

all: $(NAME)

$(NAME): compile
	@ar rc $(NAME) $(shell find . | grep "\.o" | sed 's/\.\///')
	@if [ -e $(NAME) ]; then \
		echo "$(GRN)created$(CLN)";\
	else \
		echo "$(RED)ERROR$(CLN)";\
	fi
	@ranlib $(NAME)

compile:
	@echo "$(NAME) compiling... \c"
	@$(CC) $(LC) $(EC) $(PC)

clean: 
	@echo "$(NAME) cleaning... \c"
	@$(RM) $(shell find . | grep "\.o" | sed 's/\.\///')
	@echo "$(WHT)cleaned$(CLN)"

fclean:
	@echo "$(NAME) fcleaning... \c"
	@$(RM) $(shell find . | grep "\.o" | sed 's/\.\///')
	@$(RM) $(NAME)
	@echo "$(WHT)fcleaned$(CLN)"

re: fclean all
