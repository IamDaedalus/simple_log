#include "main.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	FILE *file;
	char *line = NULL;
	size_t size = 0;
	log *head = NULL;

	file = fopen("simple.log", "a+");
	if (file == NULL)
	{
		fprintf(stderr, "Couldn't work with saved file\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("%s", PROMPT);
		getline(&line, &size, stdin);
		line = strtok(line, " \n");

		if (strncmp(line, "exit", 4) == 0)
			break;

		log_push(&head, line);
	}

	free(line);
	log_write(file, &head);

	fclose(file);
	log_free(head);

	return 0;
}
