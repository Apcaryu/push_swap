/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:59:02 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/16 17:59:03 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_where(t_tab_ab data_tabs, t_min_max_ab mm_ab, int number)
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
			break ;
		else if (data_tabs.tab[z_idx] == mm_ab.max_a && mm_ab.max_a < number)
			break ;
		else if (data_tabs.tab[idx] == mm_ab.min_a && \
		(number < mm_ab.min_a && data_tabs.tab[idx]))
			break ;
		else if (idx == 0)
			break ;
		idx--;
	}
	return (idx);
}

void	tmp_to_result(t_tab_ab data_tabs, t_data_dist *data_dist, \
						t_data_dist tmp_dist, unsigned int nb_pos)
{
	data_dist->dist = tmp_dist.dist;
	data_dist->dist_a = tmp_dist.dist_a;
	data_dist->dist_b = tmp_dist.dist_b;
	if (tmp_dist.dist_a < tmp_dist.dist_b && data_tabs.top_a + 1 != nb_pos)
		data_dist->nb_rr_rrr = tmp_dist.dist_a;
	else if (tmp_dist.dist_b < tmp_dist.dist_a && data_tabs.top_a + 1 != nb_pos)
		data_dist->nb_rr_rrr = tmp_dist.dist_b - 1;
	else
		data_dist->nb_rr_rrr = 0;
	data_dist->idx = nb_pos;
	data_dist->num = data_tabs.tab[data_dist->idx];
	data_dist->reverse_b = tmp_dist.reverse_b;
	data_dist->reverse_a = tmp_dist.reverse_a;
}

void	list_taveler(t_tab_ab data_tabs, t_data_dist *data_dist, \
						t_min_max_ab mm_ab, unsigned int nb_pos)
{
	t_data_dist	tmp_dist;

	tmp_dist.reverse_b = !is_top_b(data_tabs, nb_pos);
	tmp_dist.idx = check_where(data_tabs, mm_ab, data_tabs.tab[nb_pos]);
	tmp_dist.reverse_a = is_top_a(data_tabs, tmp_dist.idx);
	tmp_dist.dist_b = set_dist_b(data_tabs, \
				tmp_dist.reverse_b, nb_pos);
	tmp_dist.dist_a = set_dist_a(data_tabs, \
				tmp_dist.reverse_a, tmp_dist.idx);
	tmp_dist.dist = tmp_dist.dist_a + tmp_dist.dist_b;
	if (tmp_dist.dist_a <= tmp_dist.dist_b && \
			tmp_dist.reverse_a == tmp_dist.reverse_b)
		tmp_dist.dist -= tmp_dist.dist_a;
	else if (tmp_dist.dist_b <= tmp_dist.dist_a && \
				tmp_dist.reverse_a == tmp_dist.reverse_b)
		tmp_dist.dist -= tmp_dist.dist_b;
	if (tmp_dist.dist < data_dist->dist)
		tmp_to_result(data_tabs, data_dist, tmp_dist, nb_pos);
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
