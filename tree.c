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

int heigh(int size)
{
    int result = 0;
    int cpSizes = 0;

    for (cpSizes; cpSizes != size; cpSizes++)
        result = result + 4 + cpSizes;
    return result;
}

int nbSpacesMAX(int size)
{
    int result = (4 * size) - size;

    return result;
}

void my_putSpace(int spaceVar)
{
    for (int k = 0; k <= spaceVar; k++) {
        my_putchar(' ');
    }
}
int partSize(int size)
{

}

void part(int size)
{
    int draw = nbSpacesMAX(size);
    int spaceVar = draw;
    int heighMAX = heigh(size);
    int currentHeigh = 1;
    int part = 4;
    int lineReturn = 0;
    int j = 0;

    for (int p = 0; p < size; p++) {
        j = 0;
        spaceVar = draw;
        for (int i = 1; i <= draw; i += 2) {
            my_putSpace(spaceVar);
            spaceVar--;
            for (j; j < i; j++) {
                my_putchar('*');
            }
            j = 0;
            if (currentHeigh == part) {
                lineReturn = (3 * size) / (part + 1) + 1;
                part = (part * 2) + 1;
                for (int h = 0; h < lineReturn; h++)
                    spaceVar++;
                j += lineReturn * 2;
            }
            currentHeigh++;
            my_putchar('\n');
        }
    }
}

void tree(int size)
{
    part(size);
    /* trunk(size); */
}
