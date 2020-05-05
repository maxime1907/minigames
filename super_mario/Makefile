NAME            =       mario

LIB             =       -L/home/${USER}/.froot/lib/ -llapin \
                        -L/usr/local/lib \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
                        -lm

FLAG            =       -g -W -Wall -Wextra  -I/home/${USER}/.froot/include/

SRC             =       $(wildcard ./src/mario.c) \
			$(wildcard ./src/tektext.c) \
			$(wildcard ./src/tekgetpixel.c) \
			$(wildcard ./src/tekpixel.c) \
			$(wildcard ./src/tekcoldel.c) \
			$(wildcard ./src/tekblit.c)

OBJ             =       $(SRC:.c=.o)

CC              =       gcc

all:            $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.c.o:
	$(CC) -c $< -o $@ $(FLAG)
