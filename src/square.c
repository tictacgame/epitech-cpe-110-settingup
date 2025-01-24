/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup [WSL: Ubuntu-24.04]
** File description:
** square
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_settingup.h"

int check_is_return(args_t *args, tmp_t *tmpv, int i, int j)
{
    if ((args->map[tmpv->row + i][tmpv->col + j] == 'o' ||
        args->map[tmpv->row + i][tmpv->col + j] == '\n')) {
        if (j > 1)
            j++;
        return 0;
    }
}

int is_square_of_size(args_t *args, tmp_t *tmpv)
{
    int should_return = 1;

    if (tmpv->row + tmpv->square_size > args->nb_rows ||
        tmpv->col + tmpv->square_size > args->nb_cols) {
        return 0;
    }
    for (int i = 0; i < tmpv->square_size && should_return; i++) {
        for (int j = 0; j < tmpv->square_size && should_return;
            j++) {
            should_return = check_is_return(args, tmpv, i, j);
        }
    }
    return should_return;
}

int replace_char_by_x(args_t *args, tmp_t *tmpv)
{
    for (int i = 0; i < tmpv->max_square_size; i++) {
        for (int j = 0; j < tmpv->max_square_size; j++) {
            args->map[tmpv->best_row + i][tmpv->best_col + j] = 'x';
        }
    }
    return 1;
}

int calc_square_size(args_t *args, tmp_t *tmpv)
{
    tmpv->square_size = tmpv->max_square_size;
    if (args->map[tmpv->row][tmpv->col] == '.' &&
        (tmpv->col + tmpv->square_size) <= args->nb_cols) {
        while (is_square_of_size(args, tmpv) &&
            (tmpv->col + tmpv->square_size) <= args->nb_cols) {
            tmpv->square_size++;
        }
        tmpv->square_size--;
        if (tmpv->square_size > tmpv->max_square_size) {
            tmpv->max_square_size = tmpv->square_size;
            tmpv->best_row = tmpv->row;
            tmpv->best_col = tmpv->col;
        }
    }
    return 0;
}

int find_and_replace_biggest_square(args_t *args, bool is_generated)
{
    tmp_t tmpv;

    tmpv.best_row = -1;
    tmpv.best_col = -1;
    tmpv.max_square_size = 0;
    tmpv.row = is_generated ? 0 : 1;
    for (; tmpv.row < args->nb_rows; tmpv.row++) {
        for (tmpv.col = 0; tmpv.col < args->nb_cols; tmpv.col++) {
            calc_square_size(args, &tmpv);
        }
    }
    if (tmpv.max_square_size > 0) {
        replace_char_by_x(args, &tmpv);
        args->best_row = tmpv.best_row;
        args->best_col = tmpv.best_col;
        args->best_square_size = tmpv.max_square_size;
        return tmpv.max_square_size;
    }
    return 0;
}
