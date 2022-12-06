#include "push_swap.h"

/*-----------------------------------------------------------------------------
 * recuperer la plus longue suite croissante
 * pour chaque nombre :
 *     faire un tour complet de la stack a pour recuperer la taille de la suite
 *     si la suite actuel est la plus grande
 *         enregistrer la taille et l'index du premier nombre
 *     sinon
 *         passer au nombre suivant
 *---------------------------------------------------------------------------*/

void	init_data_sequence(t_data_sequence *data_seq, t_tab_ab data_tabs)
{
	data_seq->seq_list = malloc(sizeof(int) * data_tabs.size);
	data_seq->tmp_list = malloc(sizeof(int) * data_tabs.size);
	data_seq->seq_size = 0;
	data_seq->idx_better_nb = 0;
	data_seq->start_num = 0;
}

void	copy_tab(t_data_sequence *data_seq)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_seq->seq_size)
	{
		data_seq->seq_list[idx] = data_seq->tmp_list[idx];
		idx++;
	}
}

t_bool	is_in_sequence(int number, t_data_sequence data_seq)
{
	unsigned int	idx;

	idx = 0;
	while (idx < data_seq.seq_size)
	{
		if (number == data_seq.seq_list[idx])
			return (true);
		idx++;
	}
	return (false);
}

void	print_s_list(t_data_sequence data_seq, unsigned int size) // TODO remove
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		printf("%d\n", data_seq.seq_list[idx]);
		idx++;
	}
	printf("----------------\n");
}
unsigned int	size_pp(t_tab_ab data_tabs, t_data_sequence *data_seq, unsigned int start, unsigned int	idx)
{
	unsigned int	size;

	size = 1;
//	printf("idx = %u | start = %u\n", idx, start); //OK TODO remove
	while (idx != start)
	{
		if (data_tabs.size < idx)
			idx = data_tabs.top_a;
		if (idx == start)
			break;
		if (data_seq->min < data_tabs.tab[idx] && data_tabs.tab[idx] < data_seq->tmp_list[size - 1])
		{
			data_seq->min = data_tabs.tab[idx];
			data_seq->tmp_list[size - 1] = data_tabs.tab[idx];
		}
		else if (data_seq->tmp_list[size - 1] < data_tabs.tab[idx])
		{
			data_seq->tmp_list[size] = data_tabs.tab[idx];
			size++;
			if (2 <= size)
				data_seq->min = data_seq->tmp_list[size - 2];
		}
//		printf("size = %u | min = %d | tmp = %d\n", size, data_seq->min, data_seq->tmp); // TODO remove
		idx--;
	}
	return (size);
}

void	sequence_size(t_tab_ab data_tabs, t_data_sequence *data_seq, unsigned int start)
{
	unsigned int	idx;
	unsigned int	size;
	
	idx = start;
	size = 1;
	if (data_tabs.size < idx)
	    idx = data_tabs.top_a;
	data_seq->min = data_tabs.tab[idx];
	data_seq->tmp_list[0] = data_tabs.tab[idx];
	idx--;
	size = size_pp(data_tabs, data_seq, start, idx);
	if (data_seq->seq_size < size)
	{
		data_seq->seq_size = size;
		copy_tab(data_seq);
		data_seq->idx_better_nb = start;
		data_seq->start_num = data_tabs.tab[start];
	}
//	print_s_list(*data_seq, size);
}

void	sequence_pusher(t_tab_ab *data_tabs, t_data_sequence data_sequence)
{
	unsigned int	nb_push;
	unsigned int	max_push;

	nb_push = 0;
	max_push = data_tabs->size - data_sequence.seq_size;
	while (nb_push < max_push)
	{
		if (is_in_sequence(data_tabs->tab[data_tabs->top_a], data_sequence) == false)
		{
			if (data_tabs->tab[data_tabs->top_a] < data_tabs->tab[data_tabs->top_a - 1] \
			&& data_tabs->tab[data_tabs->top_a] > data_tabs->tab[0])
				rotate(data_tabs, 'a', 0);
			else
				push(data_tabs, 'b');
			nb_push++;
		}
		else
			rotate(data_tabs, 'a', 0);
	}
}

void	better_sequence(t_tab_ab *data_tabs)
{
	t_data_sequence data_seq;
	unsigned int start;

	init_data_sequence(&data_seq, *data_tabs);
	start = data_tabs->top_a;
	while (start < data_tabs->size)
	{
		sequence_size(*data_tabs, &data_seq, start);
		start--;
	}
//	printf("size = %u | min = %d | tmp = %d\n", data_seq.seq_size, data_seq.min, data_seq.tmp); // OK TODO remove
//	new_print_tab(*data_tabs, 's'); // TODO remove
	sequence_pusher(data_tabs, data_seq);
//	new_print_tab(*data_tabs, 's'); // TODO remove
	if (data_seq.seq_list)
		free(data_seq.seq_list);
	if (data_seq.tmp_list)
		free(data_seq.tmp_list);
}

//---------------------Test function of better_sequence.c----------------------
/*int main(int argc, char *argv[])
{
	t_tab_ab tabs;

	new_init_tab(&tabs, argv[1]);
	better_sequence(&tabs);
	new_print_tab(tabs, 's');
	free(tabs.tab);
}
*/