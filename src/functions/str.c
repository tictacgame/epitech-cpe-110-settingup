/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** str
*/

#include <unistd.h>
#include "my.h"

/*
** PARAMS
** char c : the char to print
** EXEMPLE
** my_putchar('a');
** It will print 'a' on standard output
*/
int my_putchar(char c)
{
    write(1, &c, 1);
}

/*
** PARAMS
** char const *str : Buff to count len
** EXEMPLE
** my_strlen("Hello World !");
** It will return 13
*/
int my_strlen(char const *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++);
    return i;
}

/*
** PARAMS
** char const *str : Buff to show
** EXEMPLE
** my_putstr("Hello World !");
** It will print "Hello World !" on standard output
*/
int my_putstr(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        my_putchar(str[index]);
        index++;
    }
    return index + 1;
}

/*
** PARAMS
** char const *str : Buff to show
** EXEMPLE
** my_revstr("Hello World !");
** It will print "! dlroW olleH" on standard output
*/
char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    char temp;
    int add = 0;

    if (len % 2 == 1)
        add = 1;
    for (i = 0; i < len / 2 + add; i++) {
        temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    return (str);
}
