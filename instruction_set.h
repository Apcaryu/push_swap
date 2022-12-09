#ifndef INSTRUCTION_SET_H
# define INSTRUCTION_SET_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "utils.h"

typedef struct	s_tab_ab
{
	int				*tab;
	unsigned int	size;
	unsigned int	top_a;
	int				min;
	int 			max;
}	t_tab_ab;

typedef struct	s_data_dist
{
	unsigned int	dist;
	unsigned int	idx;
	int				num;
    t_bool          reverse_a;
    t_bool          reverse_b;
}	t_data_dist;


void	swap(t_tab_ab *tabs, char target);
void	super_swap(t_tab_ab *tabs);
void	push(t_tab_ab *tabs, char target);
void	rotate(t_tab_ab *tabs, char target, char is_reverse);
void	super_rotate(t_tab_ab *tabs, char is_reverse);

#endif