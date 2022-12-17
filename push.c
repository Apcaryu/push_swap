/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:19:53 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/17 13:20:23 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction_set.h"

void	push(t_tab_ab *tabs, char target)
{
	if (target == 'a' && (tabs->top_a < tabs->size - 1 || \
							tabs->top_a == UINT_MAX))
	{
		tabs->top_a += 1;
		write(1, "pa\n", 3);
	}
	else if (target == 'b' && 0xFFFFFFFF != tabs->top_a)
	{
		tabs->top_a -= 1;
		write(1, "pb\n", 3);
	}
}
