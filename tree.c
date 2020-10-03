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

void putSpace(int actualSpace, int nbSpaces)
{
    if (actualSpace < nbSpaces) {
        my_putchar(' ');
        putSpace(actualSpace + 1, nbSpaces);
    }
}

void leaves(int size, int nbLines)
{
    int nbSpaces = (size * 3) + (size / 2);
    int actualSpace = 0;
    int rankLines = 4;
    int rankIncr = 1;
    int part = size;

    for (nbLines; nbLines != 0; nbLines--) {
        putSpace(actualSpace, nbSpaces);
        my_putchar('*');
        nbSpaces--;
        my_putchar('\n');
        if (rankIncr == rankLines) {
            if (part != 0) {
                rankLines = rankLines + (size / part);
                part--;
                nbSpaces += 2;
            }
        }
        rankIncr++;
    }
}

void tree(int size)
{
    leaves(size, nbLines(size));
    /* trunk(size); */
}
