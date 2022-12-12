
NAME = pipex

# BONUS = 

SRC = pipex.c pipex_utils.c pipex_handlerr.c

# SRC_BONUS = 

CC = gcc

CFLAGS = -Wall -Werror -Wextra

COMPILE = $(CC) $(CFLAGS)

FT_PRINTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME):
	@make -C ./ft_printf
	@$(COMPILE) $(SRC) $(FT_PRINTF) -o $(NAME)

# bonus:
# 	make -C ./ft_printf
# 	$(COMPILE) $(SRC_BONUS) $(FT_PRINTF) -o $(BONUS)

clean:
	@make clean -C ./ft_printf

fclean:	clean
	@make fclean -C ./ft_printf
	@rm -f $(NAME) $(BONUS)

re: fclean all

# rebo: fclean all bonus

.PHONY: all clean fclean re bonus rebo
