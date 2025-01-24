/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** load_2d_arr_from_file
*/

#include "my.h"
#include "my_settingup.h"
#include <stdlib.h>
#include <stdio.h>

char **process_2d_arr(int nb_rows, int nb_cols, char **arr,
    char *buf)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len = my_calc_nbr_len(my_getnbr(buf)) + 1;

    for (k = 0; k < nb_rows; k++) {
        arr[k] = malloc(sizeof(char) * (nb_cols + 2));
        if (arr[k] == NULL) {
            return NULL;
        }
        for (j = 0; j < nb_cols + 1; j++) {
            arr[k][j] = buf[i + len];
            i++;
        }
        arr[k][j] = '\0';
    }
}

char **process_2d_arr_from_generated(int nb_rows, int nb_cols, char **arr,
    char *buf)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (k = 0; k < nb_rows; k++) {
        arr[k] = malloc(sizeof(char) * (nb_cols + 2));
        if (arr[k] == NULL) {
            return NULL;
        }
        for (j = 0; j < nb_cols + 1; j++) {
            arr[k][j] = buf[i];
            i++;
        }
        arr[k][j] = '\0';
    }
}

char **load_2d_arr_from_buffer(char *buf, int nb_rows, int nb_cols)
{
    char **arr;

    arr = malloc(sizeof(char *) * (nb_rows + 1));
    if (arr == NULL)
        return NULL;
    process_2d_arr_from_generated(nb_rows, nb_cols, arr, buf);
    free(buf);
    arr[nb_rows] = NULL;
    return arr;
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char **arr;
    char *buf = load_file_in_mem(filepath);

    if (nb_rows <= 0 || nb_cols <= 0 || buf == NULL)
        return NULL;
    arr = malloc(sizeof(char *) * (nb_rows + 1));
    if (arr == NULL)
        return NULL;
    process_2d_arr(nb_rows, nb_cols, arr, buf);
    free(buf);
    arr[nb_rows] = NULL;
    return arr;
}
