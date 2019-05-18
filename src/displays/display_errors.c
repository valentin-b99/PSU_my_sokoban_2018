/*
** EPITECH PROJECT, 2018
** display_errors
** File description:
** display_errors
*/

#include "../../include/my_sokoban.h"
#include "../../include/errors.h"

void display_error(int error)
{
    int i = 1;

    while (i != error && i < 137)
        i++;
    if (i < 135) {
        my_putstr(errors[i - 1].msg);
        my_putchar('\n');
        exit(84);
    }
    if (i == 135) {
        my_putstr(errors[i - 1].msg);
        my_putstr(errors[i].msg);
        my_putstr(errors[i + 1].msg);
        exit(84);
    }
}

void test_disp_width(int *disp_1_x, int *disp_2_x, int *disp_3_x)
{
    if (*disp_1_x < 0)
        *disp_1_x = 0;
    if (*disp_2_x < 0)
        *disp_2_x = 0;
    if (*disp_3_x < 0)
        *disp_3_x = 0;
}

void display_size_term(void)
{
    char *err_msg_1 = "Oops! :c";
    char *err_msg_2 = "Your Terminal is too small!";
    char *err_msg_3 = "Please resize it so that it can display the map!";
    int disp_1_x = (COLS - my_strlen(err_msg_1)) / 2;
    int disp_2_x = (COLS - my_strlen(err_msg_2)) / 2;
    int disp_3_x = (COLS - my_strlen(err_msg_3)) / 2;

    test_disp_width(&disp_1_x, &disp_2_x, &disp_3_x);
    mvprintw(LINES / 3, disp_1_x, err_msg_1);
    mvprintw(LINES / 2, disp_2_x, err_msg_2);
    mvprintw(LINES / 3 * 2, disp_3_x, err_msg_3);
}