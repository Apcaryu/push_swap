/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b_seq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:37:06 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/17 13:37:08 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data_sequence(t_data_sequence *data_seq, t_tab_ab data_tabs)
{
	data_seq->seq_list = malloc(sizeof(int) * data_tabs.size);
	data_seq->tmp_list = malloc(sizeof(int) * data_tabs.size);
	data_seq->seq_size = 0;
	data_seq->idx_better_nb = 0;
	data_seq->start_num = 0;
}

void	copy_tab(t_data_sequence *data_seq)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_seq->seq_size)
	{
		data_seq->seq_list[idx] = data_seq->tmp_list[idx];
		idx++;
	}
}
