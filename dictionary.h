#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct
{
	char **word;
}Guess_list;

int get_Random_Number();

Guess_list* init_List(char *path);

#endif
