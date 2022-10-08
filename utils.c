#include "utils.h"

unsigned int	tab_lenght(const int *tab)
{
	unsigned int	size_tab;

	size_tab = (sizeof tab) / (sizeof (int));
	return (size_tab);
}
