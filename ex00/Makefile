# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                          e8'   8   '8e           #
#                                                      +:+                     #
#    By: averheij <averheij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/11 15:02:04 by averheij      #+#    #+#                  #
#    Updated: 2021/11/22 15:23:05 by dries               **ee8ee**             #
#                                                                              #
# **************************************************************************** #

NAME		=	scalar_converter
CPPFILES	=	scalar_converter.cpp Multitype.cpp
OBJDIR		=	objects
OFILES		=	$(CPPFILES:%.cpp=$(OBJDIR)/%.o)
OS      	=   $(shell uname)
ifeq ($(OS),Linux)
	CC		=	g++
else
	CC		=	clang++
endif
FLAGS		=	-Wall -Werror -Wextra -std=c++98 -pedantic
#FLAGS =

all: $(NAME)

$(NAME): $(OBJDIR) $(OFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OFILES)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	-rm $(OFILES)

fclean: clean
	-rm -rf $(OBJDIR)
	-rm $(NAME)

re: fclean all
