/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban
*/

#include "../include/my_sokoban.h"

void test_valid_map(char *buff)
{
    if (buff[0] == 0)
        exit(84);
    for (int i = 0; buff[i] != 0; i++) {
        if (buff[i] != '#' && buff[i] != ' ' && buff[i] != 'P' &&
        buff[i] != 'X' && buff[i] != 'O' && buff[i] != '\n') {
            my_putstr("Error: This file contain not autorized characters.");
            exit(84);
        }
    }
}

int my_sokoban(char *buff)
{
    WINDOW *window;
    int active = 1;
    main_t *main = init_main_struct(buff);

    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        refresh();
        if (COLS >= main->map_size.x && LINES >= main->map_size.y)
            display_map(main);
        else
            display_size_term();
        analyse_events(main);
    }
    endwin();
    free(window);
    return (0);
}

void read_map(char *path, char **buff)
{
    int len;
    int offset = 0;
    int file = open(path, O_RDONLY);
    struct stat st;

    stat(path, &st);
    *buff = malloc(sizeof(char) * (st.st_size + 1));
    while ((len = read(file, (*buff) + offset, (st.st_size + 1) - offset)) > 0)
        offset = offset + len;
    (*buff)[offset] = '\0';
    close(file);
}

int main(int ac, char **av)
{
    char *buff;

    if (ac != 2)
        display_error(134);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        display_error(135);
    display_error(errno);
    read_map(av[1], &buff);
    display_error(errno);
    test_valid_map(buff);
    my_sokoban(buff);
    free(buff);
    return (0);
}