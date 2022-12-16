#include "push_swap.h"

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

t_bool	is_top_b(t_tab_ab data_tabs, unsigned int idx)
{
	unsigned int	size_b;
	unsigned int	pos_b;
	unsigned int	up_nb;

	size_b = data_tabs.size - 1 - data_tabs.top_a;
	pos_b = idx - data_tabs.top_a;
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
		while (idx < data_tab.top_a)
		{
			dist_a++;
			idx++;
		}
	}
	else
	{
		while (idx != UINT_MAX)
		{
			dist_a++;
			idx--;
		}
	}
	return (dist_a);
}

unsigned int	set_dist_b(t_tab_ab data_tab, t_bool reverse_b, unsigned int idx)
{
	unsigned int	dist_b;

	dist_b = 0;
	while (idx > data_tab.top_a && idx <= data_tab.size)
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
		if (data_tabs.top_a + 1 <= z_idx)
			z_idx = 0;
		if (number < data_tabs.tab[idx] && number > data_tabs.tab[z_idx])
			break;
		else if (data_tabs.tab[z_idx] == mm_ab.max_a && mm_ab.max_a < number)
			break;
		else if (data_tabs.tab[idx] == mm_ab.min_a && \
        (number < mm_ab.min_a && data_tabs.tab[idx]))
			break;
		else if (idx == 0)
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

	reverse_b = !is_top_b(data_tabs, nb_pos);
	idx = check_where(data_tabs, mm_ab, data_tabs.tab[nb_pos]);
	reverse_a = is_top_a(data_tabs, idx);
	dist_b = set_dist_b(data_tabs, reverse_b, nb_pos);
	dist_a = set_dist_a(data_tabs, reverse_a, idx);
	dist = dist_a + dist_b;
	if (dist_a <= dist_b && reverse_a == reverse_b)
		dist -=  dist_a;
	else if (dist_b <= dist_a && reverse_a == reverse_b)
		dist -= dist_b;
	if (dist < data_dist->dist)
	{
		data_dist->dist = dist;
		data_dist->dist_a = dist_a;
		data_dist->dist_b = dist_b;
		if (dist_a < dist_b && data_tabs.top_a + 1 != nb_pos)
			data_dist->nb_rr_rrr = dist_a;
		else if (dist_b < dist_a && data_tabs.top_a + 1 != nb_pos)
			data_dist->nb_rr_rrr = dist_b - 1;
		else
			data_dist->nb_rr_rrr = 0;
		data_dist->idx = nb_pos;
		data_dist->num = data_tabs.tab[data_dist->idx];
		data_dist->reverse_b = reverse_b;
		data_dist->reverse_a = reverse_a;
	}
}

void	distance(t_tab_ab data_tabs, t_data_dist *data_dist, t_min_max_ab mm_ab)
{
	unsigned int	idx;

	idx = data_tabs.top_a + 1;
	while (idx < data_tabs.size)
	{
		list_taveler(data_tabs, data_dist, mm_ab, idx);
		idx++;
	}
}
