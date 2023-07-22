# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = minitalk

INCLUDE = -I ./

SRCDIR = ./
SRCS = ft_common.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

$(NAME): all

all: client server

client: $(OBJS) $(SRCDIR)ft_client.o
	$(CC) $^ -o $@

server: $(OBJS) $(SRCDIR)ft_server.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	rm -f $(OBJS) $(SRCDIR)ft_client.o $(SRCDIR)ft_server.o

fclean: clean
	rm -f client
	rm -f server

re: fclean all
