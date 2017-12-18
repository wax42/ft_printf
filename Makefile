NAME = libftprintf.a
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ft_printf.h

SRC = ft_find_nbr.c ft_putstr_len.c ft_display_char.c ft_display_htag.c ft_aff_struct.c ft_display_c.c ft_cchr.c ft_display_cs.c ft_itoa_base.c ft_atoi_base.c ft_putwchar.c ft_nbrlen.c ft_strrev.c ft_printf.c ft_display.c ft_itoa.c ft_init_struct.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

OBJ_LIBFT = ./libft/ft_putchar.o ft_isdigit ft_atoi ft_isdigit ft_itoa ft_putstr\
 ft_strchr ft_strlen

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	ar rcs $(NAME) $(OBJ) $(OBJ)

.PHONY: clean fclean all re

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ) $(OBJ_LIBFT)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
