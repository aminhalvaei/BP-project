#include "Main.h"

void command_page(User* user_head, User* user)                //while mikhahad?
{
	char token[2] = " ";
	char order[3*MaxCommand], command[MaxCommand], temp_username[MaxUsername], temp_password[MaxPassword],order1[3*MaxCommand];
	char direction1[MaxCommand], direction2[MaxCommand], direct[2 * MaxCommand];
	int x, i;
	tm taq;
	User* temp_user;

	char current_path[MaxCommand], current_path2[MaxCommand], current_path3[MaxCommand];
	
	if (user->admin_user == 0)
	{
		strcpy(current_path, "root\\user\\");
	}
	else
	{
		strcpy(current_path, "root\\admin\\");
	}
	strcat(current_path, user->username);

	while (1)
	{

		//system("cls");
		printf("%s :: %s> ", user->username, current_path);
		gets_s(order1);

		x = strlen(order1);
		strtok(order1, token);

		strcpy(order, order1);
		if (x != strlen(order))
		{
			strcpy(command, order1 + strlen(order) + 1);    ///////////////////////////////////////////////////////////////////////////
		}
		else
		{
			command[0] = NULL;
		}

		if (strcmp(order, "logout") == 0)
		{
			break;
		}
		else if (strcmp(order, "promote") == 0)
		{
			if ((user->admin_user == 1))
			{
				temp_user = search_username(user_head, command);
				if (temp_user->is_end == 1)
				{
					printf("There's no user\n");
				}
				else if (temp_user->admin_user == 1)
				{
					printf("User is admin!\n");
				}
				else
				{
					printf("User \"%s\" promoted.\n", temp_user->username);
					temp_user->promote = 1;
					temp_user->admin_user = 1;
				}
			}
			else
			{
				printf("You are not admin\n");
			}
		}
		else if (strcmp(order, "dispromote") == 0)
		{
			if (user->admin_user == 1)
			{
				temp_user = search_username(user_head, command);
				if (temp_user->is_end == 1)
				{
					printf("There's no user.\n");
				}
				else if (temp_user->admin_user == 0)
				{
					printf("User is not admin!\n");
				}
				else if (strcmp(temp_user->username, "admin") == 0)
				{
					printf("You can't dispromote admin!\n");
				}
				else
				{
					printf("User \"%s\" dispromoted.\n", temp_user->username);
					temp_user->promote = 1;
					temp_user->admin_user = 0;
				}
			}
			else
			{
				printf("You are not admin\n");
			}
		}
		else if (strcmp(order, "admins") == 0)
		{
			for (temp_user = user_head; temp_user->is_end == 0; temp_user = temp_user->next)
			{
				if (temp_user->admin_user == 1)
				{
					printf("%s\n", temp_user->username);
				}
			}
		}
		else if (strcmp(order, "users") == 0)
		{
			for (temp_user = user_head; temp_user->is_end == 0; temp_user = temp_user->next)
			{
				if (temp_user->admin_user == 0)
				{
					printf("%s\n", temp_user->username);
				}
			}
		}
		else if (strcmp(order, "create") == 0)
		{
			if (user->admin_user == 1)
			{
				signup(user_head, user_head);
				break;
			}
		}
		else if (strcmp(order, "su") == 0)          //bad az in username miaiad
		{
			temp_user = search_username(user_head, command);
			if (temp_user->is_end == 1)
			{
				printf("There's no user\n");
			}
			else if (user->admin_user == 1)
			{
				if (strcmp(user->username, "admin") == 0 || temp_user->admin_user != 1)
				{
					system("cls");
					command_page(user_head, temp_user);
					break;
				}
				else
				{
					login(user_head);
					break;
				}
			}
			else
			{
				login(user_head);
				break;
			}
		}
		else if (strcmp(order, "passwd") == 0)                   /////////////////////////////////////bug//////////////////////////////////////////
		{
			if (command[0] != '-')
			{
				if (user->admin_user == 1)        //baraye adminha
				{
					temp_user = search_username(user_head, command);
					if (temp_user->is_end == 1)
					{
						printf("There's no user.\n");
					}
					else if (strcmp(user->username, "admin") == 0)
					{
						//hamekar
						printf("Enter new password: ");
						gets_s(temp_password);
						x = password_strengh(temp_password);
						if (x != 0)
						{
							strcpy(temp_user->password, temp_password);
						}
						else
						{
							printf("Password is not strong!\n");
						}
					}
					else
					{
						if (strcmp(temp_username, "admin") != 0)
						{
							//hamekar
							printf("Enter new password: ");
							gets_s(temp_password);
							x = password_strengh(temp_password);
							if (x != 0)
							{
								strcpy(temp_user->password, temp_password);
							}
							else
							{
								printf("Password is not strong!\n");
							}
						}
					}
				}
				else            //braya orduserha
				{
					printf("Enter new password: ");
					gets_s(temp_password);
					x = password_strengh(temp_password);
					if (x != 0)
					{
						strcpy(user->password, temp_password);
					}
					else
					{
						printf("Password is not strong!\n");
					}
				}
			}
			else
			{
				if (user->admin_user == 1)
				{
					printf("Enter date: ");
					scanf("%4d/%2d/%2d %2d:%2d:%2d", &taq.tm_year, &taq.tm_mon, &taq.tm_mday, &taq.tm_hour, &taq.tm_min, &taq.tm_sec);
					_getch();
					printf("Enter username: ");
					gets_s(temp_username);                                                      ////buuuuugggg
					temp_user = search_username(user_head, temp_username);
					if (temp_user->is_end == 1)
					{
						printf("There's no user.\n");
					}
					else if (user->admin_user == 1 && strcmp(user->username, "admin") == 0)
					{
						temp_user->date.tm_year = taq.tm_year;
						temp_user->date.tm_mon = taq.tm_mon;
						temp_user->date.tm_mday = taq.tm_mday;
						temp_user->date.tm_hour = taq.tm_hour;
						temp_user->date.tm_min = taq.tm_min;
						temp_user->date.tm_sec = taq.tm_sec;
						printf("Date changed\n");
					}
					else
					{
						if (strcmp(temp_username, "admin") != 0)
						{
							temp_user->date.tm_year = taq.tm_year;
							temp_user->date.tm_mon = taq.tm_mon;
							temp_user->date.tm_mday = taq.tm_mday;
							temp_user->date.tm_hour = taq.tm_hour;
							temp_user->date.tm_min = taq.tm_min;
							temp_user->date.tm_sec = taq.tm_sec;
							printf("Date changed\n");
						}
					}

				}
				else
				{
					printf("You are not admin\n");
				}
			}
		}
		else if (strcmp(order, "cd") == 0)
		{
			//system("cd");
			if (strcmp(command, "..") != 0)
			{
				strcpy(direct, "cd ");
				//strcpy(precurrent_path, current_path);
				strcat(direct, current_path);
				strcat(direct, command);
				system(direct);  //bad az cd che chizi nemayesh dade shavad
				strcat(current_path, command);
			}
			else
			{
				//strcpy(current_path, precurrent_path);
				for (i = strlen(current_path) - 1; i>0 && (current_path[i] != '/' && current_path[i] != '\\'); i--);
				if (i > 0)
				{
					current_path[i] = '\0';
				}
			}
		}
		else if (strcmp(order, "ls") == 0)             //chetor ls khali kar konad
		{
			strcpy(direct, "dir ");
			strcat(direct, current_path);
			if (command[0] != NULL)
			{
				strcat(direct, command);
			}
			for (i = 0; direct[i]; ++i)
			{
				if (direct[i] == '/')
				{
					direct[i] = '\\';
				}
			}
			system(direct);
		}
		else if (strcmp(order, "pwd") == 0)              //agar ba mkdir baraye har user ya admin dir sakht che konam?
		{
			printf("%s\n",current_path);
		}
		else if (strcmp(order, "mkdir") == 0)
		{
			strcpy(direct, "md E:\\Final\\Final\\");
			strcat(direct, current_path);
			strcat(direct, command);
			system(direct);
		}
		else if (strcmp(order, "cat") == 0)
		{
			strcpy(direct, "TYPE ");
			strcat(direct, current_path);
			strcat(direct, command);
			system(direct);
		}
		else if (strcmp(order, "rm") == 0)     //"path"
		{
			if (command[0] != '-')
			{
				strcpy(direct, "del ");
				strcat(direct, current_path);
				strcat(direct, command);
				system(direct);
			}
			else
			{
				strcpy(direct, "rmdir /s ");
				strcat(direct, current_path);
				if (command[2] != NULL)
				{
					strcat(direct, command + 3);
				}
				system(direct);
				if (command[2] == NULL)
				{
					for (i = strlen(current_path) - 1; i > 0 && (current_path[i] != '/' && current_path[i] != '\\'); i--);
					if (i > 0)
					{
						current_path[i] = '\0';
					}
				}
			}
		}
		else if (strcmp(order, "cp") == 0)       //chetor har user natavanad dir user digar ra dar admin gharar dahad
		{
			strcpy(current_path2, "E:\\Final\\Final\\");
			strcpy(current_path3, "E:\\Final\\Final\\");
			printf("input direction 1: ");
			gets_s(direction1);
			printf("input direction 2: ");
			gets_s(direction2);
			strcpy(direct, "Xcopy /E /I ");
			//strcat(current_path, direction1);
			strcat(current_path3, direction2);
			strcat(current_path2, direction1);
			strcat(direct,current_path2);
			strcat(direct, " ");
			strcat(direct, current_path3);
			system(direct);
			strcpy(current_path2, "E:\\Final\\Final\\");
			strcpy(current_path3, "E:\\Final\\Final\\");
			//strcpy(current_path, current_path3);
			//strcpy(current_path2, "E:\\Final\\Final\\");
		}
		else if (strcmp(order, "mv") == 0)
		{
			strcpy(direct, "move ");
			strcat(direct, current_path);
			strcat(direct, command);
			system(direct);
		}
		else if (strcmp(order, "myeditor") == 0)
		{
			myeditor(user);
		}
/*		else if (strcmp(order, "wc") == 0)
		{
			gets_s(direction1);
			strcpy(direct, "find /c /v ");
			strcpy(current_path3, current_path);
			strcat(current_path, direction1);
			strcat(direct, current_path);
			system(direct);
			strcpy(current_path, current_path3);


		}
*/		else if (strcmp(order, "diff") == 0)
		{
			/*printf("input direction 1: ");
			gets_s(direction1);
			printf("input direction 2: ");
			gets_s(direction2);
			strcpy(current_path3, current_path);
			strcat(current_path, direction1);
			strcat(current_path2, direction2);
			strcpy(direct, "fc ");
			strcat(direct, current_path);
			strcat(direct, " ");
			strcat(direct, current_path2);
			system(direct);
			strcpy(current_path, current_path3);
			strcpy(current_path2, current_path3);*/
			strcpy(current_path2, "E:\\Final\\Final\\");
			strcpy(current_path3, "E:\\Final\\Final\\");
			printf("input direction 1: ");
			gets_s(direction1);
			printf("input direction 2: ");
			gets_s(direction2);
			strcpy(direct, "fc ");
			//strcat(current_path, direction1);
			strcat(current_path3, direction2);
			strcat(current_path2, direction1);
			strcat(direct, current_path2);
			strcat(direct, " ");
			strcat(direct, current_path3);
			system(direct);
			strcpy(current_path2, "E:\\Final\\Final\\");
			strcpy(current_path3, "E:\\Final\\Final\\");
		}
		else if (strcmp(order, "help") == 0)
		{
			help(user);
		}
		else if (strcmp(order, "exif") == 0)
		{
			struct stat stats;
			strcpy(direction1, command);
			strcpy(current_path3, current_path);
			strcat(current_path, direction1);
			if (stat(current_path, &stats) == 0)
			{
				printf("size of file is: %d bytes\n", stats.st_size);
				printf("owner is: %d\n", stats.st_uid);
				printf("time of last access: %d ", stats.st_atime);
				time_t t = stats.st_atime;
				struct tm date;
				localtime_s(&date, &t);
				//				printf("%d/%d/%d %d:%d:%d",&)
			}
			else
			{
				printf("unable to get informations of file");
			}
			strcpy(current_path, current_path3);


		}
		else if (strcmp(order, "clear") == 0)
		{
			system("cls");
			//printf("%s > ", user->username);
		}
		else if (strcmp(order, "hide") == 0)
		{
			strcpy(direction1, command);
			strcpy(current_path3, current_path);
			strcat(current_path, direction1);
			SetFileAttributes(current_path, FILE_ATTRIBUTE_HIDDEN);
			strcpy(current_path, current_path3);
		}
		else if (strcmp(order, "unhide") == 0)
		{
			strcpy(direction1, command);
			strcpy(current_path3, current_path);
			strcat(current_path, direction1);
			SetFileAttributes(current_path, FILE_ATTRIBUTE_NORMAL);
			strcpy(current_path, current_path3);
		}
		else if (order[0] != NULL)
		{
			printf("This command has not defined!\n");     // barayae erroer giri az karbar bayad estefade shavad     // should be one of fields of struct!!!!!
			user->error_count++;
		}

		if (order[0] != NULL && strcmp(order, "clear") != 0)
		{
			printf("\n");
		}
		//system("pause");
	}
}