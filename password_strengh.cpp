#include "Main.h"

int password_strengh(char* user_password)
{
	int i;
	int s = 0;

	for (i = 0; user_password[i] != '\0'; i++)
	{
		if ('A' <= user_password[i] && user_password[i] <= 'Z')
		{
			s = s + 4;
		}
		else if ('a' <= user_password[i] && user_password[i] <= 'z')
		{
			s = s + 2;
		}
		else if ('0' <= user_password[i] && user_password[i] <= '9')
		{
			s = s + 3;
		}
		else if (user_password[i] == ' ')
		{
			s = s + 1;
		}
		else
		{
			s = s + 8;
		}
	}

	if (s > 100 || s < 33)
	{
		return 0;      //it means password is invalid we should make preedure that guratee this func will run again
	}


	return s;   //it means that the password is acceptable and returns its strengh
}