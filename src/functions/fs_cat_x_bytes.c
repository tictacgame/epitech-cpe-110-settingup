/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** fs_cat_x_bytes
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd = fs_open_file(filepath);
    char *buf = malloc(sizeof(char) * x);

    read(fd, buf, x);
    write(1, buf, x);
    my_putchar('\n');
    free(buf);
    close(fd);
}
