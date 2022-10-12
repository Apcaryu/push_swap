#include "push_swap.h"

static unsigned int	the_words(char const *s, char c)
{
	size_t	size;
	size_t	idx;
	size_t	nb_words;
	char	is_word;
	char	tmp;

	size = ft_strlen(s);
	idx = 0;
	nb_words = 0;
	is_word = 0;
	tmp = 0;
	while (idx <= size)
	{
		if (s[idx] == c && tmp != 0)
			is_word = 0;
		if (s[idx] != c && tmp != 1)
			is_word = 1;
		if (is_word == 0 && tmp == 1)
			nb_words++;
		if (s[idx] == '\0' && tmp == 1 && s[idx] != c)
			nb_words++;
		idx++;
		tmp = is_word;
	}
	return (nb_words);
}

static int	*char_to_int(char **list, unsigned int size_list)
{
	int 			*list_out;
	unsigned int	idx;

	list_out = ft_calloc(size_list, (sizeof (int)));
	if (!list_out)
		return (NULL);
	idx = 0;
	while (idx < size_list)
	{
		list_out[idx] = ft_atoi(list[idx]);
		idx++;
	}
	return (list_out);
}

int	*init_tab(char *list)
{
	char **char_list;
	int *list_out;
	unsigned int size_list;

	size_list = the_words(list, ' ');
	char_list = ft_split(list, ' ');
	list_out = char_to_int(char_list, size_list);
	return (list_out);
}

void	new_init_tab(t_tab_ab *tabs, char *argv)
{
	char	**char_list;
	unsigned int size_list;

	size_list = the_words(argv, ' ') + 1;
	char_list = ft_split(argv, ' ');
	tabs->tab = (long int*)char_to_int(char_list, size_list + 1);
	tabs->tab[size_list] = SEPARATOR;
	tabs->size = size_list;
	tabs->top_a = size_list - 1;
}