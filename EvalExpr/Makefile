##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for project EvalExpr
##

SRC	=	calc.c\
		conversion.c\
		do_op.c\
		function_operator.c\
		cond_function.c\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

all:	lib/include $(NAME) clean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy

lib/include:
	make -C lib/my

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME) clean
