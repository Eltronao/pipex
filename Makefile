# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 21:09:14 by lagonzal          #+#    #+#              #
#    Updated: 2023/02/06 21:09:14 by lagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	00_main.c\
		01_arg_check.c \
		02_error_managment.c\
		03_access_check.c\
		04_child_process.c\
		05_parent_process.c\
		u_print_args.c

OBJS =	00_main.o\
		01_arg_check.o \
		02_error_managment.o \
		03_access_check.o\
		04_child_process.o\
		05_parent_process.o\
		u_print_args.o

LIB_DIR = libft

LIB = libft.a

INCLUDE = -I $(LIB_DIR)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -f

CC = gcc

all: $(NAME)

%o:%c
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIB_DIR)/$(LIB)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re