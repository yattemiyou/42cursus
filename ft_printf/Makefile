# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = libftprintf.a

INCLUDE = -I ./include

SRCDIR = ./src/
SRCS = ft_printf.c
SRCS += ft_print_char.c
SRCS += ft_print_decimal.c
SRCS += ft_print_string.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

CC = cc
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
	$(CC) $^ -o debug
