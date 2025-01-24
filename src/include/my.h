/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H

int my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_calc_nbr_len(int nbr);
int my_put_nbr(int number);
int fs_open_file(char const *filepath);
void fs_cat_500_bytes(char const *filepath);
void fs_cat_x_bytes(char const *filepath, int x);
int my_getnbr(char const *str);
char *nbrtostr(int number);

#endif
