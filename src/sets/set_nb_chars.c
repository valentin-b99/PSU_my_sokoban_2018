/*
** EPITECH PROJECT, 2018
** set_nb_chars
** File description:
** set_nb_chars
*/

#include "../../include/my_sokoban.h"

int count_char(char c, char *buff)
{
    int nb = 0;

    for (int i = 0; buff[i] != 0; i++)
        if (buff[i] == c)
            nb++;
    return (nb);
}

void set_nb_char(main_t *main, char *buff)
{
    int nb_p = count_char('P', buff);

    main->nb_sh = count_char('#', buff);
    main->nb_x = count_char('X', buff);
    main->nb_o = count_char('O', buff);
    if (nb_p != 1 || main->nb_x != main->nb_o)
        exit(84);
}