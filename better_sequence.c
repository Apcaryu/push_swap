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
	
	idx = start;
	size = 1;
	if (data_tabs.size < idx)
	    idx = data_tabs.top_a;
	tmp = data_tabs.tab[idx];
	idx--;
	while (idx != start)
	{
		if (data_tabs.size < idx)
			idx = data_tabs.top_a;
		if (tmp < data_tabs.tab[idx])
		{
			tmp = data_tabs.tab[idx];
			size++;
		}
		if (idx == start)
			break;
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
	unsigned int start;

	data_seq.seq_size = 0;
	start = data_tabs->top_a;
	while (start < data_tabs->size)
	{
		sequence_size(*data_tabs, &data_seq, start);
		start--;
	}
	printf("better_sequence = %u | num_start = %u\n", data_seq.seq_size, data_tabs->tab[data_seq.idx_better_nb]);
}

//---------------------Test function of better_sequence.c----------------------
int main(int argc, char *argv[])
{
	t_tab_ab tabs;

	new_init_tab(&tabs, argv[1]);
	better_sequence(&tabs);
	new_print_tab(tabs, 's');
}