/*
** EPITECH PROJECT, 2018
** set_colors
** File description:
** set_colors
*/

#include "../../include/my_sokoban.h"

void set_colors(void)
{
    init_color(COLOR_GREEN, 0, 800, 0);
    init_color(COLOR_RED, 400, 150, 150);
    init_color(COLOR_MAGENTA, 350, 0, 0);
    init_color(COLOR_YELLOW, 600, 600, 0);
    init_color(COLOR_CYAN, 400, 400, 0);
    init_color(COLOR_WHITE, 500, 450, 0);
    init_pair(1, COLOR_CYAN, COLOR_YELLOW);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_RED);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_WHITE);
}