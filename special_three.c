#include "push_swap.h"

unsigned int	get_max_pos(t_tab_ab data_tabs)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_tabs.top_a)
	{
		if (data_tabs.tab[idx] == data_tabs.max)
			return (idx);
		idx++;
	}
	return (idx);
}

void	special_three(t_tab_ab *data_tabs)
{
//	printf("idx = %u", get_max_pos(*data_tabs)); // TODO remove
	while (!is_sorted(*data_tabs))
	{
		if (get_max_pos(*data_tabs) == 2)
			rotate(data_tabs, 'a', false);
		else if (get_max_pos(*data_tabs) == 1)
			rotate(data_tabs, 'a', true);
		else if (get_max_pos(*data_tabs) == 0)
			swap(data_tabs, 'a');
	}
}