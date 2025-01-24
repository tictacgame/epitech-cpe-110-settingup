/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup
** File description:
** my_settingup
*/

#ifndef INCLUDED_MY_SETTINGUP_H
    #define INCLUDED_MY_SETTINGUP_H
    #define BUF_SIZE 31250

    #include <stdbool.h>

typedef struct args {
    char **map;
    char symbole;
    int nb_rows;
    int nb_cols;
    int best_row;
    int best_col;
    int best_square_size;
} args_t;

typedef struct tmpv {
    int row;
    int col;
    int square_size;
    int max_square_size;
    int best_row;
    int best_col;
} tmp_t;

int fs_get_number_from_first_line(char const *filepath);
int fs_open_file(char const *filepath);
char *load_file_in_mem(char const *filepath);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
char **load_2d_arr_from_buffer(char *buf, int nb_rows, int nb_cols);
int is_square_of_size(args_t *args, tmp_t *tmpv);
int find_and_replace_biggest_square(args_t *args, bool is_generated);
int getrows(char *str);
int getcols(char *str, bool is_generated);
int free_and_return(char *buf);
int free_args_and_return(args_t *args);
int free_args(args_t *args);

#endif
