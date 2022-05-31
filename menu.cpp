#include "Main.h"

void menu(User* user_head)
{
	char menu_status[MaxTemp];

	while (1)
	{
		system("cls");
		printf("Please, enter status: (login, signup, exit)\n");           //invalid entry???
		gets_s(menu_status);

		if (strcmp(menu_status, "login") == 0)
		{
			login(user_head);
		}
		else if (strcmp(menu_status, "signup") == 0)
		{
			signup(user_head, user_head);
		}
		else if (strcmp(menu_status, "exit") == 0)
		{
			system("cls");
			printf("Thanks for usage!\a\n");
			_getch();
			return;
		}
		else
		{
			printf("Invalid input!\a\n");
			system("pause");
		}
	}
}