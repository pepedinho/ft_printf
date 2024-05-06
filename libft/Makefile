NAME = libft.a

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew_bonus.c \
			 ft_lstadd_front_bonus.c \
			 ft_lstnew_bonus.c \
			 ft_lstlast_bonus.c \
			 ft_lstadd_back_bonus.c \
			 ft_lstdelone_bonus.c \
			 ft_lstclear_bonus.c \
			 ft_lstiter_bonus.c \
			 ft_lstmap_bonus.c \

# Concaténation des fichiers source de base et supplémentaires
ALL_SRCS = $(SRCS) $(BONUS_SRCS)

OBJS = $(SRCS:.c=.o)

ALL_OBJS = $(ALL_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus_1: $(BONUS_SRCS:.c=.o) $(OBJS)
	ar rcs $(NAME) $(ALL_OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

bonus : bonus_1 clean

clean:
	rm -f $(OBJS) $(ALL_OBJS)

clean_bonus:
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re re_bonus
