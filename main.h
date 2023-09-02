#ifndef MAIN_H
#define MAIN_H

#define PROMPT "Enter Entry: "

typedef struct log_t
{
	char *log;
	char *time_of_entry;
	unsigned int entry_num;
	struct log_t *next;
	struct log_t *prev;
} log;

log *log_init(char *msg);
void log_push(log **head, char *msg);
void log_free(log *head);
void log_print(log **head);

#endif /* MAIN_H */
