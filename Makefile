# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kburalek <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 09:45:38 by kburalek          #+#    #+#              #
#    Updated: 2023/10/03 09:45:40 by kburalek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

# Source Files (mandatory)
SOURCES_DIRECTORY = ./sources/mandatory/
SOURCES_LIST = pipex.c ft_error_and_free.c ft_close_pipe.c ft_fork_process.c ft_execute_cmd.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# Source Files (bonus)
SOURCES_DIRECTORY_BONUS = ./sources/bonus/
SOURCES_LIST_BONUS = pipex_bonus.c ft_error_and_free_bonus.c ft_close_pipe_bonus.c ft_fork_process_bonus.c ft_execute_cmd_bonus.c
SOURCES_BONUS = $(addprefix $(SOURCES_DIRECTORY_BONUS), $(SOURCES_LIST_BONUS))

# Object Files (mandatory)
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# Object Files (bonus)
OBJECTS_DIRECTORY_BONUS = objects_bonus/
OBJECTS_LIST_BONUS = $(patsubst %.c, %.o, $(SOURCES_LIST_BONUS))
OBJECTS_BONUS = $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_BONUS))

.PHONY: all clean fclean re bonus

# Targets (mandatory)
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

#Targets (bonus)
bonus: CFLAGS += -DBONUS
bonus: $(LIBFT) $(OBJECTS_DIRECTORY_BONUS) $(OBJECTS_BONUS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS_BONUS) -o $(NAME)

$(OBJECTS_DIRECTORY_BONUS):
	mkdir -p $(OBJECTS_DIRECTORY_BONUS)

$(OBJECTS_DIRECTORY_BONUS)%.o: $(SOURCES_DIRECTORY_BONUS)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@


$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@rm -rf $(OBJECTS_DIRECTORY_BONUS)

fclean: clean
	@rm -rf $(LIBFT)
	@rm -rf $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all

