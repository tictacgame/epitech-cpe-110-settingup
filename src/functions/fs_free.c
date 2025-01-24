/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** fs_free
*/

#include "my_settingup.h"
#include <stdlib.h>

int free_and_return(char *buf)
{
    free(buf);
    return 84;
}

int free_args_and_return(args_t *args)
{
    for (int i = 0; args->map[i] != NULL; i++)
        free(args->map[i]);
    free(args->map);
    return 84;
}

int free_args(args_t *args)
{
    for (int i = 0; args->map[i] != NULL; i++)
        free(args->map[i]);
    free(args->map);
}
