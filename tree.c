/*
** EPITECH PROJECT, 2020
** tree.c
** File description:
** 1/10/2020
*/
#include <stdio.h>

void my_putchar(char c);

int trunk(int size)
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
int nbLines(int size)
{
    int result = 0;
    int cpSizes = 0;

    for (cpSizes; cpSizes != size; cpSizes++)
        result = result + 4 + cpSizes;
    return result;
}

void putSpaces(int size, int lines)
{
    int space = (size * 3) + (size / 2);
            printf("%d\n", space);

    for (space; 0 < space; space--) {
        my_putchar(' ');
        if (lines > 0) {
            lines--;
        }
    }
}

void leaves(int size)
{
    int lines = nbLines(size);

    for (int i = 0; i < lines; i++) {
        putSpaces(size, lines);               //ICI
    }

    my_putchar('\n');
}

void tree(int size)
{
    leaves(size);
    trunk(size);
}
