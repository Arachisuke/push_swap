NAME = push_swap
BONUS = checker

SRC = main.c ./srcs/check_arg.c ./srcs/movement.c ./srcs/new_fonction.c ./srcs/main_sort.c ./srcs/cost_calcul.c ./srcs/dernier.c ./srcs/dernier2.c \
		./srcs/cost_calcul2.c ./srcs/handle_utils.c ./srcs/movement_utils.c ./srcs/movement2.c ./srcs/movement3.c \

BSRCS = ./srcs/check_arg.c ./srcs/movement.c checker.c ./srcs/movement2.c ./srcs/movement3.c ./srcs/movement_utils.c ./srcs/handle_utils.c \

BOBJS = $(BSRCS:.c=.o)
OBJ = $(SRC:.c=.o)
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
GNL = ./GNL/libgnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3


$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

all: $(NAME) $(BONUS)

bonus : $(BONUS)

$(BONUS): $(BOBJS) $(LIBFT) $(FT_PRINTF) $(GNL)
	$(CC) $(CFLAGS) -o $(BONUS) $(BOBJS) $(LIBFT) $(FT_PRINTF) $(GNL)

$(LIBFT):
	make bonus -C ./libft

$(FT_PRINTF):
	make -C ./ft_printf
$(GNL):
	make -C ./GNL
clean:
	rm -f $(OBJ) $(BOBJS)
	make -C ./libft clean
	make -C ./ft_printf clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C ./libft fclean
	make -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
