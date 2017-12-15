# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 17:28:03 by pnardozi          #+#    #+#              #
#    Updated: 2017/12/15 19:48:39 by pnardozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = 	ft_unicode.c \
		ft_convert_o.c \
		ft_convert_u.c \
		ft_convert_i.c \
		ft_convert_d.c \
		ft_convert_x.c \
		ft_convert_x_base.c \
		ft_convert_p.c \
		ft_convert_c.c \
		ft_convert_c_flags.c \
		ft_convert_s.c \
		ft_convert_smaj.c \
		ft_convert_smaj_flags.c \
		ft_convert_percent.c \
		ft_s_remp_right.c \
		ft_s_remp_left.c \
		ft_smaj_remp_right.c \
		ft_remp_right.c \
		ft_remp_left.c \
		ft_unsigned_remp.c \
		ft_unsigned_remp2.c \
		printf.c \
		printf2.c \
		ft_verif_before_print.c \
		select.c \
		select_widht.c \
		select_modifier.c \
		select_precision.c \
		read_params.c \
		ft_base_remp.c \
		ft_base_hex_remp_r.c \
		ft_base_hex_remp_l.c \
		ft_smaj_remp_left.c \
		ft_split_printf.c \
		ft_split_printf2.c \
		ft_split_printf3.c 

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

INCLUDES = .

RED = \033[31m
GREEN = \033[32m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar rc tmp.a $(OBJ)
	ar rc $(NAME) tmp.a $(LIB)
	rm -rf tmp.a
	@echo "$(GREEN)PRINTF READY$(END)"

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	make clean -C libft
	/bin/rm -f $(OBJ)
	@echo "$(RED)FT_PRINTF OBJECTS REMOVE$(END)"

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)
	@echo "$(RED)FT_PRINTF REMOVE$(END)"

re: fclean all

.PHONY: all clean fclean re
