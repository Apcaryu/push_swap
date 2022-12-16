/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:16:38 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/17 00:17:33 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_five(t_tab_ab *data_tabs)
{
	t_min_max_ab	mm_ab;

	init_min_max_ab(&mm_ab);
	if (is_sorted(*data_tabs))
		return ;
	push(data_tabs, 'b');
	push(data_tabs, 'b');
	special_three(data_tabs);
	while (data_tabs->top_a < data_tabs->size - 1)
	{
		set_min_max(*data_tabs, &mm_ab);
		while (check_push_in_a(*data_tabs, &mm_ab) == false)
			rotate(data_tabs, 'a', 0);
		push(data_tabs, 'a');
	}
	final_rotate(data_tabs);
}
