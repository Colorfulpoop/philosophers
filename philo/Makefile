
NAME = philo

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SRC = main.c init.c utils.c thread.c actions.c 

OBJ = $(SRC:.c=.o)

CC = gcc
FLAG = -Wall -Werror -Wextra

%.o: %.c
	@$(CC) $(FLAG) -c $< -o $@

$(NAME):	$(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $(NAME) -g
	@echo "$(COLOUR_BLUE)$(NAME) has been created$(COLOUR_END)"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "$(COLOUR_RED)OBJ deleted$(COLOUR_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOUR_RED)$(NAME) deleted$(COLOUR_END)"

re: fclean all clean
