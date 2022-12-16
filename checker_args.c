#include "push_swap.h"

int	is_full_numbers(char *arg)
{
	unsigned int	idx;

	idx = 0;
	while (arg[idx])
	{
		if ((arg[idx] < '0' || '9' < arg[idx]) && arg[idx] != ' ' && arg[idx] != '-') //TODO add negative
			return (1);
		if (arg[idx] == '-' && (arg[idx + 1] < '0' || '9' < arg[idx + 1]))
			return (1);
		idx++;
	}
	return (0);
}

int	is_full_space(char *arg)
{
	unsigned int	idx;

	idx = 0;
	while (arg[idx])
	{
		if (arg[idx] != ' ')
			return (0);
		idx++;
	}
	return (1);
}

int is_double(t_tab_ab data_tab)
{
	unsigned int	idx;
	unsigned int	sub_idx;
	unsigned int	tmp;

	idx = 0;
	while (idx < data_tab.size)
	{
		sub_idx = idx + 1;
		tmp = data_tab.tab[idx];
		while (sub_idx < data_tab.size)
		{
			if (tmp == data_tab.tab[sub_idx] && sub_idx != idx)
				return (1);
			sub_idx++;
		}
		idx++;
	}
	return (0);
}

t_bool	is_not_int(char *c_nb, int i_nb)
{
	char *result;

	result = ft_itoa(i_nb);
	if (result == NULL)
	{
		free(result);
		return (true);
	}
	else if (!ft_strncmp(c_nb, result, ft_strlen(c_nb)))
	{
		free(result);
		return (false);
	}
	free(result);
	return (true);
}
