#include "main.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void log_push(log **head, char *msg)
{
	static unsigned int entry_num;
	time_t currentTime;
	log *new = NULL;

	if (head == NULL)
	{
		fprintf(stderr, "There's no head to push to\n");
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(log));
	if (new == NULL)
	{
		fprintf(stderr, "Malloc failed at log_push\n");
		exit(EXIT_FAILURE);
	}

	time(&currentTime); 
	new->log = strdup(msg);
	new->entry_num = entry_num++;
	new->time_of_entry = strdup(ctime(&currentTime));
	new->next = NULL;
	new->prev = NULL;

	/* no entry yet assign head to the new node */
	if (*head != NULL)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	(*head) = new;
}

void log_write(FILE *file, log **head)
{
	log *cur = NULL;

	if (head == NULL)
	{
		printf("Nothing to print");
		return;
	}

	cur = *head;
	while (cur)
	{
		fprintf(file, "\nLog: %s\nEntry#: %d\nDate: %s",
				cur->log, cur->entry_num, cur->time_of_entry);
		cur = cur->next;
	}
}

void log_print(log **head)
{
	log *cur = NULL;

	if (head == NULL)
	{
		printf("Nothing to print");
		return;
	}

	cur = *head;
	while (cur)
	{
		printf("\n");
		printf("Entry #: %d\n", cur->entry_num);
		printf("Log: %s\n", cur->log);
		printf("Time of Entry: %s", cur->time_of_entry);

		cur = cur->next;
	}
}

void log_free(log *head)
{
	log *c = NULL;

	while(head)
	{
		c = head->next;
		free(head->log);
		free(head);
		head = c;
	}
}
