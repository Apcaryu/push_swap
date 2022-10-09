#include "test.h"

static void	print_tab(int *tab)
{
	unsigned int	idx;
	unsigned int	size_tab;

	idx = 0;
	size_tab = tab_lenght(tab);
	while (idx <= size_tab)
	{
		printf("pos %u - %d\n", idx, tab[idx]);
		idx++;
	}
}

void	test(int argc, char *argv[], int *tab_a, int *tab_b)
{
	print_tab(tab_a);
	test_swap(tab_a, tab_b);
	print_tab(tab_a);
}
