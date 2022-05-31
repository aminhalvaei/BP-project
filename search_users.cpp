#include "Main.h"

User* search_username(User* user_head, char* username)
{
	User* temp;
	for (temp = user_head; temp->is_end == 0; temp = temp->next)
	{
		if (strcmp(temp->username, username) == 0)
		{
			break;
		}
	}
	return temp;
}