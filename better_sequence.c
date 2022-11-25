#include "push_swap.h"

/*---------------------------------------------------------------------------*/
/* recuperer la plus longue suite croissante
 * pour chaque nombre :
 *     faire un tour complet de la stack a pour recuperer la taille de la suite
 *     si la suite actuel est la plus grande
 *         enregistrer la taille et l'index du premier nombre
 *     sinon
 *         passer au nombre suivant
 *---------------------------------------------------------------------------*/

void	sequence_size(t_tab_ab data_tabs, t_data_sequence *data_seq, unsigned int start)
{
	unsigned int	idx;
	unsigned int	size;
	int 			tmp;
	
	idx = start - 1;
	size = 1;
	if (idx == 4294967295)
	    idx = data_tabs.top_a;
	tmp = data_tabs.tab[idx];
	idx--;
	while (idx != start)
	{
		if (idx == 4294967295)
			idx = data_tabs.top_a;
		if (tmp < data_tabs.tab[idx])
			size++;
		idx--;
	}
	if (data_seq->seq_size < size)
	{
		data_seq->seq_size = size;
		data_seq->idx_better_nb = start;
	}
}

void	better_sequence(t_tab_ab *data_tabs)
{
	t_data_sequence data_seq;
}
