#include "Main.h"

User* scan_info()
{
	User* user_head, * temp_user;
	FILE* admin_txt, * user_txt, * temp_txt;
	char admin_direct[] = "root/admin/", user_direct[] = "root/user/", temp_direct[MaxDirect];

	_mkdir("root");
	SetFileAttributes("root", FILE_ATTRIBUTE_HIDDEN);
	_mkdir(admin_direct);
	_mkdir(user_direct);

	admin_txt = fopen("root/admin.txt", "r");
	if (admin_txt == NULL)  //first time
	{
		user_head = (User*)malloc(sizeof(User));
		strcpy(user_head->name, "amin");
		strcpy(user_head->username, "admin");
		strcpy(user_head->password, "admin");
		user_head->password_power = 10;
		user_head->admin_user = 1;
		user_head->promote = 0;
		user_head->error_count = 0;
		user_head->new_user = 1;
		user_head->change_user = 0;
		user_head->is_end = 0;

		time_t t = time(0);
		localtime_s(&user_head->date, &t);
		user_head->date.tm_year += 1900;
		user_head->date.tm_mon++;

		user_head->next = (User*)malloc(sizeof(User));
		user_head->next->is_end = 1;
	}
	else  // !first time
	{
		// read admin.txt
		user_head = (User*)malloc(sizeof(User));
		temp_user = user_head;
		while (fgets(temp_user->username, MaxUsername - 1, admin_txt) != NULL)
		{
			temp_user->username[strlen(temp_user->username) - 1] = NULL;     //buuuug

			strcpy(temp_direct, admin_direct);
			strcat(temp_direct, temp_user->username);
			strcat(temp_direct, "/info.txt");
			temp_txt = fopen(temp_direct, "r");///

			fgets(temp_user->name, MaxName - 1, temp_txt);
			temp_user->name[strlen(temp_user->name) - 1] = NULL;
			fgets(temp_user->password, MaxPassword - 1, temp_txt);
			temp_user->password[strlen(temp_user->password) - 1] = NULL;

			fscanf(temp_txt, "%d", &temp_user->password_power);
			fscanf(temp_txt, "%d", &temp_user->error_count);

			if (strcmp(temp_user->username, "admin") != 0)
			{
				fscanf(temp_txt, "%4d/%02d/%02d %02d:%02d:%02d", &temp_user->date.tm_year, &temp_user->date.tm_mon, &temp_user->date.tm_mday, &temp_user->date.tm_hour, &temp_user->date.tm_min, &temp_user->date.tm_sec);
			}

			temp_user->admin_user = 1;
			temp_user->promote = 0;
			temp_user->new_user = 0;
			temp_user->change_user = 0;
			temp_user->is_end = 0;

			fclose(temp_txt);
			temp_user->next = (User*)malloc(sizeof(User));
			temp_user = temp_user->next;
		}
		temp_user->is_end = 1;
		fclose(admin_txt);

		// read user.txt
		user_txt = fopen("root/user.txt", "r");
		if (user_txt != NULL)
		{
			while (fgets(temp_user->username, MaxUsername - 1, user_txt) != NULL)
			{
				temp_user->username[strlen(temp_user->username) - 1] = NULL;

				strcpy(temp_direct, user_direct);
				strcat(temp_direct, temp_user->username);
				strcat(temp_direct, "/info.txt");
				temp_txt = fopen(temp_direct, "r");

				fgets(temp_user->name, MaxName - 1, temp_txt);
				temp_user->name[strlen(temp_user->name) - 1] = NULL;
				fgets(temp_user->password, MaxPassword - 1, temp_txt);
				temp_user->password[strlen(temp_user->password) - 1] = NULL;
				fscanf(temp_txt, "%d", &temp_user->password_power);
				fscanf(temp_txt, "%d", &temp_user->error_count);
				fscanf(temp_txt, "%4d/%02d/%02d %02d:%02d:%02d", &temp_user->date.tm_year, &temp_user->date.tm_mon, &temp_user->date.tm_mday, &temp_user->date.tm_hour, &temp_user->date.tm_min, &temp_user->date.tm_sec);

				temp_user->admin_user = 0;
				temp_user->promote = 0;
				temp_user->new_user = 0;
				temp_user->change_user = 0;
				temp_user->is_end = 0;

				fclose(temp_txt);

				temp_user->next = (User*)malloc(sizeof(User));
				temp_user = temp_user->next;
			}
			temp_user->is_end = 1;
			fclose(user_txt);
		}
	}
	return user_head;
}