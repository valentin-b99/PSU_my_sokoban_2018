/*
** EPITECH PROJECT, 2018
** set_map_size_coords
** File description:
** set_map_size_coords
*/

#include "../../include/my_sokoban.h"

void set_map_size(main_t *main, char *buff)
{
    int nb_col = 0;

    main->map_size.x = 0;
    main->map_size.y = 1;
    for (int i = 0; buff[i] != 0; i++) {
        if (buff[i] == '\n' && main->map_size.x < nb_col)
            main->map_size.x = nb_col;
        if (buff[i] == '\n') {
            main->map_size.y += 1;
            nb_col = -1;
        }
        nb_col++;
    }
}

void set_coords(coords_t *main_type, coords_t *coords, int *tmp)
{
    main_type[*tmp].x = coords->x;
    main_type[*tmp].y = coords->y;
    *tmp += 1;
}