#include "instruction_set.h"

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
