/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** my_putnbr
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

/*
** PARAMS
** int nbr : The number to get the len
** EXEMPLE
** my_calc_nbr_len(123);
** It will return 3
*/
int my_calc_nbr_len(int nbr)
{
    int tmp = nbr;
    int len = 0;

    for (len = 0; tmp != 0; len++) {
        tmp /= 10;
    }
    return len;
}

/*
** PARAMS
** nbr : the nbr to print
** EXEMPLE :
** my_put_nbr(42)
** it will print "42"
*/
int my_put_nbr(int number)
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
    len = my_putstr(my_revstr(str_number));
    free(str_number);
    return len;
}
