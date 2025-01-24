/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** fs_cat_500_bytes
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void fs_cat_500_bytes(char const *filepath)
{
    int fd = fs_open_file(filepath);
    char buf[500];

    read(fd, buf, 500);
    write(1, buf, my_strlen(buf));
    close(fd);
}
