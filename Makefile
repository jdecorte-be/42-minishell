NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -g -fsanitize=address

RM = rm -rf

SRCS = 	src/main.c\
        src/utils.c\
		src/ft_error.c\
		src/parsing/clean.c\
		\
		src/builtins/cd.c\
		src/builtins/echo.c\
		src/builtins/env.c\
		src/builtins/export.c\
		\
        libft/libft.a\
		src/utils/*\
		src/signaux.c\
		src/exec/exec.c\
		src/exec/pipe.c\
		src/exec/ope.c\
		src/builtins/exit.c\

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