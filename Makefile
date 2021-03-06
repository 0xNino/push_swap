# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 16:51:38 by 0xNino            #+#    #+#              #
#    Updated: 2022/03/01 18:29:06 by 0xNino           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT	= libft

LIB_DIR	= ./libft
LIB		= ./libft/libft.a

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
RESET	= \033[0m

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

SRCS	=	src/check.c \
			src/operations.c \
			src/process_args.c \
			src/push_swap.c \
			src/solve.c \
			src/utils.c \

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -sC $(LIB_DIR)
			@echo "[$(GREEN)libft\t\tcompiled$(RESET)]"
			@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB)
			@echo "[$(GREEN)push_swap\tcompiled$(RESET)]"

clean:
		@$(MAKE) -sC $(LIB_DIR) clean
		@echo "[$(RED)libft\t\tdeleted$(RESET)]"
		@$(RM) $(OBJS)
		@echo "[$(RED)push_swap\tdeleted$(RESET)]"

fclean:	clean
		@$(RM) $(NAME)
		@$(MAKE) -sC $(LIB_DIR) fclean

re:		fclean all

.PHONY:	all clean fclean re