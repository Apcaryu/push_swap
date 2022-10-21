#include "instruction_set.h"

void	swap(t_tab_ab *tabs, char target)
{
	int tmp;

	if (target == 'a')
	{
		if (0 < tabs->top_a)
		{
			tmp = tabs->tab[tabs->top_a];
			tabs->tab[tabs->top_a] = tabs->tab[tabs->top_a - 1];
			tabs->tab[tabs->top_a - 1] = tmp;
			write(1, "sa\n", 3);
		}
	}
	if (target == 'b')
	{
		if (2 < tabs->size - tabs->top_a)
		{
			tmp = tabs->tab[tabs->top_a + 1];
			tabs->tab[tabs->top_a + 1] = tabs->tab[tabs->top_a + 2];
			tabs->tab[tabs->top_a + 2] = tmp;
			write(1, "sb\n", 3);
		}
	}
}

void	super_swap(t_tab_ab *tabs)
{
	swap(tabs, 'a');
	swap(tabs, 'b');
}