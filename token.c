/*
* file: token.c
* author: bhakti
* date: 15/03/2023
*/

#include <string.h>
#include <stdio.h>
#include "token.h"

int tokenise (char inputLine[], char *token[])
{
     	char *tok;
      	int i=0;

	tok = strtok(inputLine, tokenSeparators);
	token[i] = tok;

	while (tok != NULL) {

	  i++;
	  if (i>=MAX_NUM_TOKENS) {
	      i = -1;
	      break;
	  }

	  tok = strtok(NULL, tokenSeparators);
	  token[i] = tok;
	}
	
	return i;
}
