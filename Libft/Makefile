# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
TARGET = main.exe

NAME = libft.a

INCLUDE = -I.

SRCDIR = ./
SRCS = ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_isalnum.c
SRCS += ft_isascii.c
SRCS += ft_isprint.c
SRCS += ft_strlen.c
SRCS += ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_strlcpy.c
SRCS += ft_strlcat.c
SRCS += ft_toupper.c
SRCS += ft_tolower.c
SRCS += ft_strchr.c
SRCS += ft_strrchr.c
SRCS += ft_strncmp.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_strnstr.c
SRCS += ft_atoi.c
SRCS += ft_calloc.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

all: $(NAME)

$(NAME): $(OBJS)
	ar r $@ $^

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: main.o $(OBJS)
	$(CC) $^ -o $(TARGET)
