/*
** EPITECH PROJECT, 2020
** tree.c
** File description:
** 1/10/2020
*/

void my_putchar(char c);

void trunk(int size)
{
    int x = 0;
    int y = 0;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            my_putchar('|');
        }
        my_putchar('\n');
        x = 0;
    }
}

void tree(int size)
{
    trunk(size);
}
