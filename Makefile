NAME = avm

VPATH = src

CC = clang++

FLAGS = -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -g

SRCS = main.cpp					\
	   Lexer.cpp				\
	   Parser.cpp				\
	   OperandFactory.cpp

BIN_DIR = bin/

BINS = $(addprefix $(BIN_DIR), $(SRCS:.cpp=.o))

LEXER_LEX = src/flex/FreeLexer.l

LEXER_SRC = src/FreeLexer.cpp

LEXER = bin/FreeLexer.o

all: $(NAME)

$(NAME): $(BINS) $(LEXER)
	$(CC) $(FLAGS) $(BINS) $(LEXER) -o $(NAME)

$(BIN_DIR)%.o: %.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(FLAGS) -c -o $@ $<

$(LEXER): $(LEXER_SRC)
	$(CC) -Wall -Wextra -Werror -Wno-sign-compare -c -o $@ $<

$(LEXER_SRC): $(LEXER_LEX)
	flex -o $@ $<

clean:
	/bin/rm -rf $(BIN_DIR)
	/bin/rm -f src/FreeLexer.cpp

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

tests:
	make -C test/ re
