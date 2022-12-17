/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:56:21 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/16 17:56:22 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_tab_ab data_tabs)
{
	unsigned int	idx;
	int				tmp;

	idx = data_tabs.top_a - 1;
	tmp = data_tabs.tab[data_tabs.top_a];
	while (idx != UINT_MAX)
	{
		if (data_tabs.tab[idx] < tmp)
		{
			return (false);
		}
		tmp = data_tabs.tab[idx];
		idx--;
	}
	return (true);
}

void	exec(t_tab_ab *data_tabs)
{
	if (data_tabs->size == 3)
		special_three(data_tabs);
	else if (data_tabs->size == 5)
		special_five(data_tabs);
	else
	{
		better_sequence(data_tabs);
		all_in_a(data_tabs);
		final_rotate(data_tabs);
	}
}

void	error_exit(t_tab_ab *data_tabs)
{
	if (data_tabs->tab != NULL)
		free(data_tabs->tab);
	ft_printf("Error\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_tab_ab	tabs;

	tabs.tab = NULL;
	if (argc <= 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		if (is_full_numbers(argv[1]))
			error_exit(&tabs);
		if (is_full_space(argv[1]))
			exit(EXIT_SUCCESS);
		new_init_tab(&tabs, argv[1]);
		if (tabs.tab == NULL)
			return (0);
		if (is_double(tabs)) {
			free(tabs.tab);
			error_exit(&tabs);
		}
		exec(&tabs);
		free(tabs.tab);
	}
}
