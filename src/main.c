/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "my_settingup.h"

static void print_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        write(1, arr[i], my_strlen(arr[i]));
}

static int calculate_patern_off(int j, int pattern_size)
{
    j++;
    if (j >= pattern_size) {
        j = 0;
    }
    return j;
}

int draw_generated_map(char *buf, args_t *args)
{
    int val = 0;

    args->nb_cols = getcols(buf, true);
    args->nb_rows = getrows(buf);
    args->map = load_2d_arr_from_buffer(buf, args->nb_rows,
        args->nb_cols);
    if (args->map == NULL)
        return 84;
    val = find_and_replace_biggest_square(args, true);
    print_arr(args->map);
    free_args(args);
    return 0;
}

int draw_maps(char *filepath, args_t *args)
{
    char *buf;
    int val = 0;

    if (filepath[0] != 0) {
        buf = load_file_in_mem(filepath);
        if (buf == NULL)
            return 84;
        args->nb_cols = getcols(buf, false);
        args->nb_rows = getrows(buf) - 1;
        if (args->nb_rows != fs_get_number_from_first_line(buf))
            return free_and_return(buf);
        free(buf);
        args->map = load_2d_arr_from_file(filepath, args->nb_rows,
            args->nb_cols);
        if (args->map == NULL)
            return 84;
        val = find_and_replace_biggest_square(args, false);
        print_arr(args->map);
        free_args(args);
    }
}

/*
** PARAMS
** int size : representing the width and height of the maps
** char *pattern : pattern for generating maps
** Exemple :
** generate_map(5, "..o")
*/
char *generate_map(int size, char *pattern)
{
    int pattern_size = my_strlen(pattern);
    int total_chars = size * size + size;
    char *buf = malloc(total_chars + 2);
    int i = 0;
    int j = 0;
    int k = 0;

    if (!buf)
        return NULL;
    for (k = 0; k < size; k++) {
        for (i = 0; i < size; i++) {
            buf[k * (size + 1) + i] = pattern[j];
            j = calculate_patern_off(j, pattern_size);
        }
        buf[k * (size + 1) + size] = '\n';
    }
    buf[total_chars] = '\0';
    return buf;
}

/*
** TODO ->
** Erro Handling ->
** -> Maybe it's ok
** Map Generator
*/
int main(int ac, char **av)
{
    args_t args;
    int maps_result = 0;
    char *buf = NULL;
    int map_size = 0;

    args.best_col = 0;
    args.best_row = 0;
    args.best_square_size = 0;
    if (ac == 3) {
        map_size = my_getnbr(av[1]);
        if (map_size > 0) {
            buf = generate_map(map_size, av[2]);
            return draw_generated_map(buf, &args);
        }
        return 84;
    }
    for (int i = 1; i < ac; i++)
        if (draw_maps(av[i], &args) == 84)
            return 84;
    return 0;
}
