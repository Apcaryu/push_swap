#include "instruction_set.h"
#include "test.h"

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

void	move_or_not(t_tab_ab *tabs)
{
	char do_rotate;

	do_rotate = 0;

	if (tabs->tab[tabs->top_a - 1] < tabs->tab[tabs->top_a] && !check_order(*tabs))
		swap(tabs, 'a');
	if (!check_order(*tabs))
		rotate(tabs, 'a', 0);
	new_print_tab(*tabs, 'a');
}