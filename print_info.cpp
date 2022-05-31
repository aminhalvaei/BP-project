#include "Main.h"

void print_info(User* user_head)
{
	User* temp_user;
	FILE* admin_txt, * user_txt, * temp_txt;
	char admin_direct[] = "root/admin/", user_direct[] = "root/user/", temp_direct[MaxDirect], move_direct[MaxCommand + 2 * MaxDirect]; //

	_mkdir("root");                     //mage dar tabea scan make nashod?chera dobare make?
	SetFileAttributes("root", FILE_ATTRIBUTE_HIDDEN);
	_mkdir(admin_direct);
	_mkdir(user_direct);

	admin_txt = fopen("root/admin.txt", "w");
	user_txt = fopen("root/user.txt", "w");

	// read admin.txt
	temp_user = user_head;
	while (temp_user->is_end != 1)     //
	{
		if (temp_user->admin_user == 1)
		{
			fprintf(admin_txt, "%s\n", temp_user->username);
			if (temp_user->new_user == 1 || temp_user->change_user == 1 || temp_user->promote == 1)  //admin sakhte nemishavad faghat az user be admin tabdil maishavad pas aya shart aval ra mikhahad?
			{
				strcpy(temp_direct, admin_direct);
				strcat(temp_direct, temp_user->username);

				if (temp_user->new_user == 1)
				{
					_mkdir(temp_direct);
				}
				else if (temp_user->promote == 1)
				{
					strcpy(move_direct, "move ");
					strcat(move_direct, user_direct);
					strcat(move_direct, temp_user->username);
					strcat(move_direct, " ");
					strcat(move_direct, temp_direct);
					system(move_direct);
					system("cls");
				}

				if (temp_user->change_user == 1 || temp_user->new_user == 1)
				{
					strcat(temp_direct, "/info.txt");
					temp_txt = fopen(temp_direct, "w");

					fprintf(temp_txt, "%s\n%s\n%d\n%d\n", temp_user->name, temp_user->password, temp_user->password_power, temp_user->error_count);
					fprintf(temp_txt, "%4d/%02d/%02d %02d:%02d:%02d\n", temp_user->date.tm_year, temp_user->date.tm_mon, temp_user->date.tm_mday, temp_user->date.tm_hour, temp_user->date.tm_min, temp_user->date.tm_sec);

					fclose(temp_txt);
				}
			}
		}
		else
		{
			fprintf(user_txt, "%s\n", temp_user->username);
			if (temp_user->new_user == 1 || temp_user->change_user == 1 || temp_user->promote == 1)
			{
				strcpy(temp_direct, user_direct);
				strcat(temp_direct, temp_user->username);

				if (temp_user->new_user == 1)
				{
					_mkdir(temp_direct);
				}
				else if (temp_user->promote == 1)
				{
					strcpy(move_direct, "move ");
					strcat(move_direct, admin_direct);
					strcat(move_direct, temp_user->username);
					strcat(move_direct, " ");
					strcat(move_direct, temp_direct);
					system(move_direct);
					system("cls");
				}

				if (temp_user->change_user == 1 || temp_user->new_user == 1)
				{
					strcat(temp_direct, "/info.txt");
					temp_txt = fopen(temp_direct, "w");

					fprintf(temp_txt, "%s\n%s\n%d\n%d\n", temp_user->name, temp_user->password, temp_user->password_power, temp_user->error_count);
					fprintf(temp_txt, "%4d/%02d/%02d %02d:%02d:%02d\n", temp_user->date.tm_year, temp_user->date.tm_mon, temp_user->date.tm_mday, temp_user->date.tm_hour, temp_user->date.tm_min, temp_user->date.tm_sec);

					fclose(temp_txt);
				}
			}
		}
		temp_user = temp_user->next;
	}
	fclose(admin_txt);
	fclose(user_txt);
}