/*
** EPITECH PROJECT, 2020
** tree.c
** File description:
** 1/10/2020
*/
#include <stdio.h>

void my_putchar(char c);

void trunk(int size)
{
    int x = 0;
    int y = 0;

    for (y; y < size; y++) {
        for (int i = 0; i < size * 3; i++)
            my_putchar(' ');
        for (x; x < size; x++)
            my_putchar('|');
        my_putchar('\n');
        x = 0;
    }
}

int heigh(int size)
{
    int result = 0;
    int cpSizes = 0;

    for (cpSizes; cpSizes != size; cpSizes++)
        result = result + 4 + cpSizes;
    return result;
}

int nbspaces_max(int size)
{
    int result = (4 * size) - size;

    return result;
}

void my_put_space(int space_var)
{
    for (int k = 0; k <= space_var; k++)
        my_putchar(' ');
}

void my_put_star(int nbr_star)
{
    for (int i = 0; i < nbr_star; i += 2)
        my_putchar('*');
}

void triangle(int rank, int size, int *rank_sup)
{
    int nbr_star = 1 + *rank_sup;
    int space = 4 + rank;
    int i = 0;
    int h = 0;
    int position = 0;

    for (space; space > 0; space--) {
        i = space - rank + nbspaces_max(size);
        my_put_space(i);
        my_put_star(nbr_star);
        my_putchar('\n');
        if (h != 0) {
            nbr_star += 4;
            h++;
        }
        if (h == 0) {
            nbr_star += 4;
            h++;
        }
    }
}

int leaves(int size)
{
    int rank_sup = 0;
    for (int rank = 0; rank < size; rank++) {
        triangle(rank, size, &rank_sup);
        rank_sup += 4;
    }
}

void tree(int size)
{
    leaves(size);
    /* trunk(size); */
}
