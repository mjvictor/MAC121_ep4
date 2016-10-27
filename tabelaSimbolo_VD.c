
#include "stable_types.h"

/*coloca desordenado, coloca no topo.*/
void put_VD (SymbolTable *table, char *key) {
	SymbolTable *new;
	char *word;
	int len;

	if (table->i == table->max) {
		new = create_stable (2*table->max);
		for (i = 0; i < table->max; i++) {
			/*melhorar isso*/
			len = strlen (table->v[i].key);
			free (new->v[i].key);
			new->v[i].key = malloc (len * sizeof (char));
			new->v[i].key = strdup (table->v[i].key);
			new->v[i].freq = table->v[i].freq
			free(table->v[i].key);
		}
		free(table->v);
		table->v = new->v;
	}
	table->v[table->i].key = strdup (key);
	if (table->v[table->i].key == NULL)  {
		len = strlen (key);
		free (table->v[table->i].key)
		table->v[table->i].key = malloc (len * sizeof (char));
		table->v[table->i].key = strdup (key);
	}
	table->v[table->i].freq++;
	table->i++;
}