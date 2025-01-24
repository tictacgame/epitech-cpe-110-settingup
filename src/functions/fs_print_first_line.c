/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** fs_print_first_line
*/

#include <unistd.h>
#include "my_settingup.h"

void fs_print_first_line(char const *filepath)
{
    int fd = fs_open_file(filepath);
    char buf[BUF_SIZE];
    int total_bytes_read = read(fd, buf, BUF_SIZE);
    int iterator = 0;

    for (iterator = 0; buf[iterator] != '\n'; iterator++);
    write(1, buf, iterator);
}
