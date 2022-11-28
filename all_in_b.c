#include "push_swap.h"
/*-----------------------------------------------------------------------------
 * verifier que le nombre en top_a est compris emtre top_b et bottom_b
 * si c'est le cas push top_a dans top_b
 * sinon rotate b
 ----------------------------------------------------------------------------*/
void	all_in_b(t_tab_ab *data_tabs)
{
	while (data_tabs->top_a != UINT_MAX) {
		printf("top_a = %u\n", data_tabs->top_a);
		if (data_tabs->tab[data_tabs->top_a] < data_tabs->tab[data_tabs->size - 1] \
 		&& data_tabs->tab[data_tabs->top_a] > data_tabs->tab[data_tabs->top_a + 1])
			push(data_tabs, 'b');
		else
			rotate(data_tabs, 'b', 0);
	}
}
