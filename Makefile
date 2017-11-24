NAME = avm

VPATH = src

CC = clang++

FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp					\
	   Lexer.cpp				\
	   FreeLexer.cpp			\

BIN_DIR = bin/

BINS = $(addprefix, $(SRCS:.cpp=.o))

$(BIN_DIR)%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

src/FreeLexer.cpp: flex/FreeLexer.l
	flex -o $@ $<

all: $(NAME)

$(NAME): $(BINS)
	$(CC) $(FLAGS) $(BINS) -o $(NAME)

clean:
	/bin/rm -f $(BIN_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean re
