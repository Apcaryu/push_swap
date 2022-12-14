/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:47:55 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/16 17:47:57 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_min_max_ab(t_min_max_ab *mm_ab)
{
	mm_ab->min_a = INT_MAX;
	mm_ab->max_a = INT_MIN;
	mm_ab->min_b = INT_MAX;
	mm_ab->max_b = INT_MIN;
}

void	init_data_dist(t_data_dist *data_dist)
{
	data_dist->dist = UINT_MAX;
	data_dist->nb_rr_rrr = 0;
	data_dist->num = 0;
	data_dist->idx = UINT_MAX;
}

static unsigned int	the_words(char const *s, char c)
{
	size_t	size;
	size_t	idx;
	size_t	nb_words;
	char	is_word;
	char	tmp;

	size = ft_strlen(s);
	idx = 0;
	nb_words = 0;
	is_word = 0;
	tmp = 0;
	while (idx <= size)
	{
		if (s[idx] == c && tmp != 0)
			is_word = 0;
		if (s[idx] != c && tmp != 1)
			is_word = 1;
		if (is_word == 0 && tmp == 1)
			nb_words++;
		if (s[idx] == '\0' && tmp == 1 && s[idx] != c)
			nb_words++;
		idx++;
		tmp = is_word;
	}
	return (nb_words);
}

static int	*char_to_int(char **list, unsigned int size_list)
{
	int				*list_out;
	unsigned int	idx;
	unsigned int	r_idx;

	list_out = ft_calloc(size_list, (sizeof (int)));
	if (!list_out)
		return (NULL);
	idx = 0;
	r_idx = size_list - 1;
	while (0xFFFFFFFF != r_idx)
	{
		list_out[r_idx] = ft_atoi(list[idx]);
		if (is_not_int(list[idx], list_out[r_idx]))
		{
			free(list_out);
			return (NULL);
		}
		r_idx--;
		idx++;
	}
	return (list_out);
}

void	new_init_tab(t_tab_ab *tabs, char *argv)
{
	char			**char_list;
	unsigned int	size_list;

	size_list = the_words(argv, ' ');
	char_list = ft_split(argv, ' ');
	tabs->tab = char_to_int(char_list, size_list);
	if (tabs->tab == NULL)
	{
		freezer(char_list);
		error_exit(tabs);
	}
	tabs->size = size_list;
	tabs->top_a = size_list - 1;
	get_min(tabs);
	get_max(tabs);
	freezer(char_list);
}
