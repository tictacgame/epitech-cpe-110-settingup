/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** my_getnbr
*/

#include <stdio.h>

int my_data_nbr(int i, const char *str)
{
    int tempint = 1;
    long my_long = 0;

    if (i > 0 && str[i - 1] == '-') {
        tempint = -1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        my_long = (my_long * 10) + (str[i] - '0');
        i++;
    }
    my_long *= tempint;
    if (my_long < -2147483648 || my_long > 2147483647) {
        return 0;
    }
    return my_long;
}

int my_getnbr(const char *str)
{
    int index = 0;
    int final_int = 0;

    if (str == NULL) {
        return 0;
    }
    while (str[index] != '\0' && (str[index] < '0' || str[index] > '9')) {
        index++;
    }
    if (str[index] >= '0' && str[index] <= '9') {
        final_int = my_data_nbr(index, str);
    }
    return final_int;
}
