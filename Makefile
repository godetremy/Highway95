NAME=Highway95

CC=gcc
RM=rm -f

SRC = src/ft_itoa.c src/ft_strjoin.c src/main.c src/logs.c src/initialization.c src/render.c src/road.c src/event.c src/view.c src/enemy.c \
      src/collide.c src/score.c src/player.c
OBJ = $(SRC:.c=.o)

CFLAGS=-Wall -Wextra -Werror -I/opt/homebrew/include
LDLIBS=-L/opt/homebrew/lib -lSDL2 -lSDL2_mixer -lSDL2_ttf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all