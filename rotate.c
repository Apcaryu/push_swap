#include "instruction_set.h"

static void	set_bottom_top(t_tab_ab tabs, unsigned int *bottom, unsigned int *top, char target)
{
	if (target == 'a')
	{
		*bottom = 0;
		*top = tabs.top_a;
	}
	else if (target == 'b')
	{
		*bottom = tabs.top_a + 1;
		*top = tabs.size - 1;
	}
}

static void	rotate_inter(t_tab_ab *tabs, unsigned int s_idx, unsigned int e_idx)
{
	int				tmp;

	tmp = tabs->tab[e_idx];
	while (s_idx < e_idx)
	{
		tabs->tab[e_idx] = tabs->tab[e_idx - 1];
		e_idx--;
	}
	tabs->tab[s_idx] = tmp;
}

static void	rotate_exter(t_tab_ab *tabs, unsigned int s_idx, unsigned int e_idx)
{
	int	tmp;

	tmp = tabs->tab[s_idx];
	while (s_idx < e_idx)
	{
		tabs->tab[s_idx] = tabs->tab[s_idx + 1];
		s_idx++;
	}
	tabs->tab[e_idx] = tmp;
}

void	rotate(t_tab_ab *tabs, char target, char is_reverse)
{
	int	tmp;
	unsigned int	e_idx;
	unsigned int	s_idx;

	set_bottom_top(*tabs, &s_idx, &e_idx, target);
	if (target == 'a' && !is_reverse)
	{
		rotate_inter(tabs, s_idx, e_idx);
		write(1, "ra\n", 3);
	}
	if (target == 'a' && is_reverse)
	{
		rotate_exter(tabs, s_idx, e_idx);
		write(1, "rra\n", 4);
	}
	if	(target == 'b' && is_reverse)
	{
		rotate_inter(tabs, s_idx, e_idx);
		write(1, "rrb\n", 4);
	}
	if (target == 'b' && !is_reverse)
	{
		rotate_exter(tabs, s_idx, e_idx);
		write(1, "rb\n", 3);
	}

}

void	super_rotate(t_tab_ab *tabs, char is_reverse)
{
	rotate(tabs, 'a', is_reverse);
	rotate(tabs, 'b', is_reverse);
}