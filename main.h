#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#define PROMPT "Enter Entry: "

typedef struct log_t
{
	char *log;
	char *time_of_entry;
	unsigned int entry_num;
	struct log_t *next;
	struct log_t *prev;
} log;

void log_write(FILE *file, log **head);
void log_push(log **head, char *msg);
void log_free(log *head);
void log_print(log **head);

#endif /* MAIN_H */
