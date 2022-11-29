#include "push_swap.h"

void	all_in_a(t_tab_ab *data_tabs)
{
	while (data_tabs->tab[data_tabs->top_a + 1] != data_tabs->max)
		rotate(data_tabs, 'b', 0);
	while (data_tabs->top_a < data_tabs->size - 1 || data_tabs->top_a == UINT_MAX)
		push(data_tabs, 'a');
	if (data_tabs->tab[0] == data_tabs->min)
		rotate(data_tabs, 'a', 1);
}