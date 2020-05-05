NAME	= game

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

LDFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS = -I
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
