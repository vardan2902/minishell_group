#ifndef HASH_TABLE_H
# define HASH_TABLE_H

size_t	ht_hash(const char *key, int size);

void	ht_init_map(t_ht *map, size_t size);
void	*ht_get(t_ht *map, const char *key);
void	ht_remove_entry(t_ht *map, const char *key);

void	ht_set(t_ht *map, const char *key, void *value);

#endif
