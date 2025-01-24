/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** nbrtostr
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

/*
** PARAMS
** nbr : the nbr to return as string
** EXEMPLE :
** nbrtostr(42)
** it will return, "42"
*/
char *nbrtostr(int number)
{
    int len = 0;
    char *str_number = NULL;

    if (number < 0) {
        number *= -1;
        my_putchar('-');
    }
    len = my_calc_nbr_len(number);
    if (number == 0)
        my_putchar('0');
    str_number = malloc(sizeof(char) * len + 1);
    for (len = 0; number > 0; len++) {
        str_number[len] = ((number % 10) + '0');
        number /= 10;
    }
    str_number[len] = '\0';
    str_number = my_revstr(str_number);
    return str_number;
}
