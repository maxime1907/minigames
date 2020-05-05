##
## Makefile for starwars in /home/maxime1907/Documents/tictoe_r
## 
## Made by maxime1907
## Login   <maxime.leroy@epitech.eu>
## 
## Started on  Thu Sep 21 15:38:51 2017 maxime1907
## Last update Thu Sep 21 16:14:29 2017 maxime1907
##

NAME	= starwars

CC	= g++

RM	= rm -f

SRCS	= ./src/main.cpp \
	  ./src/GameManager.cpp \
	  ./src/Player.cpp \
	  ./src/Shoot.cpp \

OBJS	= $(SRCS:.cpp=.o)

LDFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS = -I inc/
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
