#include "push_swap.h"

int	main(int argc, char *argv[])
{

	t_tab_ab tabs;

	if (is_full_numbers(argv[1]))
		return (printf("not only number list\n"));
	if (is_full_space(argv[1]))
		return (printf("empty list\n"));
	new_init_tab(&tabs, argv[1]);
	if (is_double(tabs))
	{
		free(tabs.tab);
		return (printf("double presence detected\n"));
	}
	printf("tab[0] = %d | top_a = %u\n", tabs.tab[0], tabs.top_a);
	better_sequence(&tabs);
	printf("tab[0] = %d | top_a = %u\n", tabs.tab[0], tabs.top_a);
	new_print_tab(tabs, 's');

	all_in_b(&tabs);
//	init_test(tabs);

//	move_or_not(&tabs);
	new_print_tab(tabs, 's');
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