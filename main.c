#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct login {
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};

void login() {
    char username[30], password[20];
    FILE *log;
    log = fopen("login.txt", "r");
    struct login l;
    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username: ");
    fgets(username, 30, stdin);
    printf("\nPassword: ");
    printf("\n");
    fgets(password, 20, stdin);
    while (fread(&l, sizeof(l), 1, log)) {
        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0) {
            printf("\nSuccessful Login\n");
        } else {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
        }
    }
    fclose(log);
}

void registration() {
    char firstname[15];
    FILE *log;
    log = fopen("login.txt", "w");
    struct login l;
    printf("\nWelcome to your online course provider. We need to enter some details for registration.\n\n");
    printf("Enter First Name:\n");
    scanf("%s", l.fname);
    printf("Enter Surname:\n");
    scanf("%s", l.lname);
    printf("Thank you.\nNow please choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");
    printf("Enter Username:\n");
    scanf("%s", l.username);
    printf("Enter Password:\n");
    scanf("%s", l.password);
    fwrite(&l, sizeof(l), 1, log);
    fclose(log);
    printf("\nConfirming details...\n...\nWelcome, %s!\n\n", firstname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
    getchar();
    system("CLS");
    login();
}

int main() {
    int option;
    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d", &option);
    if (option == 1) {
        system("CLS");
        registration();
    } else if (option == 2) {
        system("CLS");
        login();
    }
}