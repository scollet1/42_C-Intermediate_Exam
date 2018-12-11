#include <stdio.h>

void    count_alpha(const char *str) {
    int map[27];
    char    idx[27];
    char    c;
    short   i;
    short   j;

    i = 0;

    while (i < 27)
        map[i++] = 0;
    i = 0;
    while (*str) {
        c = ((*str >= 'A' && *str <= 'Z'))?
            *str + 32 : *str;
        if (c >= 'a' && c <= 'z') {
            if (!map[(int)c - 'a']) {
                idx[i++] = c;
                map[(int)c - 'a'] = 0;
            }
            map[(int)c - 'a'] += 1;
        }
        str++;
    }

    j = i;
    i = -1;
    while (++i < j) {
        printf("%d%c", map[(int)idx[i] - 'a'], idx[i]);
        if (i != j - 1)
            printf(", ");
        else break;
    }
}

int main(int ac, char **av) {
    if (ac == 2) {
        count_alpha(av[1]);
    }
    printf("\n");
    return (0);
}
