/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:45:34 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/17 13:45:34 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(t_tab_ab *tabs)
{
	unsigned int	idx;

	tabs->max = tabs->tab[0];
	idx = 1;
	while (idx <= tabs->top_a)
	{
		if (tabs->max < tabs->tab[idx])
			tabs->max = tabs->tab[idx];
		idx++;
	}
}

void	get_min(t_tab_ab *tabs)
{
	unsigned int	idx;

	tabs->min = tabs->tab[0];
	idx = 1;
	while (idx <= tabs->top_a)
	{
		if (tabs->min > tabs->tab[idx])
			tabs->min = tabs->tab[idx];
		idx++;
	}
}

void	freezer(char **tab)
{
	size_t	idx;

	idx = 0;
	while (tab[idx] != NULL)
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}
