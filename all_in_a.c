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
	t_data_dist data_dist;

	mm_ab.min_a = INT_MAX;
	mm_ab.max_a = INT_MIN;
	mm_ab.min_b = INT_MAX;
	mm_ab.max_b = INT_MIN;
	init_data_dist(&data_dist);
	set_min_max(*data_tabs, &mm_ab);
	while (data_tabs->top_a < data_tabs->size - 1)
	{
		distance(*data_tabs, &data_dist, mm_ab);
		if (data_dist.reverse_a == data_dist.reverse_b)
		{
			while (data_dist.nb_rr_rrr)
			{
				rotate(data_tabs, 's', data_dist.reverse_a);
				data_dist.nb_rr_rrr--;
			}
		}
		while (data_tabs->tab[data_tabs->top_a + 1] != data_dist.num)
			rotate(data_tabs, 'b', data_dist.reverse_b);
		while (check_push_in_a(*data_tabs, &mm_ab) == false)
			rotate(data_tabs, 'a', data_dist.reverse_a);
		push(data_tabs, 'a');
		set_min_max(*data_tabs, &mm_ab);
		data_dist.dist = UINT_MAX;
		data_dist.num = 0;
		data_dist.idx = UINT_MAX;
	}
}