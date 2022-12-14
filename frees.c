#include "monty.h"

/**
 * _free - This function frees memory
 */

void _free(void)
{
	stack_t *tmp = NULL;
	stack_t *delete;

	delete = *global_var;

	while (delete)
	{
		tmp = delete->next;

		free(delete);

		delete = tmp;
	}
}

