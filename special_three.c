#include "push_swap.h"

unsigned int	get_max_pos(t_tab_ab data_tabs, t_min_max_ab mm_ab)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_tabs.top_a)
	{
		if (data_tabs.tab[idx] == mm_ab.max_a)
			return (idx);
		idx++;
	}
	return (idx);
}

void	special_three(t_tab_ab *data_tabs)
{
	t_min_max_ab mm_ab;

	init_min_max_ab(&mm_ab);
//	printf("idx = %u", get_max_pos(*data_tabs)); // TODO remove
	while (!is_sorted(*data_tabs))
	{
		set_min_max(*data_tabs, &mm_ab);
//		new_print_tab(*data_tabs, 's'); // TODO remove
//		printf("idx = %u\n", get_max_pos(*data_tabs, mm_ab));
//		sleep(1);
		if (get_max_pos(*data_tabs, mm_ab) == 2)
			rotate(data_tabs, 'a', false);
		else if (get_max_pos(*data_tabs, mm_ab) == 1)
			rotate(data_tabs, 'a', true);
		else if (get_max_pos(*data_tabs, mm_ab) == 0)
			swap(data_tabs, 'a');
	}
}