/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c for project EvalExpr
*/

#include "include/my_evalexpr.h"
#include "include/my.h"

int eval_expr(char *str)
{
    char ** pni = conversion(str);
    int result = calc(pni);
    return result;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
