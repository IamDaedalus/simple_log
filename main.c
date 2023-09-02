#include "main.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	char *line = NULL;
	size_t size = 0;
	log *head = NULL;

	while (1)
	{
		printf("%s", PROMPT);
		if (getline(&line, &size, stdin) != -1)
		{
			line = strtok(line, " \n");
			if (strncmp(line, "exit", 4) == 0)
				break;

			log_push(&head, line);
		}
	}

	free(line);

	log_print(&head);
	log_free(head);

	return 0;
}
