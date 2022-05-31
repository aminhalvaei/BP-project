#include "Main.h"

void help(User* user)
{
	char command[MaxCommand];
	printf("%s->", user->username);
	printf("commands/contact with us!\n");
	printf("cd\tcd ..\tls\tmv\trm\trm -l\tdiff\tmkdir\n");
	printf("cp\tpwd\tpasswd\tpasswd -l\tcreate user\tsu\n");
	printf("promote\tdispromote\tmv\texif\thide\tunhide\n");
	gets_s(command);

	if (strcmp(command, "ls") == 0)
	{
		printf("This command shows the list of files and directories\nEnter \"ls\" then enter path\n");
	}
	else if (strcmp(command, "cd") == 0)
	{
		printf("This command changes the directory\nEnter \"cd\" then enter path\n");
	}
	else if (strcmp(command, "mv") == 0)
	{
		printf("This command use for moving (cut) a directory to anothe path\nEnter \"mv\" then enter current path and in the last enter distination path\n");
	}
	else if (strcmp(command, "help") == 0)
	{
		printf("This shows the command's help for you\n");
	}
	else if (strcmp(command, "cp") == 0)
	{
		printf("To copy a file\nEnter the current path then distination\n");
	}
	else if (strcmp(command, "diff") == 0)
	{
		printf("Shows th diffrences between two files\n Enter first file path then second one \n");
	}
	else if (strcmp(command, "wc") == 0)
	{
		printf("This command shows the number of a file lines\n");
	}
	else if (strcmp(command, "contact with us!") == 0)
	{
		printf("admin number : 09135272682\n");
		printf("Email : aminhalvaei80@gmail.com\n");
	}
	else if (strcmp(command, "rm -l") == 0)
	{
		printf("This is for deleting a directory with what it contains\n");
	}
	else if (strcmp(command, "rm") == 0)
	{
		printf("To remove a file\n");
	}
	else if (strcmp(command, "hide") == 0)
	{
		printf("Enter the path after this command to hide that directory\n");
	}
	else if (strcmp(command, "unhide") == 0)
	{
		printf("To unhide a hidden file or directory in a same syntax with hide command\n");
	}
	else if (strcmp(command, "passwd") == 0)
	{
		printf("This is used for changing the password and depends on your usertype\n");
	}
	else if (strcmp(command, "passwd -l") == 0)
	{
		printf("To change the working time with program\n");
	}
	else if (strcmp(command, "cd ..") == 0)
	{
		printf("resets path\n");
	}
	else if (strcmp(command, "cls") == 0)
	{
		printf("to clear the terminal page\n");
	}
	else if (strcmp(command, "exif") == 0)
	{
		printf("Shows some info about a file\n");
	}
	else if (strcmp(command, "myeditor") == 0)
	{
		printf("Opens a text editor based on the terminal\n");
		printf("It can find a special string whenever you want\n");
	}
	else if (strcmp(command, "cat") == 0)
	{
		printf("Is used to show a file in terminal\n ");
	}
	else if (strcmp(command, "mkdir") == 0)
	{
		printf("Makes a directory in the given path\n");
	}
	else if (strcmp(command, "pwd") == 0)
	{
		printf("shows the current path\n");
	}
	else if (strcmp(command, "create user") == 0)
	{
		printf("Its only accessable for admin to create a new user in emulator\n");
	}
	else if (strcmp(command, "promote") == 0)
	{
		printf("It promotes a ordinary user by an admin\n");
	}
	else if (strcmp(command, "dispromote") == 0)
	{
		printf("It dispromotes a admin to ordinary user\n");
	}
	else if (strcmp(command, "admins") == 0)
	{
		printf("To list the admins in page\n");
	}
	else if (strcmp(command, "users") == 0)
	{
		printf("To list the users in page\n");
	}
	else if (strcmp(command, "su") == 0)
	{
		printf("To switch to another account\n");
    }
	else if (strcmp(command, ">") == 0)
	{

    }
	else if (strcmp(command, ">>") == 0)
	{

    }
	else
	{
	printf("This is not defined in help page\n");
	}
	_getch();
	return;
}