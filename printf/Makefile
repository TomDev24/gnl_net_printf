NAME = libftprintf.a
LIBFT = ./libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror


OBJS = *.o
PRINTF_O = ft_printf.o handlers.o handlers2.o utils.o 
CONVERT_O = convert/x_convert.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(PRINTF_O) $(CONVERT_O) $(OBJS) $(LIBFT)
	ar rc $(NAME) $(OBJS) $(CONVERT_O)
	ranlib $(NAME)

$(LIBFT):
	(cd libft; make all)
	ar -x $(LIBFT)

$(PRINTF_O): %.o : %.c libftprintf.h 
	$(CC) $(FLAGS) -o $@ -c $< 

$(CONVERT_O): %.o : %.c libftprintf.h 
	$(CC) $(FLAGS) -o $@ -c $< 

test:
	rm -f ./tests/a.out
	$(CC) $(FLAGS) -o ./tests/a.out ./tests/main.c $(NAME)


clean:
	rm -f $(OBJS) '__.SYMDEF SORTED'
	(cd libft; make clean)

copy:
	cp -r  ./* ../gnl_net_print/printf;

fclean: clean
	rm -f $(NAME)
	(cd libft; make fclean)

re: fclean $(NAME)
