#include<stdio.h>                                                 /* local_manifests generator*/
#include<stdlib.h>	
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#define RED    "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"         
char pr_name[200];
char pr_path[200];
char pr_revision[200];
char remote[200];
char lm_name[200];
char filename[64];
char  choice;
char choice1;
char choice3;

int main(void){
	char final_choice;
	printf(RED "***     " GREEN " *****  " BLUE " ****** " RED " *****  " YELLOW "***       " CYAN " **   **  " RED " *****  " MAGENTA "**    *** " GREEN "*** " YELLOW "****** " BLUE "****** " BLUE "  ****  " RED "***********\n"
		   RED "***     " GREEN "******* " BLUE "******* " RED "******* " YELLOW "***       " CYAN "**** **** " RED "******* " MAGENTA "***   *** " GREEN "*** " YELLOW "****** " BLUE "****** " BLUE " ****** " RED "***********\n"
		   RED "***     " GREEN "*** *** " BLUE "***     " RED "**   ** " YELLOW "***       " CYAN "*** * *** " RED "**   ** " MAGENTA "****  *** " GREEN "*** " YELLOW "***    " BLUE "***    " BLUE " **  ** " RED "**  ***  **\n"
		   RED "***     " GREEN "*** *** " BLUE "***     " RED "**   ** " YELLOW "***       " CYAN "***   *** " RED "**   ** " MAGENTA "***** *** " GREEN "*** " YELLOW "***    " BLUE "***    " BLUE " **     " RED "    ***    \n"
		   RED "***     " GREEN "*** *** " BLUE "***     " RED "******* " YELLOW "***       " CYAN "***   *** " RED "******* " MAGENTA "*** ***** " GREEN "*** " YELLOW "*****  " BLUE "*****  " BLUE " *****  " RED "    ***    \n"
		   RED "***     " GREEN "*** *** " BLUE "***     " RED "******* " YELLOW "***       " CYAN "***   *** " RED "******* " MAGENTA "***  **** " GREEN "*** " YELLOW "*****  " BLUE "*****  " BLUE "  ***** " RED "    ***    \n"
		   RED "***     " GREEN "*** *** " BLUE "***     " RED "**   ** " YELLOW "***       " CYAN "***   *** " RED "**   ** " MAGENTA "***   *** " GREEN "*** " YELLOW "***    " BLUE "***    " BLUE "     ** " RED "    ***    \n"
		   RED "******* " GREEN "******* " BLUE "******* " RED "**   ** " YELLOW "*******   " CYAN "***   *** " RED "**   ** " MAGENTA "***    ** " GREEN "*** " YELLOW "***    " BLUE "****** " BLUE " ****** " RED "    ***    \n"
		   RED "******* " GREEN " *****  " BLUE " ****** " RED "**   ** " YELLOW "*******   " CYAN "***   *** " RED "**   ** " MAGENTA "***     * " GREEN "*** " YELLOW "***    " BLUE "****** " BLUE "  ****  " RED "    ***    \n"
		  CYAN "                                                                                                          \n" 
		   "                                *******                         *                                         \n" 
		   "                                *******                         ***                                       \n" 
		   "                                **      *** *     *** *    ***  *       *                                 \n" 
		   "                                ** **** * * ****  * * * **   *  *   *** * **                              \n" 
		   "                                **   ** *** **  * *** **   ***  *   * * **                                \n" 
		   "                                ******* *   **  * *   **   * *  *   * * **                                \n" 
		   "                                ******* *** **  * *** **   ****  ** *** **     by rez23                   \n" RESET);
	struct stat st = {0};
	if (stat(".repo/", &st) == -1) {
		mkdir(".repo/", 0700);
		if (stat(".repo/local_manifests", &st) == -1) {
			mkdir(".repo/local_manifests", 0700);
		}
	}
	printf("Insert name for local_manifest:");
	scanf("%s%*c", lm_name);
	sprintf(filename, ".repo/local_manifests/%s.xml", lm_name);
	if(stat(filename, &st) == -1) {
		remove(filename);
	}
	FILE *f2 = fopen(filename, "w+");
	fprintf(f2, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n	<manifest>");
	sprintf(filename, "%s.xml", lm_name);
	do{
		printf("insert the name of repository(e.g:rez23/AdditionalTools):");
		scanf("%s%*c", pr_name);
		printf("Insert the path for sync repo(eg:kernel/universal8890):");
		scanf("%s%*c", pr_path);
		printf("Insert the name of the branch:");
		scanf("%s%*c", pr_revision);
		printf("are your repo a github repo?(y/n):");
		scanf("%c%*c", &choice1);
		switch (choice1){
			case 'y' :  
				strcpy(remote, "github");
				break;
			case 'n' :  
				printf("insert the remote server name:");
				scanf("%s", remote);
				break;
			case '\n' :   
				strcpy(remote, "github");
				break;
		}
		printf("was been generated the follow entry:\n<project name=\"%s\" path=\"%s\" remote=\"%s\" revision=\"%s\" />\n", pr_name, pr_path, remote, pr_revision);
		printf("It's correct?(y/n):");
		scanf("%c%*c", &choice3);
		if( choice3 == 'y')
			fprintf(f2, "\n<project name=\"%s\" path=\"%s\" remote=\"%s\" revision=\"%s\" />", pr_name, pr_path, remote, pr_revision);
		else
			continue;
		printf("Do you want to add another entry to the local_manifest?(y/n):");
		scanf("%c%*c", &choice);
	} while ( choice == 'y' | choice3 == 'n' );
	fprintf(f2, "\n		</manifest>");
	printf("Your local_manifest was been generated succesfully :)\n");
	printf("The generator process is finished.\nNote that the local_manifest file was generated\nin the \".repo\\local_manufests\" path,\nso if you not are into your android build working directory\n press \"^H\" or \"alt+\'.\'\" on your keyboard for see hidden file.\n");
	printf("Good luck and repo sync\n");
	fclose(f2);
};
		
	
