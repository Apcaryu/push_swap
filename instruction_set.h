/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellegr <apellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:51:43 by apellegr          #+#    #+#             */
/*   Updated: 2022/12/16 17:51:44 by apellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_SET_H
# define INSTRUCTION_SET_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_tab_ab
{
	int				*tab;
	unsigned int	size;
	unsigned int	top_a;
	int				min;
	int				max;
}	t_tab_ab;

typedef struct s_data_dist
{
	unsigned int	dist;
	unsigned int	dist_a;
	unsigned int	dist_b;
	unsigned int	nb_rr_rrr;
	unsigned int	idx;
	int				num;
	t_bool			reverse_a;
	t_bool			reverse_b;
}	t_data_dist;

void	swap(t_tab_ab *tabs, char target);
void	push(t_tab_ab *tabs, char target);
void	rotate(t_tab_ab *tabs, char target, t_bool is_reverse);

#endif