# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 17:50:54 by itahri            #+#    #+#              #
#    Updated: 2024/05/10 14:13:03 by itahri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = default_utils.c ft_printf.c mandatory_func2.c minus_utils.c utils.c utils3.c \
      default_utils2.c len_functions.c mandatory_funcs.c minus_utils2.c utils2.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -I ./includes $< -o $@

bonus : all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus