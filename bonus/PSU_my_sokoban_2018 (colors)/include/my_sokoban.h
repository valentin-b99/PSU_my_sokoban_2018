/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "my.h"

#define BUFF_SIZE 2048

typedef struct coords_s
{
    int x;
    int y;
} coords_t;

typedef struct counter_tmp_s
{
    int sh;
    int _o;
    int x;
} counter_tmp_t;

typedef struct main_s
{
    char *map;
    coords_t map_size;
    coords_t co_p;
    int nb_sh;
    coords_t *co_sh;
    int nb_x;
    coords_t *co_x;
    int nb_o;
    coords_t *co_o;
} main_t;

void test_valid_map(char *);
int my_sokoban(char *);
void read_map(char *, char **);

void display_error(int);
void test_disp_width(int *, int *, int *);
void display_size_term(void);

void display_x_on_o(main_t *, int);
void display_o_x(main_t *);
void display_p(main_t *);
void display_sh(main_t *);
void display_map(main_t *);

int test_victory_box(main_t *, coords_t);
int test_victory(main_t *);
int test_lose(main_t *);
void analyse_events(main_t *);

int test_box_border(main_t *, coords_t);
int test_box_box(main_t *, coords_t, int, int);
int test_lose_box(main_t *, coords_t);

void move_all(main_t *, int, int);
void test_move(main_t *, int);

int test_move_box_possible(main_t *, int, int, int);
void move_box(main_t *, int, int, int);

void set_colors(void);

void set_main_struct_malloc(main_t *);
void init_main_struct_next(main_t *, coords_t *, char *, int);
main_t *init_main_struct(char *);

void set_map_size(main_t *main, char *);
void set_coords(coords_t *, coords_t *, int *);


int count_char(char, char *);
void set_nb_char(main_t *, char *);

#endif /* !MY_SOKOBAN_H_ */
