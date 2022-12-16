/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:21:14 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/17 00:21:52 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_max_pos(t_tab_ab data_tabs, t_min_max_ab mm_ab)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_tabs.top_a)
	{
		if (data_tabs.tab[idx] == mm_ab.max_a)
			return (idx);
		idx++;
	}
	return (idx);
}

void	special_three(t_tab_ab *data_tabs)
{
	t_min_max_ab	mm_ab;

	init_min_max_ab(&mm_ab);
	while (!is_sorted(*data_tabs))
	{
		set_min_max(*data_tabs, &mm_ab);
		if (get_max_pos(*data_tabs, mm_ab) == 2)
			rotate(data_tabs, 'a', false);
		else if (get_max_pos(*data_tabs, mm_ab) == 1)
			rotate(data_tabs, 'a', true);
		else if (get_max_pos(*data_tabs, mm_ab) == 0)
			swap(data_tabs, 'a');
	}
}
