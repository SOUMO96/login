#include <stdio.h>
#include <string.h>
#include<conio.h>

#define MAX_NAME 100
#define MAX_ACCOUNT 100
#define MAX_PASSWORD 100

struct login
{
    char name[MAX_NAME];
    char Password[MAX_PASSWORD];
};

void add_account(struct login logins[], int *count);
void fetch_data(struct login logins[], int count);
void get_password(char *password);

int main()
{
    struct login logins[MAX_ACCOUNT];
    int choice;
    int count = 0;
    while (1)
    {
        printf("\n WELCOME \n");
        printf(" 1)ADD USER\n");
        printf(" 2)LOGIN\n");
        printf(" 3)EXIT!\n");
        printf(" CHOOSE :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_account(logins, &count);
            break;
        case 2:
            fetch_data(logins, count);
            break;
        case 3:
            return 0;
        default:
            printf("INVALID!");
            break;
        }
    }
    return 0;
}
void add_account(struct login logins[], int *count)
{
    if (*count >= MAX_ACCOUNT)
    {
        printf("NOT SUPPORTED!");
    }
    printf("\nENTER USER NAME :");
    getchar();
    fgets(logins[*count].name, MAX_NAME, stdin);
    logins[*count].name[strcspn(logins[*count].name, "\n")] = 0;

    printf("ENTER A PASSWORD :");
    get_password(logins[*count].Password);


    printf("ACCOUNT CREATED SUCCESSFULLY \n");
    (*count)++;
}
void fetch_data(struct login logins[], int count)
{
    char user_name[MAX_NAME], user_password[MAX_PASSWORD];
    int found = 0;
    
    printf("ENTER USERNAME :");
    getchar();
    fgets(user_name, MAX_NAME, stdin);
    user_name[strcspn(user_name, "\n")] = 0;

    printf("ENTER YOUR PASSWORD :");
    get_password(user_password);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(logins[i].name,user_name) == 0 && strcmp(logins[i].Password ,user_password) == 0)
        {
            printf("\nACCOUNT LOGGED IN SUCCESSFULLY!\n");
            found =1;
            break;
        }
    }
    if (!found)
    {
        printf("WRONG ACCOUNT NUMBER TRY AGAIN!");
    }
}
void get_password(char *password)
{
    int i = 0;
    char ch;

    while (1)
    {
        ch = getch(); // Read a character without echoing on the console

        if (ch == '\r') // Enter key
        {
            password[i] = '\0';
            break;
        }
        else if (ch == '\b' && i > 0) // Handle backspace
        {
            printf("\b \b");
            i--;
        }
        else if (i < MAX_PASSWORD - 1) // Regular character
        {
            printf("*");
            password[i++] = ch;
        }
    }
    printf("\n"); // Move to the next line after password input
}