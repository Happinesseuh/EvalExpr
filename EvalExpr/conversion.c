/*
** EPITECH PROJECT, 2020
** conversion
** File description:
** convert infix notations into the two ones
*/

#include "./include/my.h"
#include "include/my_evalexpr.h"
#include <stdlib.h>

static void number_conversion(char const *str, int *i, int *j, char **arr)
{
    int size = 0;
    int k = 0;

    if (str[*i + size] == '-')
        size += 1;
    for (; str[*i + size] >= '0' && str[*i + size] <= '9'; size += 1);
    arr[*j] = malloc(sizeof(char) * size);
    if (str[*i] == '-') {
        arr[*j][k] = str[*i];
        k += 1;
        *i += 1;
    }
    for (; str[*i] >= '0' && str[*i] <= '9'; *i += 1) {
        arr[*j][k] = str[*i];
        k += 1;
    }
    *j += 1;
    *i -= 1;
}

static void push_stack(char *stack, char **arr, int *k, int *j)
{
    *k -= 1;
    for (; *k >= 0 && stack[*k] != '('; *k -= 1) {
        arr[*j] = malloc(1);
        arr[*j][0] = stack[*k];
        *j += 1;
    }
    if (stack[*k] != '(')
        *k += 1;
}

void top_stack(char *stack, char const * str, int *k, int i)
{
    stack[*k] = str[i];
    *k += 1;
}

void final_conversion(char *stack, char **arr, int *k, int *j)
{
    push_stack(stack, arr, k, j);
    free(stack);
    arr[*j] = malloc(1);
    arr[*j][0] = '\0';
}

char **conversion(char const *str)
{
    char *stack = malloc(sizeof(char) * my_strlen(str));
    char **arr = malloc(sizeof(char *) * my_strlen(str));
    int j = 0;
    int k = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_weak_op(str[i]) && k != 0 && !is_neg_sign(i, str) && !is_neg_bracket(i, str)) {
            if (is_strong_op(stack[k - 1]))
                push_stack(stack, arr, &k, &j);
            top_stack(stack, str, &k, i);
        }
        if (is_strong_op(str[i]) || str[i] == '('
            || (is_weak_op(str[i]) && k == 0 && !is_neg_sign(i, str) && !is_neg_bracket(i, str)))
            top_stack(stack, str, &k, i);
        if (str[i] == ')')
            push_stack(stack, arr, &k, &j);
        if (is_num(str[i]) || is_neg_sign(i, str))
            number_conversion(str, &i, &j, arr);
        if (is_neg_bracket(i, str)) {
            stack[k] = '*';
            arr[j] = malloc(sizeof(char) * 2);
            arr[j][0] = '-';
            arr[j][1] = '1';
            k += 1;
            j += 1;
        }
    }
    final_conversion(stack, arr, &k, &j);
    return (arr);
}
/* int main (void) */
/* { */
/*     char *test = "-(10/2)--1"; */
/*     char **jsp = conversion(test); */
/*     for (int i = 0; i <= 5; i++) */
/*         printf("%s\n", jsp[i]); */
/*     return 0; */
/* } */
