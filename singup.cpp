 #include "Main.h"

void signup(User* user_head, User* temp_user)
{
	int x, pass_count = 1, user_count = 1, date_count = 1;
	char yon[MaxTemp];
	User* jadid = temp_user;
	User* temp_search;
	time_t t;
	tm now;

	system("cls");

	if (temp_user->is_end == 0)
	{
		for (jadid = user_head; jadid->is_end == 0; jadid = jadid->next);

		while (1)
		{
			printf("Username: ");
			gets_s(jadid->username);
			temp_search = search_username(user_head, jadid->username);
			if (temp_search->is_end == 1)
			{
				break;
			}

			printf("This username already has taken\n");
			printf("Try again with another username! (Turn %d of 3)\n", user_count);
			_getch();

			system("cls");

			if (++user_count > 3)
			{
				printf("Please, signup again!\n");
				system("pause");
				return;
			}
		}
	}
	else
	{
		printf("Username: %s\n", jadid->username);
	}

	while(1)                                 //chetor error bebe?
	{
		printf("Password: ");
		gets_s(jadid->password);
		x = password_strengh(jadid->password);
		if (x != 0)
		{
			break;
		}

		printf("Password is not strong!\n");
		printf("Enter password again! (Turn % d of 3)\n", pass_count);
		_getch();

		if (++pass_count > 3)
		{
			system("cls");

			printf("Please, signup again!\n");
			system("pause");
			return;
		}

		system("cls");
		printf("Username: %s\n", jadid->username);
	}

	jadid->password_power = x;
	printf("Name: ");
	gets_s(jadid->name);

	while(1)
	{
		t = time(0);
		localtime_s(&now, &t);
		now.tm_year += 1900;
		now.tm_mon++;

		printf("Set the date (in this format %4d/%02d/%2d %02d:%02d:%02d): ", now.tm_year, now.tm_mon, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);
		scanf("%4d/%2d/%2d %2d:%2d:%2d", &jadid->date.tm_year, &jadid->date.tm_mon, &jadid->date.tm_mday, &jadid->date.tm_hour, &jadid->date.tm_min, &jadid->date.tm_sec);

		x = date_check(jadid);

		if (x == 1)
		{
			break;
		}

		printf("Date is passed!\n"); 
		printf("Please, input date again. (Turn %d of 3)\n", date_count);
		_getch();

		if (++date_count > 3)
		{
			system("cls");

			printf("Please, signup again!\n");
			system("pause");
			return;
		}

		system("cls");
		printf("Username: %s\n", jadid->username);
		printf("Password: %s\n", jadid->password);
		printf("Name: %s\n", jadid->name);
	}


	jadid->new_user = 1;
	jadid->admin_user = 0;
	jadid->promote = 0;
	jadid->change_user = 1;
	jadid->is_end = 0;
	jadid->error_count = 0;

	jadid->next = (User*)malloc(sizeof(User));
	jadid->next->is_end = 1;

	char temp_first[MaxTemp];
	int first = 1;
	while (1)                  
	{
		printf("Do you want to login? (yes / no)\n");
		if (first)
		{
			gets_s(temp_first);                 //bug giri!
			first = 0;
		}
		gets_s(yon);

		if (strcmp(yon, "yes") == 0)
		{
			system("cls");
			command_page(user_head, jadid);
			break;
		}
		else if (strcmp(yon, "no") == 0)
		{
			return;
		}
		else
		{
			printf("Invalid input!\a\n");
			_getch();

			system("cls");
			printf("Username: %s\n", jadid->username);
			printf("Password: %s\n", jadid->password);                         //dobare neshoon bede!!!!!!!!!!!
			printf("Name: %s\n", jadid->name);
			printf("Set the date (in this format %4d/%02d/%2d %02d:%02d:%02d): ", now.tm_year, now.tm_mon, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);
			printf("%4d/%2d/%2d %2d:%2d:%2d\n", jadid->date.tm_year, jadid->date.tm_mon, jadid->date.tm_mday, jadid->date.tm_hour, jadid->date.tm_min, jadid->date.tm_sec);
		}
	}
}