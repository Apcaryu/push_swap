#include "push_swap.h"

char	check_order(t_tab_ab tabs)
{
	unsigned int	idx;

	idx = 0;
	while (idx < tabs.top_a)
	{
		if (tabs.tab[idx] > tabs.tab[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}
