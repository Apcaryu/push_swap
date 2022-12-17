/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:06:06 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/17 01:09:07 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "instruction_set.h"

typedef struct s_data_sequence
{
	int				*seq_list;
	int				*tmp_list;
	int				start_num;
	int				min;
	int				tmp;
	unsigned int	seq_size;
	unsigned int	idx_better_nb;
}	t_data_sequence;

typedef struct s_min_max_ab
{
	int	min_a;
	int	max_a;
	int	min_b;
	int	max_b;
}	t_min_max_ab;

int		is_full_numbers(char *arg);
int		is_full_space(char *arg);
int		is_double(t_tab_ab data_tab);
void	init_data_dist(t_data_dist *data_dist);
void	init_min_max_ab(t_min_max_ab *mm_ab);
void	set_min_max(t_tab_ab data_tabs, t_min_max_ab *mm_ab);
void	new_init_tab(t_tab_ab *tabs, char *argv);
void	better_sequence(t_tab_ab *data_tabs);
void	distance(t_tab_ab data_tabs, t_data_dist *data_dist, \
					t_min_max_ab mm_ab);
void	all_in_a(t_tab_ab *data_tabs);
void	final_rotate(t_tab_ab *data_tabs);
void	special_three(t_tab_ab *data_tabs);
void	special_five(t_tab_ab *data_tabs);
t_bool	is_sorted(t_tab_ab data_tabs);
t_bool	is_not_int(char *c_nb, int i_nb);
t_bool	check_push_in_a(t_tab_ab data_tabs, t_min_max_ab *mm_ab);
void	init_data_sequence(t_data_sequence *data_seq, t_tab_ab data_tabs);
void	copy_tab(t_data_sequence *data_seq);
void	get_max(t_tab_ab *tabs);
void	get_min(t_tab_ab *tabs);
void	freezer(char **tab);

#endif
