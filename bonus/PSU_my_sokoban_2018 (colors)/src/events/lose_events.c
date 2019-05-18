/*
** EPITECH PROJECT, 2018
** lose_events
** File description:
** lose_events
*/

#include "../../include/my_sokoban.h"

int test_box_border(main_t *main, coords_t co_x)
{
    int check = 0;

    for (int i = 0; i < main->nb_sh; i++) {
        if (co_x.x - 1 == main->co_sh[i].x && co_x.y == main->co_sh[i].y)
            check += 681;
        if (co_x.x + 1 == main->co_sh[i].x && co_x.y == main->co_sh[i].y)
            check += 769;
        if (co_x.x == main->co_sh[i].x && co_x.y - 1 == main->co_sh[i].y)
            check += 180;
        if (co_x.x == main->co_sh[i].x && co_x.y + 1 == main->co_sh[i].y)
            check += 68;
    }
    return (check);
}

int test_box_box(main_t *main, coords_t co_x, int i, int j)
{
    int check = 0;

    if (co_x.x - 1 == main->co_x[i].x && co_x.y == main->co_x[i].y &&
        ((co_x.x - 1 == main->co_sh[j].x && co_x.y - 1 == main->co_sh[j].y)
        || co_x.x - 1 == main->co_sh[j].x && co_x.y + 1 == main->co_sh[j].y))
        check += 681;
    if (co_x.x + 1 == main->co_x[i].x && co_x.y == main->co_x[i].y &&
        ((co_x.x + 1 == main->co_sh[j].x && co_x.y - 1 == main->co_sh[j].y)
        || co_x.x + 1 == main->co_sh[j].x && co_x.y + 1 == main->co_sh[j].y))
        check += 769;
    if (co_x.x == main->co_x[i].x && co_x.y - 1 == main->co_x[i].y &&
        ((co_x.x - 1 == main->co_sh[j].x && co_x.y - 1 == main->co_sh[j].y)
        || co_x.x + 1 == main->co_sh[j].x && co_x.y - 1 == main->co_sh[j].y))
        check += 180;
    if (co_x.x == main->co_x[i].x && co_x.y + 1 == main->co_x[i].y &&
        ((co_x.x - 1 == main->co_sh[j].x && co_x.y + 1 == main->co_sh[j].y)
        || co_x.x + 1 == main->co_sh[j].x && co_x.y + 1 == main->co_sh[j].y))
        check += 68;
    return (check);
}

int test_lose_box(main_t *main, coords_t co_x)
{
    int check = 0;

    for (int i = 0; i < main->nb_o; i++)
        if (co_x.x == main->co_o[i].x && co_x.y == main->co_o[i].y)
            return (0);
    check += test_box_border(main, co_x);
    for (int i = 0; i < main->nb_x; i++)
        for (int j = 0; j < main->nb_sh; j++)
            check += test_box_box(main, co_x, i, j);
    if (check == 861 || check == 749 || check == 949 || check == 837 ||
        check == 1630 || check == 1017 || check == 1518 || check == 929)
        return (1);
    return (0);
}
