/*
** EPITECH PROJECT, 2018
** move_boxs
** File description:
** move_boxs
*/

#include "../../include/my_sokoban.h"

int test_move_box_possible(main_t *main, int x, int y, int i)
{
    for (int j = 0; j < main->nb_sh; j++) {
        if (x + (x - main->co_p.x) == main->co_sh[j].x &&
            y + (y - main->co_p.y) == main->co_sh[j].y)
            return (0);
    }
    for (int j = 0; j < main->nb_x; j++) {
        if (x + (x - main->co_p.x) == main->co_x[j].x &&
            y + (y - main->co_p.y) == main->co_x[j].y)
            return (0);
    }
    if (x == main->co_x[i].x && y == main->co_x[i].y)
        return (1);
    return (0);
}

void move_box(main_t *main, int x, int y, int i)
{
    for (int j = 0; j < main->nb_sh; j++) {
        if (test_move_box_possible(main, x, y, i)) {
            main->co_x[i].x += x - main->co_p.x;
            main->co_x[i].y += y - main->co_p.y;
        }
    }
}
