NAME = libftprintf.a
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ft_printf.h

SRC = ft_parse_format_pourcent.c ft_parse_format_ltr.c ft_parse_format0.c ft_parse_format1.c ft_parse_format2.c ft_parse_format3.c ft_parse_format4.c ft_parse_regle.c ft_display_capital_s.c ft_display_little_c.c ft_display_capital_c.c ft_putnchar.c ft_isdigit.c ft_putchar.c ft_strcpy.c ft_strdup.c ft_itoa.c ft_strdup.c ft_memdel.c ft_strsplit.c ft_nb_ltr.c ft_nb_mots.c ft_index_mot.c ft_strchr.c ft_atoi.c ft_strlen.c ft_strdel.c\
ft_putwstr_len.c ft_wstr_len.c ft_itoa_base_max.c ft_display_di_z.c ft_display_wchar.c ft_display_p.c ft_display_di_h.c ft_display_di_hh.c ft_display_di_j.c ft_display_di_none.c ft_display_di_l.c ft_find_nbr.c ft_putstr_len.c ft_display_char.c ft_display_htag.c ft_aff_struct.c ft_display_c.c ft_cchr.c ft_display_s.c ft_itoa_base.c ft_atoi_base.c ft_putwchar.c ft_nbrlen.c ft_strrev.c ft_printf.c ft_display.c ft_itoa.c ft_init_struct.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

OBJ_LIBFT = ./libft/ft_putchar.o ft_isdigit ft_atoi ft_isdigit ft_itoa ft_putstr\
 ft_strchr ft_strlen

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

.PHONY: clean fclean all re

clean:
	/bin/rm -f $(OBJ) $(OBJ_LIBFT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
