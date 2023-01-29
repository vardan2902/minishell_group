#include "minishell.h"

void	resize_map(t_ht *map)
{
	size_t		new_size;
	t_ht_node	**new_table;

	new_size = map->size * 2;
	new_table = create_new_table(new_size);
	rehash_nodes(map, new_table, new_size);
	free(map->table);
	map->table = new_table;
	map->size = new_size;
}

t_ht_node	**create_new_table(size_t size)
{
	t_ht_node	**new_table;
	size_t		i;

	i = -1;
	new_table = (t_ht_node **)malloc(sizeof(t_ht_node *) * size);
	while (++i < size)
		new_table[i] = NULL;
	return (new_table);
}

void	rehash_nodes(t_ht *map, t_ht_node **new_table, size_t new_size)
{
	size_t		i;
	size_t		new_index;
	t_ht_node	*node;
	t_ht_node	*next;

	i = -1;
	while (++i < map->size)
	{
		node = map->table[i];
		while (node != NULL)
		{
			new_index = ht_hash(node->key, new_size);
			next = node->next;
			node->next = new_table[new_index];
			new_table[new_index] = node;
			node = next;
		}
	}
}
