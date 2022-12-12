
NAME = libftprintf.a

SRC =	ft_printf.c cases_s_c_p_d_i.c \
		cases_u_X_x_percent.c ft_hexatoa.c ft_printf_utils.c \
		libft/ft_putchar_fd.c libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c libft/ft_strlen.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

COMPILE = $(CC) $(CFLAGS) -c

LIBFT = ./libft/libft.a

%.o: %.c
	@$(COMPILE) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@cp $(LIBFT) $(NAME)
	@ar -rs $(NAME) $(OBJ)

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
