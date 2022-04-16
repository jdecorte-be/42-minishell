NAME = minishell

CC = gcc

CFLAGS = -lreadline -g -fsanitize=address # -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew//opt/readline/include

RM = rm -rf

SRCS = 	src/main.c\
        src/utils.c\
		src/ft_error.c\
		src/cleanstr.c\
		\
		src/builtins/rep.c\
		src/builtins/echo.c\
		src/builtins/env.c\
		src/builtins/export.c\
		src/builtins/unset.c\
		src/builtins/utils.c\
		\
        libft/libft.a\
		src/signal/signal.c\
		src/builtins/exit.c\
		\
		src/lst/*.c\
		src/utils/*\
		src/exec/exec_2.c\
		src/exec/exec.c\
		src/exec/ope.c\
		src/exec/ope_2.c\


$(NAME) :
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME)

clean :
	make clean -C libft
	$(RM) $(NAME)

re : fclean all
