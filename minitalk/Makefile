# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = minitalk

INCLUDE = -I ./

SRCDIR = ./
SRCS = common.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

$(NAME): all

all: client server

client: $(OBJS) $(SRCDIR)client.o
	$(CC) $^ -o $@

server: $(OBJS) $(SRCDIR)server.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	rm -f $(OBJS) $(SRCDIR)client.o $(SRCDIR)server.o

fclean: clean
	rm -f client
	rm -f server

re: fclean all
