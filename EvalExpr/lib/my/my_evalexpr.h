/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** header
*/

#ifndef MY_EVALEXPR_
#define MY_EVLAEXPR_

int do_op(int a, int b, char op);
int calc(char **arr);
int is_operator(char c);
int is_strong_op(char c);
int is_weak_op(char c);
int is_num(char c);
char **conversion(char const *str);

#endif /* MY_EVALEXPR_ */
