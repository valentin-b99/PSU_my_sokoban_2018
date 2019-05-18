/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** display_map
*/

#include "../../include/my_sokoban.h"

void display_x_on_o(main_t *main, int i)
{
    for (int j = 0; j < main->nb_o; j++) {
        if (main->co_x[i].x == main->co_o[j].x &&
        main->co_x[i].y == main->co_o[j].y) {
            attron(COLOR_PAIR(6));
            mvprintw(main->co_x[i].y + (LINES - main->map_size.y) / 2,
            main->co_x[i].x + (COLS - main->map_size.x) / 2, "X");
            attroff(COLOR_PAIR(6));
        }
    }
}

void display_o_x(main_t *main)
{
    for (int i = 0; i < main->nb_o; i++) {
        attron(COLOR_PAIR(2));
        mvprintw(main->co_o[i].y + (LINES - main->map_size.y) / 2,
        main->co_o[i].x + (COLS - main->map_size.x) / 2, "O");
        attroff(COLOR_PAIR(2));
    }
    for (int i = 0; i < main->nb_x; i++) {
        attron(COLOR_PAIR(1));
        mvprintw(main->co_x[i].y + (LINES - main->map_size.y) / 2,
        main->co_x[i].x + (COLS - main->map_size.x) / 2, "X");
        attroff(COLOR_PAIR(1));
        display_x_on_o(main, i);
    }
}

void display_p(main_t *main)
{
    mvprintw(main->co_p.y + (LINES - main->map_size.y) / 2,
    main->co_p.x + (COLS - main->map_size.x) / 2, "P");
}

void display_sh(main_t *main)
{
    for (int i = 0; i < main->nb_sh; i++)
        mvprintw(main->co_sh[i].y + (LINES - main->map_size.y) / 2,
        main->co_sh[i].x + (COLS - main->map_size.x) / 2, "#");
}

void display_map(main_t *main)
{
    display_o_x(main);
    display_p(main);
    display_sh(main);
}