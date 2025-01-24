/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** fs_get_number_from_first_line
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int fs_get_number_from_first_line(char const *str)
{
    int nbr = 0;
    int i = 0;
    char *buf;

    for (i = 0; str[i] != '\n'; i++);
    buf = malloc(sizeof(char) * i);
    for (int j = 0; j < i; j++)
        buf[j] = str[j];
    buf[i] = '\0';
    nbr = my_getnbr(buf);
    free(buf);
    return nbr;
}
