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
    for (; y < size; y++) {
        for (int g = 0; g < size * 3 + h; g++)
            my_putchar(' ');
        for (; x < size - h; x++)
            my_putchar('|');
        my_putchar('\n');
        x = 0;
    }
}

int heigh(int size)
{
    int result = 0;
    int cp_sizes = 0;

    for (; cp_sizes != size; cp_sizes++)
        result = result + 4 + cp_sizes;
    return result;
}

int nbspaces_max(int size)
{
    return (4 * size) - size + size / 2;
}

void my_put_star(int nbr_star)
{
    for (int i = 0; i < nbr_star; i += 2)
        my_putchar('*');
}

void my_put_space(int space, int rank, int size)
{
    for (int k = 0; k <= space - rank; k++) {
        my_putchar(' ');
    }
}

/* void my_correction(int rank, int size, int *correction, int *star_in_more)
{
    int space = 4 + rank;
    int d = 0;

    for (; space > 0; space--)
        d = space - rank + nbspaces_max(size) - *star_in_more / 4;
    if (d != -1) {
        while (d + *correction != -1) {
            if (d < -1)
                ++*correction;
            else if (d > -1)
                --*correction;
        }
    }
} */

void triangle(int part, int size, int *nbr_star, int *d)
{
    int rank = 4 + part;
    int space = nbspaces_max(size);
    int i = 0;


    for (; rank > 0; rank--) {
        space--;
        if (part != 0 && rank == 4 + part) {
            space -= part + part - 1;
        }
        my_put_space(space, part, size);
        my_put_star(*nbr_star);
        my_putchar('\n');
        *nbr_star += 4;
    }
}

void leaves(int size)
{
    int star_in_more = 0;
    int part_section = 8;
    int j = 0;
    int d = 4;
    int x = 0;
    int h = 2;
    int correction = 0;
    int part = 0;
    int nbr_star = 1;

    /* for (; rank < size; rank++) {
        correction = 0;
        my_correction(rank, size, &correction, &star_in_more);
        star_in_more += part_section;
        if (j == 1) {
            part_section += 4 ;
            j = 0;
        }
        j++;
    }
    j = 0;
    part_section = 8; */
    for (part = 0; part < size; part++) {
        triangle(part, size, &nbr_star, &d);
        nbr_star -= 4;
        if (j == 2) {
            d += 4;
            j = 0;
        }
        h++;
        j++;
        nbr_star = nbr_star - d;
        /* printf("%d\n", d); */
    }
}

void tree(int size)
{
    leaves(size);
    trunk(size);
}
