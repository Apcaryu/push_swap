#include "test.h"

void	print_tab(int *tab)
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

void	init_test(t_tab_ab tabs)
{
	int idx = 0;
	while (idx < tabs.size)
	{
		printf("%d\n", tabs.tab[idx]);
		idx++;
	}
	printf("pos top a = %u\n", tabs.top_a);
}

void	new_print_tab(t_tab_ab tabs, char target)
{
	int idx;

	idx = 0;
	if ((target == 'a' || target == 's') && 0xFFFFFFFF != (int)tabs.top_a)
	{
		while (idx <= tabs.top_a)
		{
			printf("\033[35m%d\n", tabs.tab[idx]);
			idx++;
		}
		printf("\033[35ma\n");
	}
	if ((target == 'b' || target == 's') /*&& tabs.top_a < tabs.size - 1*/)
	{
		idx = tabs.top_a + 1;
		while (idx < tabs.size)
		{
			printf("\033[33m%d\n", tabs.tab[idx]);
			idx++;
		}
		printf("\033[33mb\n");
	}
	printf("\033[38m------------------------------------------\n");
}
