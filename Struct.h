#ifndef STRUCT
#define STRUCT

#include "Header.h"

struct User
{
	char username[MaxUsername];
	char password[MaxPassword];
	char name[MaxName];
	tm date;
	int admin_user;
	int change_user;
	int new_user;
	int error_count;
	int password_power;
	int promote;

	int is_end;
	User* next;
};

#endif // !STRUCT