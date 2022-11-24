#include "instruction_set.h"
#include "test.h"

char	check_order(t_tab_ab tabs)
{
	unsigned int	idx;

	idx = tabs.top_a;
	while (0 < idx)
	{
		if (tabs.tab[idx - 1] < tabs.tab[idx])
			return (0);
		idx--;
	}
	return (1);
}

char	check_minmax(t_tab_ab tabs, int min, int max)
{
	if (tabs.tab[tabs.top_a - 1] == min && tabs.tab[tabs.top_a] == max)
		return (1);
	return (0);
}

int	get_max(t_tab_ab tabs)
{
	int 			val_max;
	unsigned int	idx;

	val_max = tabs.tab[0];
	idx = 1;
	while (idx <= tabs.top_a)
	{
	    if (val_max < tabs.tab[idx])
			val_max = tabs.tab[idx];
	    idx++;
	}
	return (val_max);
}

int	get_min(t_tab_ab tabs)
{
	int 			val_min;
	unsigned int	idx;

	val_min = tabs.tab[0];
	idx = 1;
	while (idx <= tabs.top_a)
	{
		if (val_min > tabs.tab[idx])
			val_min = tabs.tab[idx];
		idx++;
	}
	return (val_min);
}

void	move_or_not(t_tab_ab *tabs)
{
	char	do_rotate;
	int		min;
	int		max;

	do_rotate = 0;

	min = get_min(*tabs);
	max = get_max(*tabs);
	while (!check_order(*tabs))
	{
		if (check_minmax(*tabs, min, max))
			rotate(tabs, 'a', 0);
		if (tabs->tab[tabs->top_a - 1] < tabs->tab[tabs->top_a] && !check_order(*tabs))
			swap(tabs, 'a');
		if (!check_order(*tabs))
			rotate(tabs, 'a', 0);
	}
//	new_print_tab(*tabs, 'a');
}