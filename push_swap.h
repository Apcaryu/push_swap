#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define VERSION "0.3.0"
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "instruction_set.h"

// -----lib for test-----
# include <stdio.h>
# include "test.h"
// ----------------------

typedef struct	s_data_sequence
{
	int				*tab_seq;
	unsigned int	seq_size;
	unsigned int	idx_better_nb;
}	t_data_sequence;

int		is_full_numbers(char *arg);
int		is_full_space(char *arg);
int 	is_double(t_tab_ab data_tab);
int		*init_tab(char *list);

void	new_init_tab(t_tab_ab *tabs, char *argv);

char	check_order(t_tab_ab tabs);
void	move_or_not(t_tab_ab *tabs);

void	better_sequence(t_tab_ab *data_tabs);

# endif