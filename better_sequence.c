/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:21:26 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/16 17:21:32 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_in_sequence(int number, t_data_sequence data_seq)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_seq.seq_size)
	{
		if (number == data_seq.seq_list[idx])
			return (true);
		idx++;
	}
	return (false);
}

unsigned int	size_pp(t_tab_ab data_tabs, t_data_sequence *data_seq,
						unsigned int start, unsigned int idx)
{
	unsigned int	size;

	size = 1;
	while (idx != start)
	{
		if (data_tabs.size < idx)
			idx = data_tabs.top_a;
		if (idx == start)
			break ;
		if (data_seq->min < data_tabs.tab[idx] && \
			data_tabs.tab[idx] < data_seq->tmp_list[size - 1])
		{
			data_seq->min = data_tabs.tab[idx];
			data_seq->tmp_list[size - 1] = data_tabs.tab[idx];
		}
		else if (data_seq->tmp_list[size - 1] < data_tabs.tab[idx])
		{
			data_seq->tmp_list[size] = data_tabs.tab[idx];
			size++;
			if (2 <= size)
				data_seq->min = data_seq->tmp_list[size - 2];
		}
		idx--;
	}
	return (size);
}

void	sequence_size(t_tab_ab data_tabs, t_data_sequence *data_seq, \
						unsigned int start)
{
	unsigned int	idx;
	unsigned int	size;

	idx = start;
	if (data_tabs.size < idx)
		idx = data_tabs.top_a;
	data_seq->min = data_tabs.tab[idx];
	data_seq->tmp_list[0] = data_tabs.tab[idx];
	idx--;
	size = size_pp(data_tabs, data_seq, start, idx);
	if (data_seq->seq_size < size)
	{
		data_seq->seq_size = size;
		copy_tab(data_seq);
		data_seq->idx_better_nb = start;
		data_seq->start_num = data_tabs.tab[start];
	}
}

void	sequence_pusher(t_tab_ab *data_tabs, t_data_sequence data_sequence)
{
	unsigned int	nb_push;
	unsigned int	max_push;

	nb_push = 0;
	max_push = data_tabs->size - data_sequence.seq_size;
	while (nb_push < max_push)
	{
		if (is_in_sequence(data_tabs->tab[data_tabs->top_a], \
		data_sequence) == false)
		{
			push(data_tabs, 'b');
			nb_push++;
		}
		else
			rotate(data_tabs, 'a', 0);
	}
}

void	better_sequence(t_tab_ab *data_tabs)
{
	t_data_sequence	data_seq;
	unsigned int	start;

	init_data_sequence(&data_seq, *data_tabs);
	start = data_tabs->top_a;
	while (start < data_tabs->size)
	{
		sequence_size(*data_tabs, &data_seq, start);
		start--;
	}
	sequence_pusher(data_tabs, data_seq);
	if (data_seq.seq_list)
		free(data_seq.seq_list);
	if (data_seq.tmp_list)
		free(data_seq.tmp_list);
}
