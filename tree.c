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
    int res = size * 3;
    if (size >= 3)
        res += size - 2;
    return res;
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

void triangle(int part, int size, int *nbr_star, int *d)
{
    int rank = 4 + part;
    int space = nbspaces_max(size);
    int i = 0;


    for (; rank > 0; rank--) {
        space--;
        if (part != 0 && rank == 4 + part) {
            if (part <= 4) {
                space++;
            }
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
