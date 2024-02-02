#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

void decorator1() {
    int i;
    for (i = 0; i <= 40; i++) { // Decorator
        printf("*-");
    }
    putchar('*');
    printf("\n");
}

void encrypter(char str[40]) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (i % 2 == 0) {
            str[i] = str[i] + 7;
        }
        else {
            str[i] = str[i] + 3;
        }
    }
}

void decrypter(char str[40]) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (i % 2 == 0) {
            str[i] = str[i] - 7;
        }
        else {
            str[i] = str[i] - 3;
        }
    }
}

char sign_in() {
    char input_username[40], input_pw[50], role[20], ch;
    int loop_checker = 0, i;
    FILE *fp;

    while (1) {
        decorator1();
        printf("SIGN IN\n");
        decorator1();
        printf("Enter your username\n\n\n\n\n");
        decorator1();
        printf("Entered username :");
        scanf("%s", input_username);
        strlwr(input_username);
        system("cls");

        decorator1();
        printf("SIGN IN\n");
        decorator1();
        printf("Enter your password\n\n\n\n\n");
        decorator1();
        printf("Entered password :");

        for (i = 0, loop_checker = 0; (ch = _getch()) != 13; i++) {
            if (ch == 8) {
                loop_checker += 1;
                break;
            }
            input_pw[i] = ch;
            printf("*");
        }
        input_pw[i] = '\0';
        if (loop_checker != 0) {
            printf("\nAn error occurred");
            system("cls");
            continue;
        }

        struct user {
            char role[30];
            char username[50];
            char name[50];
            char last_name[100];
            char birthdate[100];
            char email[200];
            char phone_number[120];
            char pw[80];
            struct user *link;
        };
        struct user *head = NULL, *tail = NULL, *temp = NULL;

        fp = fopen("user_info.txt", "r");

        while (feof(fp) == 0) {

            temp = malloc(sizeof(struct user));

            fscanf(fp, "%*s %s\n", temp->role);
            fscanf(fp, "%*s %s\n", temp->username);
            fscanf(fp, "%*s %s\n", temp->name);
            fscanf(fp, "%*s %s\n", temp->last_name);
            fscanf(fp, "%*s %s\n", temp->email);
            fscanf(fp, "%*s %s\n", temp->birthdate);
            fscanf(fp, "%*s %s\n", temp->phone_number);
            decrypter(temp->phone_number);
            fscanf(fp, "%*s %s\n", temp->pw);
            decrypter(temp->pw);

            if (strcmp(temp->pw, input_pw) == 0 && strcmp(temp->username, input_username) == 0) {
                loop_checker += 1;
                strcpy(role, temp->role);

                fclose(fp);
                break;
            }
            fscanf(fp, "%*s");

            if (head == NULL) {
                head = temp;
                head->link = NULL;
                tail = head;
            } else {
                tail->link = temp;
                tail = temp;
                tail->link = NULL;
            }
        }

        if (loop_checker == 0) {
            printf("\nNo results found\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }
        else {
            system("cls");
            decorator1();
            printf("Login successfully !\n");
            decorator1();
            printf("\n\n\n\n\nPress any key to continue ...");
            getch();
            // return
            break;
        }
    }
}

void main() {
    sign_in();
}