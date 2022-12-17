/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_in_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:14:47 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/16 17:14:52 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	in_while_mm_ab(t_tab_ab data_tabs, t_min_max_ab *mm_ab, \
						unsigned int s_idx, unsigned int idx)
{
	if (idx <= data_tabs.top_a)
	{
		if (data_tabs.tab[idx] < mm_ab->min_a && s_idx == 0)
			mm_ab->min_a = data_tabs.tab[idx];
		else if (data_tabs.tab[idx] > mm_ab->max_a && s_idx == 1)
			mm_ab->max_a = data_tabs.tab[idx];
	}
	else if (data_tabs.top_a < idx)
	{
		if (data_tabs.tab[idx] < mm_ab->min_b && s_idx == 0)
			mm_ab->min_b = data_tabs.tab[idx];
		else if (data_tabs.tab[idx] > mm_ab->max_b && s_idx == 1)
			mm_ab->max_b = data_tabs.tab[idx];
	}
}

void	set_min_max(t_tab_ab data_tabs, t_min_max_ab *mm_ab)
{
	unsigned int	idx;
	unsigned int	s_idx;

	s_idx = 0;
	while (s_idx < 2)
	{
		idx = 0;
		while (idx < data_tabs.size)
		{
			in_while_mm_ab(data_tabs, mm_ab, s_idx, idx);
			idx++;
		}
		s_idx++;
	}
}

t_bool	check_push_in_a(t_tab_ab data_tabs, t_min_max_ab *mm_ab)
{
	if (data_tabs.tab[data_tabs.top_a + 1] < data_tabs.tab[data_tabs.top_a] \
	&& data_tabs.tab[data_tabs.top_a + 1] > data_tabs.tab[0])
		return (true);
	else if (data_tabs.tab[0] == mm_ab->max_a && \
			mm_ab->max_a < data_tabs.tab[data_tabs.top_a + 1])
	{
		mm_ab->max_a = data_tabs.tab[data_tabs.top_a + 1];
		return (true);
	}
	else if (data_tabs.tab[data_tabs.top_a] == mm_ab->min_a && \
			(data_tabs.tab[data_tabs.top_a + 1] < mm_ab->min_a && \
			data_tabs.tab[data_tabs.top_a]))
	{
		mm_ab->min_a = data_tabs.tab[data_tabs.top_a + 1];
		return (true);
	}
	return (false);
}

void	all_in_a(t_tab_ab *data_tabs)
{
	t_min_max_ab	mm_ab;
	t_data_dist		data_dist;

	init_min_max_ab(&mm_ab);
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
		init_data_dist(&data_dist);
	}
}
