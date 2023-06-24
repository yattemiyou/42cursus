# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = debug

INCLUDE = -I ./

SRCDIR = ./
SRCS = get_next_line.c
SRCS += get_next_line_utils.c
SRCS += main.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -DBUFFER_SIZE=1 -DOPEN_MAX=42 -DSSIZE_MAX=LONG_MAX
CFLAGS += -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o debug

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
