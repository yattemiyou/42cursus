# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = push_swap

INCLUDE = -I ./

SRCDIR = ./
SRCS = main.c
SRCS += ft_chunk.c
SRCS += ft_error.c
SRCS += ft_operation.c
SRCS += ft_sort.c
SRCS += ft_stack.c
SRCS += ft_util.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
