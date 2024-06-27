NAME = push_swap
SRC = main.c check_arg.c movement.c new_fonction.c main_sort.c cost_calcul.c dernier.c dernier2.c
OBJ = $(SRC:.c=.o)
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make bonus -C ./libft

$(FT_PRINTF):
	make -C ./ft_printf

clean:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
