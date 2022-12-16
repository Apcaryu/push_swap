#include "push_swap.h"

t_bool	is_sorted(t_tab_ab data_tabs)
{
	unsigned int	idx;
	int				tmp;

	idx = data_tabs.top_a - 1;
	tmp = data_tabs.tab[data_tabs.top_a];
	while (idx != UINT_MAX)
	{
		if (data_tabs.tab[idx] < tmp)
		{
			return (false);
		}
		tmp = data_tabs.tab[idx];
		idx--;
	}
	return (true);
}

int	main(int argc, char *argv[])
{

	t_tab_ab tabs;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	if (is_full_numbers(argv[1]))
		return (printf("not only number list\n"));
	if (is_full_space(argv[1]))
		return (printf("empty list\n"));
	new_init_tab(&tabs, argv[1]);
	if (tabs.tab == NULL)
		return (0);
	if (is_double(tabs))
	{
		free(tabs.tab);
		return (printf("double presence detected\n"));
	}
	if (tabs.size == 3)
		special_three(&tabs);
	else if (tabs.size == 5)
		special_five(&tabs);
	else
	{
		better_sequence(&tabs);
		all_in_a(&tabs);
		final_rotate(&tabs);
	}
	free(tabs.tab);
}
