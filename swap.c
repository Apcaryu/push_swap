#include "instruction_set.h"

void	swap(int *tab, char heap)
{
	int tmp;

	if (1 < tab_lenght(tab) && (heap == 'a' || heap == 'b'))
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
		if (heap == 'a')
			write(1, "sa\n", 3);
		else if (heap == 'b')
			write(1, "sb\n", 3);
		return;
	}
	write(1, "ERROR SWAP\n", 11);
}

void	new_swap(t_tab_ab *tabs, char target)
{
	int tmp;

	if (target == 'a')
	{
		if (0 < tabs->top_a)
		{
			tmp = tabs->tab[tabs->top_a];
			tabs->tab[tabs->top_a] = tabs->tab[tabs->top_a - 1];
			tabs->tab[tabs->top_a - 1] = tmp;
		}
	}
}