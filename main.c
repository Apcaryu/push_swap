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
	// push(&tabs, 'b');
	// push(&tabs, 'b');
	// push(&tabs, 'b');
	// new_print_tab(tabs, 's');
	// rotate(&tabs, 'a', false);
	// new_print_tab(tabs, 's');
	// rotate(&tabs, 'a', true);
	// new_print_tab(tabs, 's');
	// rotate(&tabs, 'b', false);
	// new_print_tab(tabs, 's');
	// rotate(&tabs, 'b', true);
	// new_print_tab(tabs, 's');
	// rotate(&tabs, 's', false);
	// new_print_tab(tabs, 's');
	// rotate(&tabs, 's', true);
	// new_print_tab(tabs, 's');
//	printf("tab[0] = %d | top_a = %u\n", tabs.tab[0], tabs.top_a);
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
//	printf("tab[0] = %d | top_a = %u\n", tabs.tab[0], tabs.top_a);
//	new_print_tab(tabs, 's');

//	all_in_b(&tabs);
//	init_test(tabs);

//	move_or_not(&tabs);
//	new_print_tab(tabs, 's');
//	new_print_tab(tabs, 's');
//	printf("list is sorted : %u", is_sorted(tabs));
//	if (check_order(tabs) == 0)
//		printf("\033[34mis not tried\n\033[0m");
//	else
//		printf("\033[32mis tried\n\033[0m");
//	swap(&tabs, 'a');
//	new_print_tab(tabs, 's');
//	push(&tabs, 'b');
//	push(&tabs, 'b');
//	push(&tabs, 'b');
//	new_print_tab(tabs, 's');
//	super_rotate(&tabs, 0);
//	new_print_tab(tabs, 's');
//	super_rotate(&tabs, 1);
//	new_print_tab(tabs, 's');
//	swap(&tabs, 'a');
//	new_print_tab(tabs, 's');
//	push(&tabs, 'a');
//	push(&tabs, 'a');
//	push(&tabs, 'a');
//	new_print_tab(tabs, 's');
//	if (check_order(tabs) == 0)
//		printf("\033[34mis not tried\n\033[0m");
//	else
//		printf("\033[32mis tried\n\033[0m");
}