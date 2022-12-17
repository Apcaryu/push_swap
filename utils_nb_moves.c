/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nb_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:10:50 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/17 14:10:51 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	set_dist_a(t_tab_ab data_tab, t_bool reverse_a, \
							unsigned int idx)
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

unsigned int	set_dist_b(t_tab_ab data_tab, t_bool reverse_b, \
							unsigned int idx)
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
