#include "push_swap.h"

t_bool is_in_top(t_tab_ab data_tabs)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_tabs.size)
	{
		if (data_tabs.tab[idx] == data_tabs.min) {
			if (idx < data_tabs.size / 2)
				return (true);
			else
				return (false);
		}
		idx++;
	}
	return (false);
}

void	final_rotate(t_tab_ab *data_tabs)
{

}
