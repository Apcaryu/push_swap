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

t_bool	is_top_a(t_tab_ab data_tabs, unsigned int idx)
{
	unsigned int	size_a;
	unsigned int	pos_a;
	unsigned int	up_nb;

	size_a = data_tabs.top_a;
	pos_a = size_a - idx;
	if (size_a % 2 == 1)
		up_nb = 1;
	else
		up_nb = 0;
	if (size_a / 2 + up_nb <= pos_a)
		return (true);
	else
		return (false);
}

t_bool	is_top_b(t_tab_ab data_tabs, t_data_dist data_dist, unsigned int idx)
{
	unsigned int	size_b;
	unsigned int	pos_b;
	unsigned int	up_nb;

	size_b = data_tabs.size - 1 - data_tabs.top_a;
	// printf("size_b = %u | tab_size = %u | top_a = %u\n", size_b,  data_tabs.size, data_tabs.top_a); // TODO remove
	pos_b = idx - data_tabs.top_a;
	// printf("size_b = %u | pos_b = %u | idx = %u | top_a = %u\n", size_b, pos_b, idx, data_tabs.top_a); // TODO remove
//	printf("size_b / 2 = %u | pos_b = %u\n", size_b / 2, pos_b); // TODO remove
	if (size_b % 2 == 1)
		up_nb = 1;
	else
		up_nb = 0;
	if (pos_b <= size_b / 2 + up_nb)
		return (true);
	else
		return (false);
}

unsigned int	set_dist_a(t_tab_ab data_tab, t_bool reverse_a, unsigned int idx)
{
	unsigned int	dist_a;

	dist_a = 0;
	if (reverse_a == false)
	{
		printf("idx = %u | top = %u\n", idx, data_tab.top_a); //TODO remove
		while (idx < data_tab.top_a)
		{
			dist_a++;
			idx++;
		}
	}
	else
	{
		printf("idx = %u\n", idx); // TODO remove
		while (idx != UINT_MAX)
		{
			dist_a++;
			idx--;
		}
	}
	// while (idx < data_tab.top_a && idx != UINT_MAX)
	// {
	// 	if (reverse_a == false)
	// 	{
	// 		dist_a++;
	// 		idx++;
	// 	}
	// 	else
	// 	{
	// 		dist_a++;
	// 		idx--;
	// 	}
	// }
	return (dist_a);
}

unsigned int	set_dist_b(t_tab_ab data_tab, t_bool reverse_b, unsigned int idx)
{
	unsigned int	dist_b;

	dist_b = 0;
	while (idx > data_tab.top_a && idx < data_tab.size)
	{
		if (reverse_b == false)
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

t_bool check_where(t_tab_ab data_tabs, t_min_max_ab mm_ab, int number/*, unsigned int idx*/)
{
	unsigned int	idx;
	unsigned int	z_idx;

	idx = data_tabs.top_a;
	while (idx != UINT_MAX)
	{
		z_idx = idx + 1;
		if (data_tabs.top_a + 1 < z_idx)
			z_idx = 0;
		//	printf("z_idx = %u\n", z_idx); // TODO remove
		if (number < data_tabs.tab[idx] && number > data_tabs.tab[z_idx])
			break;
		else if (data_tabs.tab[z_idx] == mm_ab.max_a && mm_ab.max_a < number)
			break;
		else if (data_tabs.tab[idx] == mm_ab.min_a && \
        (number < mm_ab.min_a && data_tabs.tab[idx]))
			break;
		idx--;
	}
	return (idx);
}

void	list_taveler(t_tab_ab data_tabs, t_data_dist *data_dist, t_min_max_ab mm_ab, unsigned int nb_pos)
{
	unsigned int	idx;
	unsigned int	dist;
	unsigned int	dist_a;
	unsigned int	dist_b;
	t_bool			reverse_b;
	t_bool			reverse_a;

	reverse_b = !is_top_b(data_tabs, *data_dist, nb_pos);
	idx = check_where(data_tabs, mm_ab, data_tabs.tab[nb_pos]);
	// printf("idx = %u\n", idx);
	reverse_a = is_top_a(data_tabs, idx);
	dist = 0;
	dist_b = set_dist_b(data_tabs, reverse_b, nb_pos);
	// printf("dist_b = %u\n", dist_b); // TODO remove
	dist_a = set_dist_a(data_tabs, reverse_a, idx);
	// printf("dist_a = %u\n", dist_a); // TODO remove
	/*
	while (idx != UINT_MAX)
	{
		if (check_where(data_tabs, mm_ab, data_tabs.tab[nb_pos], idx))
			break;
		dist++;
		idx--;
	}
	*/
//	dist_a = dist - dist_b;

	dist = dist_a + dist_b;
	if (dist_a < dist_b && reverse_a == reverse_b)
		dist -=  dist_a;
	else if (dist_b < dist_a && reverse_a == reverse_b)
		dist -= dist_b;
	printf("dist_a = %u | dist_b = %u | dist = %u | rev_a = %u | rev_b = %u\n", dist_a, dist_b, dist, reverse_a, reverse_b); // TODO remove
	if (dist < data_dist->dist)
	{
		data_dist->dist = dist;
		data_dist->dist_a = dist_a;
		data_dist->dist_b = dist_b;
		if (dist_a < dist_b && data_tabs.top_a + 1 != nb_pos)
			data_dist->nb_rr_rrr = dist_a;
		else if (dist_b < dist_a && data_tabs.top_a + 1 != nb_pos)
			data_dist->nb_rr_rrr = dist_b;
		else
			data_dist->nb_rr_rrr = 0;
		data_dist->idx = nb_pos;
		data_dist->num = data_tabs.tab[data_dist->idx];
		data_dist->reverse_b = reverse_b;
		data_dist->reverse_a = reverse_a;
	}
	// new_print_tab(data_tabs, 's'); // TODO remove
//	printf("dist_b = %u | reverse_b = %d | nb = %d\n", dist_b, /*data_dist->*/reverse_b, data_tabs.tab[nb_pos]); // TODO remove
//	sleep(2); // TODO remove
}

void	distance(t_tab_ab data_tabs, t_data_dist *data_dist, t_min_max_ab mm_ab)
{
	unsigned int	idx;

	idx = data_tabs.top_a + 1;
//	list_taveler(data_tabs, data_dist, mm_ab, idx);
	new_print_tab(data_tabs, 's');
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
