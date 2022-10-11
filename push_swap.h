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

typedef struct	s_tab_ab
{
	long int		*tab;
	unsigned int	size;
	unsigned int	top_a;
}	t_tab_ab;

void	is_full_numbers(char *arg);
int		*init_tab(char *list);

# endif