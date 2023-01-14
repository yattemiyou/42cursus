# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
TARGET = main.exe

NAME = libft.a

INCLUDE = -I.

SRCDIR = ./
SRCS = ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_isalnum.c

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
