/*
** EPITECH PROJECT, 2018
** general_moves
** File description:
** general_moves
*/

#include "../../include/my_sokoban.h"

void move_all(main_t *main, int x, int y)
{
    for (int i = 0; i < main->nb_sh; i++)
        if (x == main->co_sh[i].x && y == main->co_sh[i].y)
            return;
    for (int i = 0; i < main->nb_x; i++)
        move_box(main, x, y, i);
    for (int i = 0; i < main->nb_x; i++)
        if (x == main->co_x[i].x && y == main->co_x[i].y)
            return;
    main->co_p.x = x;
    main->co_p.y = y;
}

void test_move(main_t *main, int ch)
{
    if (ch == KEY_UP)
        move_all(main, main->co_p.x, main->co_p.y - 1);
    if (ch == KEY_DOWN)
        move_all(main, main->co_p.x, main->co_p.y + 1);
    if (ch == KEY_RIGHT)
        move_all(main, main->co_p.x + 1, main->co_p.y);
    if (ch == KEY_LEFT)
        move_all(main, main->co_p.x - 1, main->co_p.y);
    if (ch == KEY_END || ch == 'q') {
        endwin();
        exit(1);
    }
}
