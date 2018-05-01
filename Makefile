# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 19:11:37 by jkimmina          #+#    #+#              #
#    Updated: 2018/04/30 20:15:24 by jkimmina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERFLG = -Iinc/ -Ilibft/

HDR = 		libft.h				\
			ft_printf.h			\
			ft_printf_conv.h	\
			ft_printf_flags.h	\
			ft_printf_struct.h	\
			get_next_line.h	

LIBFTSRC =	ft_atoi.c			\
			ft_bzero.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_itoa_base.c		\
			ft_lstadd.c			\
			ft_lstdel.c			\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_memalloc.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memdel.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_putchar.c		\
			ft_putchar_fd.c		\
			ft_putendl.c		\
			ft_putendl_fd.c		\
			ft_putnbr.c			\
			ft_putnbr_fd.c		\
			ft_putstr.c			\
			ft_putstr_fd.c		\
			ft_strcat.c			\
			ft_strchr.c			\
			ft_strclr.c			\
			ft_strcmp.c			\
			ft_strcpy.c			\
			ft_strdel.c			\
			ft_strdup.c			\
			ft_strequ.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlen.c			\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strncat.c		\
			ft_strncmp.c		\
			ft_strncpy.c		\
			ft_strnequ.c		\
			ft_strnew.c			\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strsplit.c		\
			ft_strstr.c			\
			ft_strsub.c			\
			ft_strtrim.c		\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_uitoa.c			\
			ft_uitoa_base.c		\
			ft_sitoa.c			\
			ft_nextspace.c		\
			ft_nextword.c		\
			ft_nextl.c			\
			ft_pow.c			\
			ft_abs.c			\
			ft_strndup.c		\
			get_next_line.c		\
			ft_strtointarr.c	\
			ft_wordcount.c		\
			ft_putintarr.c		

SRC = 		ft_printf.c			\
			ft_printf_flags.c	\
			ft_printf_conv.c	\
			conv_char.c			\
			conv_num.c			\
			ft_printf_struct.c		

OBJ =	$(SRC:.c=.o) $(LIBFTSRC:.c=.o)

CFLAGS = -c -Wall -Werror -Wextra

all: $(NAME) test

$(NAME):
	@gcc $(CFLAGS) $(HEADERFLG) $(addprefix src/, $(SRC)) $(addprefix libft/, $(LIBFTSRC))
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

test: $(NAME)
	@gcc main.c $(HEADERFLG) -L. -lftprintf -o test

clean:
	@/bin/rm -f $(OBJ) inc/*.gch*

fclean: clean
	@/bin/rm -f $(NAME) test

re: fclean all
