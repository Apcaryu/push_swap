#include "push_swap.h"

int	main(int argc, char *argv[])
{
//	int	*tab_a;
//	int *tab_b;
//
//	tab_a = init_tab(argv[1]);
//	(void)argc;
//	(void)argv;
//	test(argc, argv, tab_a, tab_b);
//	return (0);

	t_tab_ab tabs;

	new_init_tab(&tabs, argv[1]);
	init_test(tabs);
//	push(&tabs, 'b');
//	push(&tabs, 'b');
//	new_print_tab(tabs, 's');
//	new_swap(&tabs, 'b');
//	new_print_tab(tabs, 's');
//	push(&tabs, 'a');
//	push(&tabs, 'a');
//	new_print_tab(tabs, 's');
//	rotate(&tabs, 'a', 0);
//	new_print_tab(tabs, 's');
//	rotate(&tabs, 'a', 1);
//	new_print_tab(tabs, 's');
//	push(&tabs, 'b');
//	push(&tabs, 'b');
//	push(&tabs, 'b');
//	new_print_tab(tabs, 's');
//	rotate(&tabs, 'b', 0);
//	new_print_tab(tabs, 's');
//	rotate(&tabs, 'b', 1);
//	new_print_tab(tabs, 's');
//	super_swap(&tabs);
//	new_print_tab(tabs, 's');
//	super_rotate(&tabs, 0);
//	new_print_tab(tabs, 's');
//	super_rotate(&tabs, 1);
//	new_print_tab(tabs, 's');

	new_swap(&tabs, 'a');
	new_print_tab(tabs, 's');
	push(&tabs, 'b');
	push(&tabs, 'b');
	push(&tabs, 'b');
	new_print_tab(tabs, 's');

}