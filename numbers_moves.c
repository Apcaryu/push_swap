#include "push_swap.h"

// unsigned int	list_traveler(t_tab_ab data_tabs)
// {
// 	unsigned int	idx;

// 	idx = data_tabs.top_a;
// 	while (idx != UINT_MAX)
// 	{
// 		if (data_tabs.tab[data_tabs.top_a + 1] < data_tabs.tab[data_tabs.top_a] \
// 		&& data_tabs.tab[data_tabs.top_a + 1] > data_tabs.tab[0])
// 			break;
// 		idx--;
// 	}
// 	return (idx);
// }

t_bool check_where(t_tab_ab data_tabs, t_min_max_ab mm_ab, int number, unsigned int idx)
{
	t_bool	output;
	unsigned int z_idx;

	z_idx = idx + 1;
	if (data_tabs.top_a + 1 < z_idx)
		z_idx = 0;
//	printf("z_idx = %u\n", z_idx); // TODO remove
	if (number < data_tabs.tab[idx] && number > data_tabs.tab[z_idx])
		return (true);
	else if (data_tabs.tab[z_idx] == mm_ab.max_a && mm_ab.max_a < number)
	{
		return (true);
	}
	else if (data_tabs.tab[idx] == mm_ab.min_a && \
	(number < mm_ab.min_a && data_tabs.tab[idx]))
	{
		return (true);
	}
	return (false);
}

void	list_taveler(t_tab_ab data_tabs, t_data_dist *data_dist, t_min_max_ab mm_ab, unsigned int nb_pos)
{
	unsigned int	idx;
	unsigned int	dist;

	idx = data_tabs.top_a;
	dist = 0;
	while (idx != UINT_MAX)
	{
		if (check_where(data_tabs, mm_ab, data_tabs.tab[nb_pos], idx))
			break;
		dist++;
		idx--;
	}
	if (dist < data_dist->dist)
	{
		data_dist->dist = dist;
		data_dist->idx = nb_pos;
		data_dist->num = data_tabs.tab[data_dist->idx];
	}
}

void	distance(t_tab_ab data_tabs, t_data_dist *data_dist, t_min_max_ab mm_ab)
{
	unsigned int	idx;

	idx = data_tabs.top_a + 1;
//	list_taveler(data_tabs, data_dist, mm_ab, idx);
//	new_print_tab(data_tabs, 's');
	while (idx < data_tabs.size)
	{
//		printf("idx = %u\n", idx); // TODO remove
		list_taveler(data_tabs, data_dist, mm_ab, idx);
		idx++;
	}
//	printf("number test = %d | distance = %u\n", data_dist->num, data_dist->dist); //TODO remove
}

// t_bool	numbers_moves(t_tab_ab data_tabs)
// {
// 	unsigned int	idx;
	
// 	idx = list_traveler(data_tabs);
// 	if (idx < data_tabs.size / 2)
// 		return (true);
// 	else
// 		return (false);
// }
