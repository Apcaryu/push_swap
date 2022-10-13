#include "instruction_set.h"

void	push(t_tab_ab *tabs, char target)
{
	if (target == 'a' && tabs->top_a < tabs->size - 1)
		tabs->top_a += 1;
	else if (target == 'b' && 0xFFFFFFFF != tabs->top_a)
		tabs->top_a -= 1;
}
