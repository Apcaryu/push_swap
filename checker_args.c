#include "push_swap.h"

int	is_full_numbers(char *arg)
{
	unsigned int	idx;

	idx = 0;
	while (arg[idx])
	{
		if ((arg[idx] < '0' || '9' < arg[idx]) && arg[idx] != ' ')
			return (1);
		idx++;
	}
	return (0);
}
