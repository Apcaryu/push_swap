#include "push_swap.h"

int	main(int argc, char *argv[])
{

	t_tab_ab tabs;

	new_init_tab(&tabs, argv[1]);
	init_test(tabs);

	move_or_not(&tabs);
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