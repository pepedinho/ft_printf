# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 17:50:54 by itahri            #+#    #+#              #
#    Updated: 2024/05/12 11:45:42 by itahri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = default_utils.c ft_printf.c mandatory_func2.c minus_utils.c utils.c utils3.c \
      default_utils2.c len_functions.c mandatory_funcs.c minus_utils2.c utils2.c \
						car_functions.c car_functions2.c return_functions.c strict_functions.c strict_utils.c\
						default_utils3.c \
						includes/ft_atoi.c \
	   		includes/ft_bzero.c \
						includes/ft_calloc.c \
						includes/ft_isalnum.c \
						includes/ft_isalpha.c \
						includes/ft_isascii.c \
						includes/ft_isdigit.c \
						includes/ft_isprint.c \
						includes/ft_memchr.c \
						includes/ft_memcmp.c \
						includes/ft_memcpy.c \
						includes/ft_memmove.c \
						includes/ft_memset.c \
						includes/ft_strchr.c \
						includes/ft_strdup.c \
						includes/ft_strlcat.c \
						includes/ft_strlcpy.c \
						includes/ft_strlen.c \
						includes/ft_strncmp.c \
						includes/ft_strrchr.c \
						includes/ft_strstr.c \
						includes/ft_substr.c \
						includes/ft_tolower.c \
						includes/ft_toupper.c \
						includes/ft_strjoin.c \
						includes/ft_strtrim.c \
						includes/ft_split.c \
						includes/ft_itoa.c \
						includes/ft_strmapi.c \
						includes/ft_striteri.c \
						includes/ft_putchar_fd.c \
						includes/ft_putstr_fd.c \
						includes/ft_putendl_fd.c \
						includes/ft_putnbr_fd.c

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