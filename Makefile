CC = gcc
CCFLAGS = -Wall -Werror -Wextra
CLEAN = rm
CLEAN_FLAGS = -f
SRC = main.c \
	  read_line.c \
	  string.c \
	  split_line.c \
	  execute.c \
	  launch.c \
	  ft_strsplit.c \
	  launch_command.c \
	  is_file.c \
	  is_dir.c \
	  builtin_env.c

OBJ = main.o \
	  read_line.o \
	  string.o \
	  split_line.o \
	  execute.o \
	  launch.o \
	  ft_strsplit.o \
	  launch_command.o \
	  is_file.o \
	  is_dir.o \
	  builtin_env.o

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CC) $(CCFLAGS) -c $^

re: fclean all

clean:
	$(CLEAN) $(CLEAN_FLAGS) $(OBJ)
	$(CLEAN) $(CLEAN_FLAGS) *~
fclean: clean
	$(CLEAN) $(CLEAN_FLAGS) $(NAME)
