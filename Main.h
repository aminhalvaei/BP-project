#ifndef MAIN
#define MAIN

#include "Struct.h"

void menu(User* user_head);
User* search_username(User* user_head, char* username);
int date_check(User* user_check);
void login(User* user_head);
void signup(User* user_head, User* temp_user);
User* scan_info();
void print_info(User* user_head);
void command_page(User* user_head, User* user);
void myeditor(User* user);
void help(User* user);
int password_strengh(char* user_password);

#endif // !MAIN