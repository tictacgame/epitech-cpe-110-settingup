/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** get_x_y
*/

#include <stdbool.h>
#include "my.h"

int getrows(char *str)
{
    int i = 0;
    int total_rows = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            total_rows++;
        }
    }
    return total_rows;
}

int getcols(char *str, bool is_generated)
{
    int i = 0;
    int total_cols = 0;
    int nbr_len = 0;

    if (!is_generated)
        nbr_len = my_calc_nbr_len(my_getnbr(str)) + 1;
    for (i = nbr_len; str[i] != '\0'; i++) {
        total_cols++;
        if (str[i] == '\n')
            return total_cols - 1;
    }
    return total_cols;
}
