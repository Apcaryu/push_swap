#include "instruction_set.h"

static void	set_bottom_top(t_tab_ab tabs, unsigned int *bottom, unsigned int *top, char target)
{
	if (target == 'a')
	{
		*bottom = 0;
		*top = tabs.top_a;
	}
	else if (target == 'b')
	{
		*bottom = tabs.size - 1;
		*top = tabs.top_a + 1;
	}
}

void	rotate(t_tab_ab *tabs, char target, char is_reverse)
{
	int	tmp;
	unsigned int	idx;

	idx = tabs->top_a;
	tmp = tabs->tab[tabs->top_a];
	while (0 < idx)
	{
		tabs->tab[idx] = tabs->tab[idx - 1];
		idx--;
	}
	tabs->tab[0] = tmp;
}
