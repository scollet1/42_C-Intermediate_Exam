
int		is_anagram(char *a, char *b) {
	char hash[94] = {0};
	int	offs;
	long int i;
	long int key;

	i = 0;
	offs = 32;
	while (a[i]) {
		key = a[i++] - offs;
		if (!hash[key])
			hash[key] = 0;
		hash[key]++;
	}
	i = 0;
	while (b[i]) {
		key = b[i] - offs;
		if (!hash[key])
			return (0);
		else if (-1 >= hash[key]--)
			return (0);
		i++;
	}
	return (1);
}

#ifdef TESTING
#include <stdio.h>
int	main(void) {
	printf("%d\n", is_anagram("abcdef", "fabcde"));
	printf("%d\n", is_anagram(".123?.", "?321.."));
	printf("%d\n", is_anagram("abca", "bcab"));
}
#endif
