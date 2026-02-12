SRCS = srcs/main.c \
		srcs/game.c \
		srcs/map.c \
		srcs/player.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)
CC = cc
FLAGS = -g
LDFLAGS = -lm -lpthread -ldl  # raylib dependencies
NAME = game
INCLUDE_DIRS = -I include

all: objs $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) lib/libraylib.a $(LDFLAGS) $(INCLUDE_DIRS) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@

objs:
	mkdir objs

re: fclean all

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

.PHONY: all re clean fclean
