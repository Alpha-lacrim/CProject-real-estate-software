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

void sign_up() {
    char username[50], name[20], last_name[40], email[100], phone_number[40], role[10], citizen_id[12];
    char pw[40], pw_1[40], pw_2[40], pw_cpy[40];
    char domain[5], input_BD[12], choice[5], owner_pw[40], input_pw[40], ch;
    int birthdate[3];
    int i, j, z, count1, count2, count3, loop_checker = 0;
    FILE *fp;


    struct user {
        char role[10];
        char username[50];
        char name[20];
        char last_name[40];
        char citizen_id[12];
        int birthdate[10];
        char email[100];
        char phone_number[40];
        char pw[40];
    };
    struct user info;

    while (1) {
        decorator1();
        printf("SIGN UP\n");
        decorator1();
        printf("Enter the role\n1) ADMIN\n2) USER\n\n9) Exit\n");
        decorator1();
        printf("Entered role :");
        scanf("%s", role);
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
                strcpy(info.role, "admin");
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
                strcpy(info.role, "user");
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
            strlwr(username);

            for (i = 0, count1 = 0; i < strlen(username); i++) {
                if (username[i] == 9 || username[i] == 32) {
                    count1 += 1;
                }
            }
            if (count1 != 0) {
                printf("(UN1) Your username can NOT contain spaces or tabs !\nPress any key to go back ...");
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
                break;
            }

            while (1) {
                printf("SIGN UP\n");
                decorator1();

                printf("Enter your birth date (Christian)");
                printf("\n\n\n\n\n");

                decorator1();

                printf("Entered birth date (Year/Month/Day) :");
                scanf("%s", input_BD);

                if (strlen(input_BD) > 10) {
                    printf("Wrong input !\nPress any key to go back ...");
                    getch();
                    continue;
                }

                sscanf(input_BD, "%d %*c %d %*c %d", &birthdate[0], &birthdate[1], &birthdate[2]);
                printf("\nyear : %d, month : %d, day : %d\n", birthdate[0], birthdate[1], birthdate[2]);
                printf("Do you want to continue?");
                scanf("%s", choice);
                strlwr(choice);
                if (strcmp(choice, "no") == 0) {
                    system("cls");
                    continue;
                }
                else {
                    if (strcmp(choice, "yes") != 0) {
                        printf("Wrong input !\nPress any key to go back ...");
                        getch();
                        continue;
                    }
                }


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
                system("cls");
                break;
            }
            break;
        }

        system("cls");

        while (1) {// email
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please enter your email");
            printf("\n\n\n\n\n");

            decorator1();

            printf("Entered email :");
            scanf("%s", email);
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
                domain[i] = NULL;
            }

            if (strcmp(domain, ".net") == 0 || strcmp(domain, ".com") == 0 || strcmp(domain, ".org") == 0 ||
                strcmp(domain, ".co") == 0 || strcmp(domain, ".uk") == 0 || strcmp(domain, ".ir") == 0) {
            } else { // email checker 3
                printf("(EC3) Wrong email\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            while (1) {// phone number
                decorator1();

                printf("SIGN UP\n");
                decorator1();
                printf("Please enter your phone number");
                printf("\n\n\n\n\n");

                decorator1();

                printf("Entered phone number :");
                scanf("%s", phone_number);
                strlwr(phone_number);


                if (strlen(phone_number) < 10 || strlen(phone_number) > 11) { // number checker 1
                    printf("\nERROR (PN1): WRONG PHONE NUMBER !!!\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                for (i = 0; i <= strlen(phone_number); i++) { // number checker 2
                    count1 += isdigit(phone_number[i]);
                }

                if (count1 == 0) {
                    printf("\nERROR (PN2): WRONG PHONE NUMBER2 !!!\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                if (phone_number[0] != '0' &&
                    strlen(phone_number) == 10) { // adds 0 to the phone number if the user didn't
                    for (i = 9; i >= 0; i--) {
                        phone_number[i + 1] = phone_number[i];
                    }
                    phone_number[0] = '0';
                }

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

        strcpy(info.username, username);
        strcpy(info.name, name);
        strcpy(info.last_name, last_name);
        strcpy(info.citizen_id, citizen_id);
        strcpy(info.email, email);
        strcpy(info.phone_number, phone_number);
        strcpy(info.pw, pw_1);
        info.birthdate[0] = birthdate[0];
        info.birthdate[1] = birthdate[1];
        info.birthdate[2] = birthdate[2];


        fp = fopen("user_info.txt", "a+");

        fprintf(fp,
                "ROLE: %s\nUSERNAME: %s\nNAME: %s\nLAST_NAME: %s\nCITIZEN_ID: %s\nEMAIL: %s\nBIRTHDATE: %d/%d/%d"
                "\nPHONE_NUMBER: %s\nPASSWORD: %s\n",
                info.role, info.username, info.name, info.last_name, info.citizen_id, info.email,
                info.birthdate[0], info.birthdate[1],info.birthdate[2], info.phone_number, info.pw);

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
