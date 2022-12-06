#include "push_swap.h"

void	set_min_max(t_tab_ab data_tabs, t_min_max_ab *mm_ab)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_tabs.size)
	{
		if (idx <= data_tabs.top_a) {
			if (data_tabs.tab[idx] < mm_ab->min_a)
				mm_ab->min_a = data_tabs.tab[idx];
		}
		else if (data_tabs.top_a < idx) {
			if (data_tabs.tab[idx] < mm_ab->min_b)
				mm_ab->min_b = data_tabs.tab[idx];
		}
		idx++;
	}
	idx = 0;
	while (idx < data_tabs.size)
	{
		if (idx <= data_tabs.top_a) {
			if (data_tabs.tab[idx] > mm_ab->max_a)
				mm_ab->max_a = data_tabs.tab[idx];
		}
		else if (data_tabs.top_a < idx) {
			if (data_tabs.tab[idx] > mm_ab->max_b)
				mm_ab->max_b = data_tabs.tab[idx];
		}
		idx++;
	}
}

t_bool check_push_in_a(t_tab_ab data_tabs, t_min_max_ab *mm_ab)
{
	t_bool	output;

	if (data_tabs.tab[data_tabs.top_a + 1] < data_tabs.tab[data_tabs.top_a] \
	&& data_tabs.tab[data_tabs.top_a + 1] > data_tabs.tab[0])
		return (true);
	else if (data_tabs.tab[0] == mm_ab->max_a && mm_ab->max_a < data_tabs.tab[data_tabs.top_a + 1])
	{
		mm_ab->max_a = data_tabs.tab[data_tabs.top_a + 1];
		return (true);
	}
	else if (data_tabs.tab[data_tabs.top_a] == mm_ab->min_a && \
	(data_tabs.tab[data_tabs.top_a + 1] < mm_ab->min_a && data_tabs.tab[data_tabs.top_a]))
	{
		mm_ab->min_a = data_tabs.tab[data_tabs.top_a + 1];
		return (true);
	}
	return (false);
}

void	all_in_a(t_tab_ab *data_tabs)
{
	t_min_max_ab mm_ab;

	mm_ab.min_a = INT_MAX;
	mm_ab.max_a = INT_MIN;
	mm_ab.min_b = INT_MAX;
	mm_ab.max_b = INT_MIN;
	set_min_max(*data_tabs, &mm_ab);
//	printf("ma = %d Ma = %d | mb = %d Mb = %d\n", mm_ab.min_a, mm_ab.max_a, mm_ab.min_b, mm_ab.max_b);
//	printf("push? %d\n", check_push_in_a(*data_tabs, &mm_ab));
	while (data_tabs->top_a < data_tabs->size - 1)
	{
//		new_print_tab(*data_tabs, 's'); // TODO remove
		if (check_push_in_a(*data_tabs, &mm_ab))
			push(data_tabs, 'a');
		else
			rotate(data_tabs, 'a', 0);
	}
}