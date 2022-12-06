#include "push_swap.h"

unsigned int	list_traveler(t_tab_ab data_tabs)
{
	unsigned int	idx;

	idx = data_tabs.top_a;
	while (idx != UINT_MAX)
	{
		if (data_tabs.tab[data_tabs.top_a + 1] < data_tabs.tab[data_tabs.top_a] \
		&& data_tabs.tab[data_tabs.top_a + 1] > data_tabs.tab[0])
			break;
		idx--;
	}
	return (idx);
	
}

t_bool	numbers_moves(t_tab_ab data_tabs)
{
	unsigned int	idx;
	
	idx = list_traveler(data_tabs);
	if (idx < data_tabs.size / 2)
		return (true);
	else
		return (false);
}
