#include "Main.h"

void login(User* user_head)
{
	User* temp_user = user_head;
	char temp_username[MaxUsername];
	char temp_password[MaxPassword];
	char yon[MaxTemp];

	system("cls");
	printf("username: ");
	gets_s(temp_username);
	if (strcmp(temp_username, "admin") != 0)
	{
		temp_user = search_username(user_head, temp_username);
	}

	if (temp_user->is_end == 1)
	{ // User is new
		while (1)
		{
			system("cls");
			printf("There is no \"%s\" user!\a\nDo you want to singup with this username? (yes / no)\n", temp_username);
			gets_s(yon);

			if (strcmp(yon, "yes") == 0)
			{
				strcpy(temp_user->username, temp_username);
				signup(user_head, temp_user);
				break;
			}
			else if (strcmp(yon, "no") == 0)
			{
				break;
			}
			else
			{
				printf("Invalid input!\a\n");
				system("pause");
			}
		}

	}
	else        
	{ // username is found
		int wrong_count = 1;
		while(1)
		{
			printf("password: ");
			gets_s(temp_password);

			if (strcmp(temp_user->password, temp_password) == 0)
			{
				if ((strcmp(temp_username, "admin") != 0) && (date_check(temp_user) == 0))
				{
					system("cls");
					printf("Your user is out of date. Please call admin!\a\n");
					system("pause");
				}
				else
				{
					//successfully logined
					system("cls");
					command_page(user_head, temp_user);
				}
				break;
			}
			else
			{
				printf("Wrong password! (Turn %d of 3)\a\n", wrong_count);
				printf("Please enter corroct password\n");
				_getch();

				if (++wrong_count > 3)
				{
					printf("Please, enter program again!\a");
					_getch();
					break;
				}

				system("cls");
				printf("username: %s\n", temp_user->username);
			}
		}
	}
}