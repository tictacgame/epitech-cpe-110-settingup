/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** fs_print_first_line
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

char *load_file_in_mem(char const *filepath)
{
    int fd = fs_open_file(filepath);
    long int size = 0;
    char *buf;
    struct stat file_stat;

    if (fd == -1)
        return NULL;
    if (stat(filepath, &file_stat) == -1)
        return NULL;
    buf = malloc(file_stat.st_size + 1);
    if (buf == NULL)
        return NULL;
    size = read(fd, buf, file_stat.st_size);
    if (buf[size - 1] != '\n') {
        free(buf);
        return NULL;
    }
    buf[size] = '\0';
    return buf;
}
