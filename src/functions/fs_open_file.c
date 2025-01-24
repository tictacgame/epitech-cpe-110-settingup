/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** fs_open_file
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int fs_open_file(char const *filepath)
{
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    return fd;
}
