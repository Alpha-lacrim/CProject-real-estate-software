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

void fdecorator1(FILE *fp) {
    int i;
    for (i = 0; i <= 20; i++) {
        fprintf(fp, "*-");
    }
    fprintf(fp, "*\n");
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

int sign_up() {
    char username[50], name[50], last_name[100], email[200], phone_number[120], role[30], citizen_id[20];
    char pw_1[80], pw_2[80], pw_cpy[80];
    char domain[5], input_BD[12], choice[5], owner_pw[80], input_pw[80], ch;
    int birthdate[3] = {0, 0, 0};
    int i, j, z, count1, count2, count3, loop_checker;
    FILE *fp;


    while (1) {
        decorator1();
        printf("SIGN UP\n");
        decorator1();
        printf("Enter the role\n1) ADMIN\n2) USER\n\n9) Exit\n");
        decorator1();
        printf("Entered role :");
        scanf("%s", role);
        fflush(stdin);
        strlwr(role);

        if (strcmp(role, "9") == 0 || strcmp(role, "exit") == 0) {
            system("cls");
            break;
        }

        if (strcmp(role, "admin") == 0 || strcmp(role, "1") == 0) {
            printf("Enter the password :");


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


            strcpy(owner_pw, "Wr||hq83888:;6(");
            decrypter(owner_pw);

            if (strcmp(input_pw, owner_pw) == 0) {
                strcpy(role, "admin");
            }

            else {
                printf("\nWrong password, only owner can create admin\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }
        }
        else {
            if (strcmp(role, "user") == 0 || strcmp(role, "2") == 0) {
                strcpy(role, "user");
            }
            else {
                printf("Wrong input !");
                system("cls");
                continue;
            }
        }
        system("cls");

        //
        while(1) { // username
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please enter your username");
            printf("\n\n\n\n\n");

            decorator1();

            printf("Entered username :");
            scanf("%s", username);
            fflush(stdin);
            strlwr(username);

            for (i = 0, count1 = 0; i < strlen(username); i++) {
                if (isspace(username[i]) != 0) {
                    count1 += 1;
                }
            }
            if (count1 != 0) {
                printf("Your username can NOT contain spaces or tabs !\n Press any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            else {
                if (strlen(username) < 5) {
                    printf("(UN1) Your username is too short !\n Press any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }
            }

            struct user {
                char role[30];
                char username[50];
                char name[50];
                char last_name[100];
                char birthdate[100];
                char citizen_id[20];
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
                if (strcmp(temp->username, username) == 0) {
                    system("cls");
                    decorator1();
                    printf("This username already exists in the system\nPlease enter another username ...\nPress any key to continue\n");
                    decorator1();
                    getch();
                    return 0;
                }
                fscanf(fp, "%*s %s\n", temp->name);
                fscanf(fp, "%*s %s\n", temp->last_name);
                fscanf(fp, "%*s %s\n", temp->citizen_id);
                decrypter(temp->citizen_id);
                fscanf(fp, "%*s %s\n", temp->email);
                fscanf(fp, "%*s %s\n", temp->birthdate);
                fscanf(fp, "%*s %s\n", temp->phone_number);
                decrypter(temp->phone_number);
                fscanf(fp, "%*s %s\n", temp->pw);
                decrypter(temp->pw);
                fscanf(fp, "%*s\n");
            }
            fclose(fp);

            system("cls");
            break;
        }

        while (1) { // name
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please enter your name");
            printf("\n\n\n\n\n");

            decorator1();

            printf("Entered name :");
            scanf("%s", name);
            fflush(stdin);
            strlwr(name);

            decorator1();

            for (count1 = 0, i = 0; i <= strlen(name); i++) {
                if (isdigit(name[i]) != 0) {
                    count1 += 1;
                }
            }
            if (count1 != 0) {
                printf("Your name can NOT contain digits !\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            for (i = 0, count1 = 0; i < strlen(name); i++) {
                if (isspace(name[i]) != 0) {
                    count1 += 1;
                }
            }
            if (count1 != 0) {
                printf("Your name can NOT contain spaces or tabs !\n Press any key to go back ...");
                getch();
                system("cls");
                continue;
            }
            system("cls");


            // last_name
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please enter your last name");
            printf("\n\n\n\n8) Back\n");

            decorator1();

            printf("Entered last name :");
            scanf("%s", last_name);
            fflush(stdin);
            strlwr(last_name);

            decorator1();

            if (strcmp(last_name, "8") == 0 || strcmp(last_name, "back") == 0) {
                system("cls");
                continue;
            }

            for (count2 = 0, i = 0; i <= strlen(last_name); i++) {
                if (isdigit(last_name[i]) != 0) {
                    count2 += 1;
                }
            }

            if (count2 != 0) {
                printf("Your last name can NOT contain digits !\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            while (1) { // citizen ID
                system("cls");
                printf("SIGN UP\n");
                decorator1();
                printf("Enter your citizen ID\n\n\n\n\n");
                decorator1();

                printf("Entered citizen ID:");
                scanf("%s", citizen_id);
                fflush(stdin);

                for (i = 0, count3 = 0; i < strlen(citizen_id); i++) {
                    if (isdigit(citizen_id[i]) == 0) {
                        count3 += 1;
                    }
                }

                if (count3 != 0) {
                    printf("Your citizen ID should be numeric !\nPress any key to go back");
                    getch();
                    system("cls");
                    continue;
                }

                if (strlen(citizen_id) != 10) {
                    printf("Your citizen ID should contain 10 digits !\nPress any key to go back");
                    getch();
                    system("cls");
                    continue;
                }
                encrypter(citizen_id);
                system("cls");
                break;
            }

            while (1) {
                system("cls");
                printf("SIGN UP\n");
                decorator1();

                printf("Enter your birth date (Christian)");
                printf("\n\n\n\n\n");

                decorator1();

                printf("Entered birth date (Year/Month/Day) :");
                scanf("%s", input_BD);
                fflush(stdin);

                if (strlen(input_BD) > 10) {
                    printf("Wrong input !\nPress any key to go back ...");
                    getch();
                    continue;
                }

                sscanf(input_BD, "%d %*c %d %*c %d", &birthdate[0], &birthdate[1], &birthdate[2]);

                if (birthdate[0] < 1900 || birthdate[0] > 2023) {
                    printf("Wrong input !\nPress any key to go back ...");
                    getch();
                    continue;
                } else {
                    if (birthdate[1] <= 0 || birthdate[1] > 12) {
                        printf("Wrong input !\nPress any key to go back ...");
                        getch();
                        continue;
                    } else {
                        if (birthdate[2] > 31 || birthdate[2] <= 0) {
                            printf("Wrong input !\nPress any key to go back ...");
                            getch();
                            continue;
                        }
                    }
                }

                printf("\nyear : %d, month : %d, day : %d\n", birthdate[0], birthdate[1], birthdate[2]);
                printf("Do you want to continue?\n");
                scanf("%s", choice);
                fflush(stdin);
                strlwr(choice);
                if (strcmp(choice, "no") == 0) {
                    continue;
                }
                else {
                    if (strcmp(choice, "yes") == 0) {
                        if (birthdate[0] == 0 || birthdate[1] == 0 || birthdate[2] == 0) {
                            printf("Wrong input !\nPress any key to go back ...");
                            getch();
                            system("cls");
                            continue;
                        }
                    }
                    else {
                        printf("Wrong input !\nPress any key to continue ...");
                        getch();
                        system("cls");
                        continue;
                    }
                }

                system("cls");
                break;
            }
            break;
        }

        system("cls");

        while (1) {// email
            system("cls");
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please enter your email");
            printf("\n\n\n\n\n");

            decorator1();

            printf("Entered email :");
            scanf("%s", email);
            fflush(stdin);
            strlwr(email);

            decorator1();
            system("cls");

            for (i = strlen(email) - 1, count1 = 0; i >= 0; i--) { // @ finder
                if (email[i] == '@') {
                    count1 += 1;
                    j = i;
                }
            }

            if (count1 == 0) { // email checker 1
                printf("(EC1) Wrong email\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            for (i = strlen(email) - 1, count1 = 0; i >= j; i--) {
                if (email[i] == '.') {
                    z = i;
                    count1 += 1;
                }
            }

            if (count1 == 0) { // email checker 2
                printf("(EC2) Wrong email\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            for (i = z, j = 0, count1 = 0; i < strlen(email); i++, j++) {
                domain[j] = email[i];
                count1 += 1;
            }

            for (i = count1; i <= 10; i++) {
                domain[i] = (char)NULL;
            }

            if (strcmp(domain, ".net") == 0 || strcmp(domain, ".com") == 0 || strcmp(domain, ".org") == 0 ||
                strcmp(domain, ".co") == 0 || strcmp(domain, ".uk") == 0 || strcmp(domain, ".ir") == 0) {
            } else { // email checker 3
                printf("(EC3) Wrong email\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            struct user {
                char role[30];
                char username[50];
                char name[50];
                char last_name[100];
                char birthdate[100];
                char citizen_id[20];
                char email[200];
                char phone_number[120];
                char pw[80];
                struct user *link;
            };
            struct user *head = NULL, *tail = NULL, *temp = NULL;

            count2 = 0;

            fp = fopen("user_info.txt", "r");

            while (feof(fp) == 0) {

                temp = malloc(sizeof(struct user));

                fscanf(fp, "%*s %s\n", temp->role);
                fscanf(fp, "%*s %s\n", temp->username);
                fscanf(fp, "%*s %s\n", temp->name);
                fscanf(fp, "%*s %s\n", temp->last_name);
                fscanf(fp, "%*s %s\n", temp->citizen_id);
                decrypter(temp->citizen_id);
                fscanf(fp, "%*s %s\n", temp->email);
                if (strcmp(temp->email, email) == 0) {
                    system("cls");
                    decorator1();
                    printf("This email already exists in the system\nPlease enter another email ...\nPress any key to continue\n");
                    decorator1();
                    getch();
                    count2 += 1;
                    break;
                }
                fscanf(fp, "%*s %s\n", temp->birthdate);
                fscanf(fp, "%*s %s\n", temp->phone_number);
                decrypter(temp->phone_number);
                fscanf(fp, "%*s %s\n", temp->pw);
                decrypter(temp->pw);
                fscanf(fp, "%*s\n");
            }

            if (count2 != 0) { // it'll get another email from the user
                continue;
            }

            fclose(fp);


            while (1) {// phone number
                system("cls");
                decorator1();

                printf("SIGN UP\n");
                decorator1();
                printf("Please enter your phone number");
                printf("\n\n\n\n\n");

                decorator1();

                printf("Entered phone number :");
                scanf("%s", phone_number);
                fflush(stdin);
                strlwr(phone_number);

                for (i = 0, count3 = 0; i < strlen(phone_number); i++) {
                    if (isdigit(phone_number[i]) == 0) {
                        count3 += 1;
                    }
                }

                if (count3 != 0) {
                    system("cls");
                    printf("You can only enter number here\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                if (strlen(phone_number) < 10 || strlen(phone_number) > 11) {
                    printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                if ((strlen(phone_number) == 11) && (phone_number[0] != '0')) {
                    printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                for (i = strlen(phone_number) - 1; i >= 0; i--) {
                    phone_number[i + 1] = phone_number[i];
                }
                phone_number[0] = '0';

                for(i = 11; i < 40; i++) {
                    phone_number[i] = (char)NULL;
                }

                struct user {
                    char role[30];
                    char username[50];
                    char name[50];
                    char last_name[100];
                    char birthdate[100];
                    char citizen_id[20];
                    char email[200];
                    char phone_number[120];
                    char pw[80];
                    struct user *link;
                };
                struct user *head = NULL, *tail = NULL, *temp = NULL;

                count2 = 0;

                fp = fopen("user_info.txt", "r");

                while (feof(fp) == 0) {

                    temp = malloc(sizeof(struct user));

                    fscanf(fp, "%*s %s\n", temp->role);
                    fscanf(fp, "%*s %s\n", temp->username);
                    fscanf(fp, "%*s %s\n", temp->name);
                    fscanf(fp, "%*s %s\n", temp->last_name);
                    fscanf(fp, "%*s %s\n", temp->citizen_id);
                    decrypter(temp->citizen_id);
                    fscanf(fp, "%*s %s\n", temp->email);
                    fscanf(fp, "%*s %s\n", temp->birthdate);
                    fscanf(fp, "%*s %s\n", temp->phone_number);
                    decrypter(temp->phone_number);
                    if (strcmp(temp->phone_number, phone_number) == 0) {
                        system("cls");
                        decorator1();
                        printf("This phone number already exists in the system\n"
                                      "Please enter another phone number ...\nPress any"
                                      " key to continue\n");
                        decorator1();
                        getch();
                        count2 += 1;
                        break;
                    }
                    fscanf(fp, "%*s %s\n", temp->pw);
                    decrypter(temp->pw);
                    fscanf(fp, "%*s\n");
                }

                if (count2 != 0) { // it'll get another phone number from the user
                    continue;
                }

                fclose(fp);

                encrypter(phone_number);
                decorator1();

                break;
            }
            break;
        }

        system("cls");


        while (1) { // str
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please enter your password");
            printf("\n\n\n\n\n");
            decorator1();

            printf("Entered password :");
            scanf("%s", pw_1);
            fflush(stdin);

            if (strlen(pw_1) < 6) { // str len checker
                printf("(P1) Your password is too short !\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }


            for (i = 0, count1 = 0; i < strlen(pw_1); i++) { // str num checker
                if (isdigit(pw_1[i]) == 1) {
                    count1 += 1;
                }
            }

            for (i = 0, count2 = 0; i < strlen(pw_1); i++) { // str special character checker
                if (pw_1[i] == '!' || pw_1[i] == '@' || pw_1[i] == '#' || pw_1[i] == '%' ||
                    pw_1[i] == '^' || pw_1[i] == '&' || pw_1[i] == '*' || pw_1[i] == '(' ||
                    pw_1[i] == ')' || pw_1[i] == '+' || pw_1[i] == '=' || pw_1[i] == '+' ||
                    pw_1[i] == '`' || pw_1[i] == '~' || pw_1[i] == '{' || pw_1[i] == '}' ||
                    pw_1[i] == '[' || pw_1[i] == ']' || pw_1[i] == '"' || pw_1[i] == '\'' ||
                    pw_1[i] == ':' || pw_1[i] == ';' || pw_1[i] == '<' || pw_1[i] == '>' ||
                    pw_1[i] == ',' || pw_1[i] == '.' || pw_1[i] == '?' || pw_1[i] == '/' ||
                    pw_1[i] == '|' || pw_1[i] == '$' || pw_1[i] == '\\') {
                    count2 += 1;
                }
            }

            for (i = 0, count3 = 0; i < strlen(pw_1); i++) { // str alphabet checker
                if ((pw_1[i] >= 65 && pw_1[i] <= 90) || (pw_1[i] >= 97 && pw_1[i] <= 122)) {
                    count3 += 1;
                }
            }

            if (count1 == 0 || count2 == 0 || count3 == 0) {
                printf("(P2) Your password must contain characters, numbers and special characters !\n"
                       "Press any key to go back ...");
                getch();
                system("cls");

                continue;
            }

            system("cls");
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please enter your password again");
            printf("\n\n\n\n8) Back\n");

            decorator1();

            printf("Re-entered password :");
            scanf("%s", pw_2);
            fflush(stdin);

            strcpy(pw_cpy, pw_2);
            strlwr(pw_cpy);
            if (strcmp(pw_cpy, "8") == 0 || strcmp(pw_cpy, "back") == 0) {
                system("cls");
                continue;
            }

            if (strcmp(pw_1, pw_2) != 0) {
                system("cls");
                printf("(P3) The entered passwords are not the same !\n"
                       "Press any key to go back ...");
                getch();
                system("cls");
                continue;
            } else {
                break;
            }
        }
        encrypter(pw_1);


        fp = fopen("user_info.txt", "a+");

        fprintf(fp,
                "ROLE: %s\nUSERNAME: %s\nNAME: %s\nLAST_NAME: %s\nCITIZEN_ID: %s\nEMAIL: %s\nBIRTHDATE: %d/%d/%d"
                "\nPHONE_NUMBER: %s\nPASSWORD: %s\n",
                role, username, name, last_name, citizen_id, email,
                birthdate[0], birthdate[1], birthdate[2], phone_number, pw_1);

        fdecorator1(fp);

        fclose(fp);
        system("cls");
        decorator1();
        printf("Created successfully !\n");
        decorator1();
        printf("\n\n\n\n\nPress any key to continue ...");
        getch();
        break;
    }
}


void main() {
    char choice[20];

    printf("WELCOME !\n");
    while (1) {
        decorator1();
        printf("Please select your choice :\n");
        decorator1();
        printf("1) SIGN UP\n2) SIGN IN\n\n\n9) Exit\n");

        decorator1();

        printf("Your choice :");
        scanf("%s", choice);
        system("cls");

        if ((strcmp(choice, "1") == 0)|| (strcmp(strlwr(choice), "sign up") == 0)) {
            sign_up();
            system("cls");
            continue;

        } else if ((strcmp(choice, "2") == 0)|| (strcmp(strlwr(choice), "sign in") == 0)) {
            //*- sign in *-
            char input_username[40], input_pw[50], role_sign_in[20], ch;
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
                fflush(stdin);
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
                fflush(stdin);

                if (loop_checker != 0) {
                    system("cls");
                    continue;
                }

                struct user {
                    char role[30];
                    char username[50];
                    char name[50];
                    char last_name[100];
                    char birthdate[100];
                    char citizen_id[20];
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
                    fscanf(fp, "%*s %s\n", temp->citizen_id);
                    decrypter(temp->citizen_id);
                    fscanf(fp, "%*s %s\n", temp->email);
                    fscanf(fp, "%*s %s\n", temp->birthdate);
                    fscanf(fp, "%*s %s\n", temp->phone_number);
                    decrypter(temp->phone_number);
                    fscanf(fp, "%*s %s\n", temp->pw);
                    decrypter(temp->pw);

//                    printf("\n%s", temp->role);
//                    printf("\n%s", temp->username);
//                    printf("\n%s", temp->name);
//                    printf("\n%s", temp->last_name);
//                    printf("\n%s", temp->citizen_id);
//                    printf("\n%s", temp->email);
//                    printf("\n%s", temp->birthdate);
//                    printf("\n%s", temp->phone_number);
//                    printf("\n*");


                    if (strcmp(temp->pw, input_pw) == 0 && strcmp(temp->username, input_username) == 0) {
                        loop_checker += 1;
                        strcpy(role_sign_in, temp->role);

                        fclose(fp);
                        break;
                    }
                    fscanf(fp, "%*s\n"); // skipping decorator

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
                    getch();
                    system("cls");
                    decorator1();
                    printf("Login successfully !\n");
                    decorator1();
                    printf("\n\n\n\n\nPress any key to continue ...");
                    getch();
                    system("cls");
                    break;
                }
            } //*- sign in *-



        } else if ((strcmp(choice, "9") == 0) || (strcmp(strlwr(choice), "exit") == 0)) {
            printf("Thanks for using <3\nGoodbye !");
            getch();
            break;

        } else {
            printf("\n*** Wrong input ! ***\nPress any key to continue ...");
            getch();
            system("cls");
        }
    }
}