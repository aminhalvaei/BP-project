#include "Main.h"

int main()
{
	User* user_head = scan_info();
	printf("Welcome to Program!\n");
	_getch();
	menu(user_head);
	print_info(user_head);
	return 0;
}