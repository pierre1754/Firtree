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
    int h = 0;

    if (size % 2 == 0)
        h--;

    for (y; y < size; y++) {
        for (int g = 0; g < size * 3 + h; g++)
            my_putchar(' ');
        for (x; x < size - h; x++)
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
    int result = (4 * size) - size + size / 2;
    /* printf("%d, ", result); */
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

void my_correction(int rank, int size, int *correction, int *star_in_more)
{
    int space = 4 + rank;
    int d = 0;

    for (space; space > 0; space--) {
        d = space - rank + nbspaces_max(size) - *star_in_more / 4;
    }
    if (d != -1) {
        while (d + *correction != -1) {
            if (d < -1)
                --*correction;
            else
                ++*correction;
        }
    }
}

void triangle(int rank, int size, int *star_in_more, int *correction)
{
    int nbr_star = 1 + *star_in_more;
    int space = 4 + rank;
    int cp_space = space;
    int i = 0;
    int d = 0;

    for (space; space > 0; space--) {
        i = space - rank + nbspaces_max(size) - *star_in_more / 4 + *correction;
        printf("%d, ", i);
        my_put_space(i);
        my_put_star(nbr_star);
        my_putchar('\n');
        nbr_star += 4;
        }
}

int leaves(int size)
{
    int star_in_more = 0;
    int part_section = 8;
    int j = 0;
    int correction = 0;
    int rank = 0;

    for (rank; rank < size; rank++) {
        my_correction(rank, size, &correction, &star_in_more);
        star_in_more += part_section;
        if (j == 1) {
            part_section += 4 ;
            j = 0;
        }
        j++;
    }
    j = 0;
    star_in_more = 0;
    part_section = 8;
    for (rank = 0; rank < size; rank++) {
        triangle(rank, size, &star_in_more, &correction);
        star_in_more += part_section;
        if (j == 1) {
            part_section += 4 ;
            j = 0;
        }
        j++;
    }
}

void tree(int size)
{
    leaves(size);
    trunk(size);
}
