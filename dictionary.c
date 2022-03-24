#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <err.h>
#include <string.h>
#include "dictionary.h"


#define MAXWORD 1371
#define MAXSIZE 7

int get_Random_Number()
{
	srand(time(NULL));
	return (rand() % 1370);
}


Guess_list* init_List(char* path)
{
	Guess_list *list = malloc(sizeof(Guess_list));
	list->word = calloc(MAXWORD+1, sizeof(char *));
	if(list == NULL)
		errx(1, "could not allocated memory.");
	FILE *ptr = fopen(path, "r");
	if(ptr == NULL)
		errx(1, "there was an error in the file name.");

	int i = 0;
	char s[9];
	while(!feof(ptr))
	{
		fgets(s, 9, ptr);
		list->word[i] = calloc(MAXSIZE + 2, sizeof(char));
		if(s[7] == '\n')
			s[7] = '\0';
		strncpy(list->word[i], s, 7);
		i++;
	}
	fclose(ptr);
	return list;
}

/*int main()
{
	Guess_list *list = init_List("wordlist.txt");
	for(int i = 0; i < MAXWORD; i++)
	{
		printf("%s\n", list->word[i]);
	}

	for(int j = 0; j <= MAXWORD; j++)
		free(list->word[j]);
    free(list->word);
	free(list);
	return 1;
}*/
