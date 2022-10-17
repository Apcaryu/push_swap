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
	unsigned int	e_idx;
	unsigned int	s_idx;

	set_bottom_top(*tabs, &s_idx, &e_idx, target);
	tmp = tabs->tab[e_idx];
	while (s_idx < e_idx)
	{
		tabs->tab[e_idx] = tabs->tab[e_idx - 1];
		e_idx--;
	}
	tabs->tab[s_idx] = tmp;
}
