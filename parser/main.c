#include "parser.h"
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*
 * main.c
 * A simple Command Line Parser.
 * Author : Michael Roberts <mroberts@it.net.au>
 * Last Modification : 11/09/01
 * Modified 11/9/01 by Nick Nelissen, who speparated the main into a separate source
 *	file
 */


/*
 * This function reads one line of 256 characters from stdin. THis line of
 * characters is then processed as a command line.
 * The resulting array of structures is then displayed to stdout.
 *
 * Arguments :
 *      None.
 *
 * Returns :
 *      An integer representing the exit status.
 *
 */
int
main(void)
{
   char *cmd;
   int lc = 0;
   char *c;
   command **cl;
   char *shellPrompt = "%";

   cmd = (char *) malloc(CMD_LENGTH);

   

   while (strcmp(cmd, "exit") != 0) {
   	printf("%s ", shellPrompt);
   	cmd = fgets(cmd, CMD_LENGTH, stdin);
	   c = index(cmd, '\n');
	   *c = '\0';
	   
	   cl = process_cmd_line(cmd, 1);
	  
   	for(lc = 0; cl[lc] != NULL; lc++) {
   		if (strcmp(cl[lc]->com_name, "prompt") == 0) 
   		{
   			shellPrompt = cl[lc]->argv[1];
   		}
   		
   		
	      	pid_t pid = fork();
		if (pid == 0) {
			execvp(cl[lc]->argv[0], cl[lc]->argv);
			exit(0);
			printf("\n");
		} else if (pid > 0) {
			wait ((int*)0);
			
		}
       }
  }
     

   clean_up(cl);
   free(cmd);

   return 0;
}                       /*End of main() */

