#ifdef TESTING
#include <stdio.h>
#endif

int	find_pivot(int *arr, int n) {
	int i;
	int l = 0;
	int r = 0;

	i = -1;
	while (++i < n) l += arr[i];
	while (--i >= 0) {
		l -= arr[i];
#ifdef TESTING
//		printf("%d, %d\n", l, r);
#endif
		if (l == r) return (i);
		r += arr[i];
	}
	return (-1);
}

#ifdef TESTING
int	main(void) {
	int a1[4] = {-5, 10, 2, 5};
	int a2[6] = {1, 2, 3, 4, 0, 6};
	int a3[5] = {1, 100, 0, 0, 1};
	int a4[3] = {7, 8, 9};
	int a5[2] = {1, 2};

	printf("%d\n", find_pivot(a1, 4));
	printf("%d\n", find_pivot(a2, 6));
	printf("%d\n", find_pivot(a3, 5));
	printf("%d\n", find_pivot(a4, 3));
	printf("%d\n", find_pivot(a5, 2));
	return (0);
}
#endif
