NAME = avm

VPATH = src

CC = clang++

FLAGS = -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -g

SRCS = main.cpp					\
	   Lexer.cpp				\
	   FreeLexer.cpp			\

BIN_DIR = bin/

BINS = $(addprefix $(BIN_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(BINS)
	$(CC) $(FLAGS) $(BINS) -o $(NAME)

$(BIN_DIR)%.o: %.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(FLAGS) -c -o $@ $<

src/FreeLexer.cpp: flex/FreeLexer.l
	flex -o $@ $<

clean:
	/bin/rm -rf $(BIN_DIR)
	/bin/rm -f src/FreeLexer.cpp

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
