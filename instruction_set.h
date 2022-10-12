#ifndef INSTRUCTION_SET_H
# define INSTRUCTION_SET_H
# define SEPARATOR 2147483648
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"

typedef struct	s_tab_ab
{
	long int		*tab;
	unsigned int	size;
	unsigned int	top_a;
}	t_tab_ab;

void	swap(int *tab, char heap);
void	new_swap(t_tab_ab *tabs, char target);

#endif