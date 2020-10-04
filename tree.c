/*
** EPITECH PROJECT, 2020
** tree.c
** File description:
** 1/10/2020
*/

void my_putchar(char c);

int nbspaces_max(int size)
{
    int t = 0;
    int n = 0;

    for (int i = size; i > 0; i--) {
        n = n + 3 + (t / 2);
        t++;
    }
    return n;
}

void trunk(int size)
{
    int x = 0;
    int y = 0;
    int h = 0;
    int w = nbspaces_max(size);

    if (size % 2 == 0) {
        h++;
    }
    for (; y < size; y++) {
        for (int g = 0; g < w - size / 2; g++)
            my_putchar(' ');
        for (; x < size + h; x++) {
            my_putchar('|');
        }
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

void my_put_star(int nbr_star)
{
    for (int i = 0; i < nbr_star; i++)
        my_putchar('*');
}

void my_put_space(int space)
{
    for (int k = 0; k < space; k++) {
        my_putchar(' ');
    }
}

void triangle(int part, int *nbr_star, int *space)
{
    int rank = 4 + part;

    for (; rank > 0; rank--) {
        my_put_space(*space);
        my_put_star(*nbr_star);
        my_putchar('\n');
        --*space;
        *nbr_star += 2;
    }
}

void leaves(int size)
{
    int d = 1;
    int part = 0;
    int nbr_star = 1;
    int space = nbspaces_max(size);

    for (part = 0; part < size; part++) {
        triangle(part, &nbr_star, &space);
        if (part % 2 == 0) {
            d++;
        }
        space += d;
        nbr_star -= d * 2;
    }
}

void tree(int size)
{
    leaves(size);
    trunk(size);
}
