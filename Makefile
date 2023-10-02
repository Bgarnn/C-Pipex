# Project Name
NAME = pipex

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Libraries and Includes
LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBRARIES = -lm -lft -L$(LIBFT_DIRECTORY)
LIBFT_HEADER = $(LIBFT_DIRECTORY)

HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = pipex.h error.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADER)

# Source Files
SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = pipex.c ft_error.c ft_close_free.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# Object Files
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# Targets
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@rm -rf $(LIBFT)
	@rm -rf $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
