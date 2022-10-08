#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*tab_a;
	int *tab_b;

	init_tab(argv[1]);
	(void)argc;
	(void)argv;
	test(argc, argv, tab_a, tab_b);
	return (0);
}