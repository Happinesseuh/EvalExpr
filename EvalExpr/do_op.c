/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "include/my.h"
#include "include/my_evalexpr.h"

int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int modulo(int a, int b);

int do_op(int a, int b, char op)
{
    int (*operator[48])(int, int);

    operator['+'] = &add;
    operator['-'] = &substract;
    operator['*'] = &multiply;
    operator['/'] = &divide;
    operator['%'] = &modulo;
    return operator[op](a, b);
}
