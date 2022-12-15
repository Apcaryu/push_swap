#include "push_swap.h"

void	special_five(t_tab_ab *data_tabs)
{
	t_min_max_ab mm_ab;

	init_min_max_ab(&mm_ab);
	if (is_sorted(*data_tabs))
		return;
	push(data_tabs, 'b');
	push(data_tabs, 'b');
//	new_print_tab(*data_tabs, 's'); // TODO remove
	special_three(data_tabs);
//	new_print_tab(*data_tabs, 's'); // TODO remove
//	set_min_max(*data_tabs, &mm_ab);
	while (data_tabs->top_a < data_tabs->size - 1)
	{
		set_min_max(*data_tabs, &mm_ab);
		while (check_push_in_a(*data_tabs, &mm_ab) == false)
		{
			rotate(data_tabs, 'a', 0);
		}
		push(data_tabs, 'a');
	}
	final_rotate(data_tabs);
}