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

t_bool	is_top_b(t_tab_ab data_tabs, t_data_dist data_dist, unsigned int idx)
{
	unsigned int	size_b;
	unsigned int	pos_b;
	unsigned int	up_nb;

	size_b = data_tabs.size - 1 - data_tabs.top_a;
	// printf("size_b = %u | tab_size = %u | top_a = %u\n", size_b,  data_tabs.size, data_tabs.top_a); // TODO remove
	pos_b = idx - data_tabs.top_a;
	// printf("size_b = %u | pos_b = %u | idx = %u | top_a = %u\n", size_b, pos_b, idx, data_tabs.top_a); // TODO remove
	printf("size_b / 2 = %u | pos_b = %u\n", size_b / 2, pos_b); // TODO remove
	if (size_b % 2 == 1)
		up_nb = 1;
	else
		up_nb = 0;
	if (pos_b <= size_b / 2 + up_nb)
		return (true);
	else
		return (false);
}

unsigned int	set_dist_b(t_tab_ab data_tab, t_data_dist data_dist, unsigned int idx)
{
	unsigned int	dist_b;

	dist_b = 0;
	while (idx > data_tab.top_a && idx < data_tab.size)
	{
		if (data_dist.reverse_b == false)
		{
			dist_b++;
			idx--;
		}
		else
		{
			dist_b++;
			idx++;
		}
	}
	return (dist_b);
}

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
	unsigned int	dist_a;
	unsigned int	dist_b;

	data_dist->reverse_b = !is_top_b(data_tabs, *data_dist, nb_pos);
	idx = data_tabs.top_a;
	dist = 0;
	dist_b = set_dist_b(data_tabs, *data_dist, nb_pos);
	while (idx != UINT_MAX)
	{
		if (check_where(data_tabs, mm_ab, data_tabs.tab[nb_pos], idx))
			break;
		dist++;
		idx--;
	}
	dist_a = dist - dist_b;
	if (dist < data_dist->dist)
	{
		data_dist->dist = dist;
		data_dist->idx = nb_pos;
		data_dist->num = data_tabs.tab[data_dist->idx];
	}
	new_print_tab(data_tabs, 's');
	printf("dist_b = %u | reverse_b = %d | nb = %d\n", dist_b, data_dist->reverse_b, data_tabs.tab[nb_pos]); // TODO remove
	sleep(2);
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
