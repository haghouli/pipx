# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 05:44:24 by haghouli          #+#    #+#              #
#    Updated: 2023/01/21 18:07:08 by haghouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SANI = -fsanitize=address
NAME	= pipex
CC		= gcc
#CFLAGS	= -Wall -Wextra -Werror

FILES  = ./utiles/ft_split.c \
		./utiles/ft_strnstr.c \
		./utiles/get_path.c \
		./utiles/pipex.c \
		./utiles/put_error.c \
		./bonus/gnl/get_next_line.c \
		./bonus/gnl/get_next_line_utils.c \

B_FILES = ./bonus/ft_lstnew_bonus.c \
		./bonus/ft_lstadd_front_bonus.c\
		./bonus/ft_lstdelone_bonus.c \
		./bonus/ft_lstclear_bonus.c \
 		./bonus/ft_lstlast_bonus.c \
		./bonus/ft_lstadd_back_bonus.c \
		./bonus/ft_lstsize_bonus.c \
		./bonus/fill_lst.c \
		./bonus/ft_strcmp.c \


OBJS = $(FILES:.c=.o)
B_OBJS = $(B_FILES:.c=.o)

all : $(NAME)

bonus : $(OBJS) $(B_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(B_OBJS) ./ft_printf/libftprintf.a main_bonus.c -o $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a main.c -o $(NAME)

clean :
	rm -f $(OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

reclean :
	make fclean && make && make clean

recleanb :
	make fclean && make bonus && make clean
