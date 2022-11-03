#include "instruction_set.h"

char	check_order(t_tab_ab tabs)
{
	unsigned int	idx;

	idx = tabs.top_a - 1;
	while (0 < idx)
	{
		if (tabs.tab[idx] < tabs.tab[idx + 1])
			return (0);
		idx--;
	}
	return (1);
}
