/*
** EPITECH PROJECT, 2018
** events
** File description:
** events
*/

#include "../../include/my_sokoban.h"
#include <unistd.h>

int test_victory_box(main_t *main, coords_t co_x)
{
    for (int i = 0; i < main->nb_o; i++) {
        if (co_x.x == main->co_o[i].x && co_x.y == main->co_o[i].y)
            return (1);
    }
    return (0);
}

int test_victory(main_t *main)
{
    int nb = 0;

    for (int i = 0; i < main->nb_x; i++)
        if (test_victory_box(main, main->co_x[i]))
            nb += 1;
    if (nb == main->nb_x)
        return (1);
    return (0);
}

int test_lose(main_t *main)
{
    for (int i = 0; i < main->nb_x; i++)
        if (test_lose_box(main, main->co_x[i]))
            return (1);
    return (0);
}

void analyse_events(main_t *main)
{
    int ch = getch();

    test_move(main, ch);
    if (ch == ' ')
        my_sokoban(main->map);
    if (test_victory(main)) {
        endwin();
        write(1, "You win ! :)\n", 13);
        exit(0);
    }
    if (test_lose(main)) {
        endwin();
        write(1, "You lose ! :(\n", 14);
        exit(1);
    }
}