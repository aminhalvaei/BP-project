#include "Main.h"

void myeditor(User* user)
{
	char current_path[MaxCommand];
	char command[MaxCommand];
	

	if (user->admin_user == 1)
	{
		strcpy(current_path, "E:\\Final\\Final\\root");
	}
	else
	{
		strcpy(current_path, "E:\\Final\\Final\\root\\user\\");
		strcat(current_path, user->username);
	}

	while (1)
	{
		system("cls");
		printf("%s->", user->username);
		printf("...EDITOR...");

		if (strcmp(command, "open") == 0)
		{

		}
		else if (strcmp(command,"create new")==0)
		{

		}
		else if (strcmp(command, "find") == 0)
		{
			system("findstr");
		}
			
	}
}