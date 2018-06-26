CC = gcc
CCFLAGS = -Wall -Werror -Wextra
CLEAN = rm
CLEAN_FLAGS = -f
SRC = main.c \
	  read_line.c \
	  string.c \
	  split_line.c \
	  execute.c \
	  launch.c
OBJ = main.o \
	  read_line.o \
	  string.o \
	  split_line.o \
	  execute.o \
	  launch.o
NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CC) $(CCFLAGS) -c $^

re: fclean all

clean:
	$(CLEAN) $(CLEAN_FLAGS) $(OBJ)

fclean: clean
	$(CLEAN) $(CLEAN_FLAGS) $(NAME)
