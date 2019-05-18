/*
** EPITECH PROJECT, 2018
** set_main_struct
** File description:
** set_main_struct
*/

#include "../../include/my_sokoban.h"

void set_main_struct_malloc(main_t *main)
{
    main->co_sh = malloc(sizeof(coords_t) * (main->nb_sh + 1));
    main->co_x = malloc(sizeof(coords_t) * (main->nb_x + 1));
    main->co_o = malloc(sizeof(coords_t) * (main->nb_o + 1));
}

void init_main_struct_next(main_t *main, coords_t *coords, char *buff, int i)
{
    if (buff[i] == '\n') {
        coords->y++;
        coords->x = -1;
    }
    if (buff[i] == 'P') {
        main->co_p.x = coords->x;
        main->co_p.y = coords->y;
    }
}

main_t *init_main_struct(char *buff)
{
    main_t *main = malloc(sizeof(main_t));
    coords_t coords = {.x = 0, .y = 0};
    counter_tmp_t tmp = {0, 0, 0};

    main->map = buff;
    set_nb_char(main, buff);
    set_map_size(main, buff);
    set_main_struct_malloc(main);
    for (int i = 0; buff[i] != 0; i++) {
        init_main_struct_next(main, &coords, buff, i);
        if (buff[i] == '#')
            set_coords(main->co_sh, &coords, &tmp.sh);
        if (buff[i] == 'O')
            set_coords(main->co_o, &coords, &tmp._o);
        if (buff[i] == 'X')
            set_coords(main->co_x, &coords, &tmp.x);
        coords.x++;
    }
    return (main);
}