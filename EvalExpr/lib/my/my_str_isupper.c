/*
** EPITECH PROJECT, 2020
** my_str_isupper.c
** File description:
** check if only upper letter
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 65 && str[i] <= 90)) {
            return 0;
        }
    }
    return 1;
}
