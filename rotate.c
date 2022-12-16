/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:14:00 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/17 00:15:09 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction_set.h"

static void	set_bottom_top(t_tab_ab tabs, unsigned int *bottom, \
							unsigned int *top, char target)
{
	if (target == 'a')
	{
		*bottom = 0;
		*top = tabs.top_a;
	}
	else if (target == 'b')
	{
		*bottom = tabs.top_a + 1;
		*top = tabs.size - 1;
	}
}

static void	rotate_inter(t_tab_ab *tabs, unsigned int s_idx, unsigned int e_idx)
{
	int				tmp;

	tmp = tabs->tab[e_idx];
	while (s_idx < e_idx)
	{
		tabs->tab[e_idx] = tabs->tab[e_idx - 1];
		e_idx--;
	}
	tabs->tab[s_idx] = tmp;
}

static void	rotate_exter(t_tab_ab *tabs, unsigned int s_idx, unsigned int e_idx)
{
	int	tmp;

	tmp = tabs->tab[s_idx];
	while (s_idx < e_idx)
	{
		tabs->tab[s_idx] = tabs->tab[s_idx + 1];
		s_idx++;
	}
	tabs->tab[e_idx] = tmp;
}

void	rotate_printer(char target, t_bool is_reverse)
{
	if (target == 'a' && !is_reverse)
		write(1, "ra\n", 3);
	else if (target == 'a' && is_reverse)
		write(1, "rra\n", 4);
	else if (target == 'b' && !is_reverse)
		write(1, "rb\n", 3);
	else if (target == 'b' && is_reverse)
		write(1, "rrb\n", 4);
	else if (target == 's' && !is_reverse)
		write(1, "rr\n", 3);
	else if (target == 's' && is_reverse)
		write(1, "rrr\n", 4);
}

void	rotate(t_tab_ab *tabs, char target, t_bool is_reverse)
{
	unsigned int	e_idx;
	unsigned int	s_idx;

	if (target == 'a' || target == 's')
		set_bottom_top(*tabs, &s_idx, &e_idx, 'a');
	if ((target == 'a' || target == 's') && !is_reverse)
		rotate_inter(tabs, s_idx, e_idx);
	if ((target == 'a' || target == 's') && is_reverse)
		rotate_exter(tabs, s_idx, e_idx);
	if (target == 'b' || target == 's')
		set_bottom_top(*tabs, &s_idx, &e_idx, 'b');
	if ((target == 'b' || target == 's') && is_reverse)
		rotate_inter(tabs, s_idx, e_idx);
	if ((target == 'b' || target == 's') && !is_reverse)
		rotate_exter(tabs, s_idx, e_idx);
	rotate_printer(target, is_reverse);
}
