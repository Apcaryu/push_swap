#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define VERSION "0.3.0"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "instruction_set.h"

// -----lib for test-----
# include <stdio.h>
# include "test.h"
// ----------------------

typedef struct	s_data_sequence
{
	int 			*seq_list;
	int 			*tmp_list;
	int				start_num;
	int				min;
	int				tmp;
	unsigned int	seq_size;
	unsigned int	idx_better_nb;
}	t_data_sequence;

typedef struct s_min_max_ab
{
	int	min_a;
	int max_a;
	int min_b;
	int max_b;
}	t_min_max_ab;

int		is_full_numbers(char *arg);
int		is_full_space(char *arg);
int 	is_double(t_tab_ab data_tab);
int		*init_tab(char *list);
void    init_data_dist(t_data_dist *data_dist);

void	new_init_tab(t_tab_ab *tabs, char *argv);

char	check_order(t_tab_ab tabs);
void	move_or_not(t_tab_ab *tabs);

void	better_sequence(t_tab_ab *data_tabs);
void	all_in_b(t_tab_ab *data_tabs);
t_bool	numbers_moves(t_tab_ab data_tabs);
void	distance(t_tab_ab data_tabs, t_data_dist *data_dist, t_min_max_ab mm_ab);
void	all_in_a(t_tab_ab *data_tabs);
void	final_rotate(t_tab_ab *data_tabs);

# endif