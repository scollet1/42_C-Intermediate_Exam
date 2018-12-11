
#include <stdio.h>

int		AB(int a, int b) {return ((a * 10) + b);}

int		CA(int c, int a) {return (AB(c, a));}

void	equation(int n) {
	int		a;
	int		b;
	int		c;

	if (n > 198)
		return ;
	if (n == 0) {
		printf("A = 0, B = 0, C = 0\n");
	} else {
		c = 10;
		while (--c > -1) {
			b = 10;
			while (--b > -1) {
				a = -1;
				while (++a < 10) {
					if ((AB(a, b) + CA(c, a)) == n)
						printf("A = %d, B = %d, C = %d\n", a, b, c);
				}
			}
		}
	}
}


#ifdef TESTING
int		main(void) {
	equation(42);
	equation(111);
	equation(0);
	return (0);
}
#endif
