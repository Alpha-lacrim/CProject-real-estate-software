#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#define FILENAME_SIZE 32
#define MAX_LINE 256

char *log_username_ptr, *log_pw_ptr, *log_role_ptr;

void decorator1() {
    int i;
    for (i = 0; i <= 40; i++) { // Decorator
        printf("*-");
    }
    putchar('*');
    printf("\n");
}


void decorator2() {
    int i;
    for (i = 0; i <= 25; i++) {
        printf("*+-");
    }
    printf("*\n");
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


void space_converter(char str[100]) {
    int i;

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 9 || str[i] == 32) {
            str[i] = '_';
        }
    }
}


void space_returner(char str[100]) {
    int i;

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '_') {
            str[i] = 32;
        }
    }
}


void time_fwriter(FILE *fp, int i) {
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    if (i == 1) {
        fprintf(fp, "ADDED_ON: %d-%02d-%02d %02d:%02d\n",
                date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min);
    }

    else {
        if (i == 0) {
            fprintf(fp, "REMOVED_ON: %d-%02d-%02d %02d:%02d\n",
                    date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min);
        }

        else {
            if (i == 2) {
                fprintf(fp, "CREATED_ON: %d-%02d-%02d %02d:%02d\n",
                        date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min);
            }
            else {
                printf("ERROR: CAN NOT WRITE IN THE FILE");

            }
        }
    }
}


char time_string_converter(char time_str[100]) {
    time_t t = time(NULL);
    struct tm date = *localtime(&t);

    sprintf(time_str, "%d-%02d-%02d %02d:%02d",
            date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min);
}


int file_updater(char filename[FILENAME_SIZE], int replace_line, char replace[MAX_LINE]) {
    char temp_filename[FILENAME_SIZE], buffer[MAX_LINE];
    int current_line = 1;
    FILE *fp, *fp_temp;
    strcpy(temp_filename, "temp_");
    strcat(temp_filename, filename);


    fp = fopen(filename, "r");
    fp_temp = fopen(temp_filename, "w");

    if (fp_temp == NULL || fp == NULL) {
        printf("FILE ERROR: FILE CAN NOT BE OPENED");
        return 1;
    }

    bool reading = true;

    do {
        fgets(buffer, MAX_LINE, fp);

        if (feof(fp)) {
            reading = false;
        }
        else {
            if (current_line == replace_line) {

                fprintf(fp_temp, replace);
                fprintf(fp_temp, "\n");
            }

            else {
                fputs(buffer, fp_temp);
            }
        }

        current_line += 1;

    } while (reading);

    fclose(fp);
    fclose(fp_temp);

    remove(filename);
    rename(temp_filename, filename);

}


int sign_up() {
    char username[50], name[50], last_name[100], email[200], phone_number[120], role[30], citizen_id[20];
    char pw_1[80], pw_2[80], pw_cpy[80];
    char domain[5], input_BD[12], choice[5], owner_pw[80], input_pw[80], ch;
    int birthdate[3] = {0, 0, 0};
    int i, j, z, count1, count2, count3, loop_checker;
    FILE *fp;
    time_t t;
    time(&t);

    while (1) {
        decorator1();
        printf("\t\t\t   SIGN UP\n");
        decorator1();
        printf("Enter The Role\n1) ADMIN\n2) USER\n\n8) Back\n");
        decorator1();
        printf("Entered Role :");
        scanf("%s", role);
        fflush(stdin);
        strlwr(role);

        if (strcmp(role, "8") == 0 || strcmp(role, "back") == 0) {
            system("cls");
            break;
        }

        if (strcmp(role, "admin") == 0 || strcmp(role, "1") == 0) {
            printf("Enter The Password :");


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
                printf("\nWrong Password, only owner can create admin\nPress any key to return ...");
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
                printf("WRONG INPUT!");
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
            printf("Please Enter Your Username");
            printf("\n\n\n\n\n");

            decorator1();

            printf("Entered Username :");
            scanf("%s", username);
            fflush(stdin);
            strlwr(username);

            for (i = 0, count1 = 0; i < strlen(username); i++) {
                if (isspace(username[i]) != 0) {
                    count1 += 1;
                }
            }
            if (count1 != 0) {
                printf("Your Username can NOT contain spaces or tabs !\n Press any key to return ...");
                getch();
                system("cls");
                continue;
            }

            else {
                if (strlen(username) < 5) {
                    printf("(UN1) Your Username is too short !\n Press any key to return ...");
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
                    printf("This Username already exists in the system\nPlease enter another Username ...\nPress any key to continue\n");
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
            printf("Please enter your Name");
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
                printf("Your Name can NOT contain digits !\nPress any key to return ...");
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
                printf("Your Name can NOT contain spaces or tabs !\n Press any key to return ...");
                getch();
                system("cls");
                continue;
            }
            system("cls");


            // last_name
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please Enter Your Last Name");
            printf("\n\n\n\n8) Back\n");

            decorator1();

            printf("Entered Last Name :");
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
                printf("Your Last Name can NOT contain digits !\nPress any key to return ...");
                getch();
                system("cls");
                continue;
            }

            while (1) { // citizen ID
                system("cls");
                printf("SIGN UP\n");
                decorator1();
                printf("Enter your Citizen ID\n\n\n\n\n");
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
                    printf("Your Citizen ID should be numeric !\nPress any key to return");
                    getch();
                    system("cls");
                    continue;
                }

                if (strlen(citizen_id) != 10) {
                    printf("Your Citizen ID should contain 10 digits !\nPress any key to return");
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

                printf("Enter Your Birthdate (Christian)");
                printf("\n\n\n\n\n");

                decorator1();

                printf("Entered Birthdate (Year/Month/Day) :");
                scanf("%s", input_BD);
                fflush(stdin);

                if (strlen(input_BD) > 10) {
                    printf("WRONG INPUT!\nPress any key to return ...");
                    getch();
                    continue;
                }

                sscanf(input_BD, "%d %*c %d %*c %d", &birthdate[0], &birthdate[1], &birthdate[2]);

                if (birthdate[0] < 1900 || birthdate[0] > 2023) {
                    printf("WRONG INPUT!\nPress any key to go back ...");
                    getch();
                    continue;
                } else {
                    if (birthdate[1] <= 0 || birthdate[1] > 12) {
                        printf("WRONG INPUT!\nPress any key to return ...");
                        getch();
                        continue;
                    } else {
                        if (birthdate[2] > 31 || birthdate[2] <= 0) {
                            printf("WRONG INPUT!\nPress any key to return ...");
                            getch();
                            continue;
                        }
                    }
                }

                printf("\nYear : %d, Month : %d, Day : %d\n", birthdate[0], birthdate[1], birthdate[2]);
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
                            printf("WRONG INPUT!\nPress any key to go back ...");
                            getch();
                            system("cls");
                            continue;
                        }
                    }
                    else {
                        printf("WRONG INPUT!\nPress any key to continue ...");
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
            printf("Please Enter Your Email");
            printf("\n\n\n\n\n");

            decorator1();

            printf("Entered Email :");
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
                printf("(EC1) WRONG EMAIL\nPress any key to go back ...");
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
                printf("(EC2) WRONG EMAIL\nPress any key to go back ...");
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
                printf("(EC3) WRONG EMAIL\nPress any key to go back ...");
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
                    printf("This Email already exists in the system\nPlease enter another email ...\nPress any key to continue\n");
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
                printf("Please Enter Your Phone Number");
                printf("\n\n\n\n\n");

                decorator1();

                printf("Entered Phone Number :");
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
                    printf("You can only enter number here\nPress any key to return ...");
                    getch();
                    system("cls");
                    continue;
                }

                if (strlen(phone_number) < 10 || strlen(phone_number) > 11) {
                    printf("\nWRONG PHONE NUMBER !!!\nPress any key to return ...");
                    getch();
                    system("cls");
                    continue;
                }

                if ((strlen(phone_number) == 11) && (phone_number[0] != '0')) {
                    printf("\nWRONG PHONE NUMBER !!!\nPress any key to return ...");
                    getch();
                    system("cls");
                    continue;
                }

                if ((strlen(phone_number) == 10) && (phone_number[0] == '0')) {
                    printf("\nWRONG PHONE NUMBER !!!\nPress any key to return ...");
                    getch();
                    system("cls");
                    continue;
                }

                if (strlen(phone_number) != 11) {
                    for (i = strlen(phone_number) - 1; i >= 0; i--) {
                        phone_number[i + 1] = phone_number[i];
                    }
                    phone_number[0] = '0';
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


        while (1) { // pw
            decorator1();

            printf("SIGN UP\n");
            decorator1();
            printf("Please Enter Your Password");
            printf("\n\n\n\n\n");
            decorator1();

            printf("Entered Password :");
            scanf("%s", pw_1);
            fflush(stdin);

            if (strlen(pw_1) < 6) { // pw len checker
                printf("(P1) Your password is too short !\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }


            for (i = 0, count1 = 0; i < strlen(pw_1); i++) { // pw num checker
                if (isdigit(pw_1[i]) == 1) {
                    count1 += 1;
                }
            }

            for (i = 0, count2 = 0; i < strlen(pw_1); i++) { // pw special character checker
                if (pw_1[i] == '!' || pw_1[i] == '@' || pw_1[i] == '#' || pw_1[i] == '%' ||
                    pw_1[i] == '^' || pw_1[i] == '&' || pw_1[i] == '*' || pw_1[i] == '(' ||
                    pw_1[i] == ')' || pw_1[i] == '+' || pw_1[i] == '=' || pw_1[i] == '+' ||
                    pw_1[i] == '`' || pw_1[i] == '~' || pw_1[i] == '{' || pw_1[i] == '}' ||
                    pw_1[i] == '[' || pw_1[i] == ']' || pw_1[i] == '"' || pw_1[i] == '\''||
                    pw_1[i] == ':' || pw_1[i] == ';' || pw_1[i] == '<' || pw_1[i] == '>' ||
                    pw_1[i] == ',' || pw_1[i] == '.' || pw_1[i] == '?' || pw_1[i] == '/' ||
                    pw_1[i] == '|' || pw_1[i] == '$' || pw_1[i] == '\\') {
                    count2 += 1;
                }
            }

            for (i = 0, count3 = 0; i < strlen(pw_1); i++) { // pw alphabet checker
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
            printf("Please Enter Again Your Password");
            printf("\n\n\n\n8) Back\n");

            decorator1();

            printf("Re-entered Password :");
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

        time_fwriter(fp, 2);
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


int residential_property_fwriter(int rent_or_sell) {
    char address[100], building_lifespan[10], building_meterage[10], building_municipal_area[5];
    char floor[10], base_meterage[10], owner_phone_number[40], rooms[10], type[20];
    char price[20]; // sell
    char mortgage[20], rental_price[20]; // rent
    int i, c;
    FILE *fp;

    system("cls");
    decorator1();
    printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
    decorator1();
    printf("Please Enter The Type Of The Building\n\n\n\n8) Back\n");
    decorator1();
    printf("Type :");
    scanf("%s", type);
    fflush(stdin);
    strlwr(type);

    if (strcmp("back", type) == 0 || strcmp("8", type) == 0) {
        system("cls");
        return 0;
    }

    system("cls");
    decorator1();
    printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
    decorator1();
    printf("Please Enter The Address Of The Apartment\n\n\n\n\n");
    decorator1();
    printf("Address :");
    gets(address);
    strlwr(address);
    space_converter(address);

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please Enter The Building's Lifespan\n\n\n\n\n");
        decorator1();
        printf("Lifespan :");
        scanf("%s", building_lifespan);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(building_lifespan); i++) {
            if (isdigit(building_lifespan[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;

    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please Enter Building's Meterage\n\n\n\n\n");
        decorator1();
        printf("Building Meterage :");
        scanf("%s", building_meterage);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(building_meterage); i++) {
            if (isdigit(building_meterage[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;
    }

    system("cls");
    decorator1();
    printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
    decorator1();
    printf("Please Enter The Building Municipal Area\n\n\n\n\n");
    decorator1();
    printf("Area :");
    scanf("%s", building_municipal_area);
    fflush(stdin);

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please Enter The Number Of Rooms\n\n\n\n\n");
        decorator1();
        printf("Rooms :");
        scanf("%s", rooms);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(building_municipal_area); i++) {
            if (isdigit(building_municipal_area[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;

    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("What Floor is The Property on?\n\n\n\n\n");
        decorator1();
        printf("Floor :");
        scanf("%s", floor);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(floor); i++) {
            if (isdigit(floor[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;
    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please Enter The Base Meterage\n\n\n\n\n");
        decorator1();
        printf("Base Meterage :");
        scanf("%s", base_meterage);
        fflush(stdin);


        for (i = 0, c = 0; i < strlen(base_meterage); i++) {
            if (isdigit(base_meterage[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;
    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please Enter The Owner's Phone Number \n\n\n\n\n");
        decorator1();
        printf("Phone Number :");
        scanf("%s", owner_phone_number);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(owner_phone_number); i++) {
            if (isdigit(owner_phone_number[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (strlen(owner_phone_number) < 10 || strlen(owner_phone_number) > 11) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if ((strlen(owner_phone_number) == 11) && (owner_phone_number[0] != '0')) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if ((strlen(owner_phone_number) == 10) && (owner_phone_number[0] == '0')) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (strlen(owner_phone_number) != 11) {
            for (i = strlen(owner_phone_number) - 1; i >= 0; i--) {
                owner_phone_number[i + 1] = owner_phone_number[i];
            }
            owner_phone_number[0] = '0';
        }

        break;
    }

    if (rent_or_sell == 2) {
        while (1) {
            system("cls");
            decorator1();
            printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
            decorator1();
            printf("Please Enter The Property's Price\n\n\n\n\n");
            decorator1();
            printf("Price :");
            scanf("%s", price);
            fflush(stdin);

            for (i = 0, c = 0; i < strlen(price); i++) {
                if (isdigit(price[i]) == 0) {
                    c += 1;
                }
            }

            if (c != 0) {
                system("cls");
                printf("You can only enter number here\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }
            break;
        }

        struct sell_residential_property {
            char address[100];
            char building_lifespan[10];
            char building_meterage[10];
            char building_municipal_area[5];
            char floor[10];
            char base_meterage[10];
            char owner_phone_number[40];
            char rooms[10];
            char type[20];
            char price[20];
        };
        struct sell_residential_property info;

        strcpy(info.address, address);
        strcpy(info.building_lifespan, building_lifespan);
        strcpy(info.building_meterage, building_meterage);
        strcpy(info.building_municipal_area, building_municipal_area);
        strcpy(info.floor, floor);
        strcpy(info.owner_phone_number, owner_phone_number);
        strcpy(info.rooms, rooms);
        strcpy(info.type, type);
        strcpy(info.price, price);
        strcpy(info.base_meterage, base_meterage);

        fp = fopen("sell_residential_properties.txt", "a+");

        fprintf(fp, "STATUS: ACTIVE\nADDRESS: %s\nBUILDING_LIFESPAN: %s\nBUILDING_METERAGE: %s\nBUILDING_MUNICIPAL_AREA: %s"
                    "\nFLOOR: %s\nBASE_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\nROOMS: %s\nTYPE: %s\nPRICE: %s\nADDED_BY: %s\n",
                info.address, info.building_lifespan, info.building_meterage, info.building_municipal_area, info.floor,
                info.base_meterage, info.owner_phone_number, info.rooms, info.type, info.price, log_username_ptr);
        time_fwriter(fp, 1);
        fdecorator1(fp);
        fclose(fp);
        system("cls");
        printf("***- ADDED SUCCESSFULLY -***\nPress any key to continue ...");
        getch();
        system("cls");
    }

    else {
        if (rent_or_sell == 1) {
            while (1) {
                system("cls");
                decorator1();
                printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
                decorator1();
                printf("Please Enter The Property's Mortgage\n\n\n\n\n");
                decorator1();
                printf("Mortgage :");
                scanf("%s", mortgage);
                fflush(stdin);

                for (i = 0, c = 0; i < strlen(mortgage); i++) {
                    if (isdigit(mortgage[i]) == 0) {
                        c += 1;
                    }
                }

                if (c != 0) {
                    system("cls");
                    printf("You can only enter number here\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }
                break;
            }

            while (1) {
                system("cls");
                decorator1();
                printf("\t\t\t\t   RESIDENTIAL PROPERTY\n");
                decorator1();
                printf("Please Enter The Property Rental Price\n\n\n\n\n");
                decorator1();
                printf("Rental Price :");
                scanf("%s", rental_price);
                fflush(stdin);

                for (i = 0, c = 0; i < strlen(rental_price); i++) {
                    if (isdigit(rental_price[i]) == 0) {
                        c += 1;
                    }
                }

                if (c != 0) {
                    system("cls");
                    printf("You can only enter number here\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                break;
            }

            struct rent_residential_property {
                char address[100];
                char building_lifespan[10];
                char building_meterage[10];
                char building_municipal_area[5];
                char floor[10];
                char base_meterage[10];
                char owner_phone_number[40];
                char rooms[10];
                char type[20];
                char rental_price[20];
                char mortgage[20];
            };
            struct rent_residential_property info;

            strcpy(info.address, address);
            strcpy(info.building_lifespan, building_lifespan);
            strcpy(info.building_meterage, building_meterage);
            strcpy(info.building_municipal_area, building_municipal_area);
            strcpy(info.floor, floor);
            strcpy(info.base_meterage, base_meterage);
            strcpy(info.owner_phone_number, owner_phone_number);
            strcpy(info.rooms, rooms);
            strcpy(info.type, type);
            strcpy(info.rental_price, rental_price);
            strcpy(info.mortgage, mortgage);

            fp = fopen("rent_residential_properties.txt", "a+");

            fprintf(fp, "STATUS: ACTIVE\nADDRESS: %s\nBUILDING_LIFESPAN: %s\nBUILDING_METERAGE: %s\nBUILDING_MUNICIPAL_AREA: %s\nFLOOR: %s\n"
                        "BASE_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\nROOMS: %s\nTYPE: %s\nMORTGAGE: %s\nRENTAL_PRICE: %s\nADDED_BY: %s\n",
                    info.address, info.building_lifespan, info.building_meterage, info.building_municipal_area, info.floor,
                    info.base_meterage, info.owner_phone_number, info.rooms, info.type, info.mortgage, info.rental_price, log_username_ptr);
            time_fwriter(fp, 1);
            fdecorator1(fp);
            fclose(fp);
            system("cls");
            printf("***- ADDED SUCCESSFULLY -***\nPress any key to continue ...");
            getch();
            system("cls");

        }
        else {
            printf("ADDING FAILED E1");
            return 0;
        }
    }
}


int office_property_fwriter(int rent_or_sell) {
    char address[100], building_lifespan[10], building_meterage[10], building_municipal_area[5];
    char floor[10], base_meterage[10], owner_phone_number[40], rooms[10], type[20];
    char price[20]; // sell
    char mortgage[20], rental_price[20]; // rent
    int i, c;
    FILE *fp;

    system("cls");
    decorator1();
    printf("\t\t\t\t   OFFICE PROPERTY\n");
    decorator1();
    printf("Please Enter The Type of The Building\n\n\n\n8) Back\n");
    decorator1();
    printf("Type :");
    scanf("%s", type);
    fflush(stdin);
    strlwr(type);

    if (strcmp("back", type) == 0 || strcmp("8", type) == 0) {
        system("cls");
        return 0;
    }

    system("cls");
    decorator1();
    printf("\t\t\t\t   OFFICE PROPERTY\n");
    decorator1();
    printf("Please Enter The Address of The Apartment\n\n\n\n\n");
    decorator1();
    printf("Address :");
    gets(address);
    strlwr(address);
    space_converter(address);

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   OFFICE PROPERTY\n");
        decorator1();
        printf("Please Enter The Building's Lifespan\n\n\n\n\n");
        decorator1();
        printf("Lifespan :");
        scanf("%s", building_lifespan);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(building_lifespan); i++) {
            if (isdigit(building_lifespan[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;

    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   OFFICE PROPERTY\n");
        decorator1();
        printf("Please Enter Building's Meterage\n\n\n\n\n");
        decorator1();
        printf("Meterage :");
        scanf("%s", building_meterage);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(building_meterage); i++) {
            if (isdigit(building_meterage[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;
    }

    system("cls");
    decorator1();
    printf("\t\t\t\t   OFFICE PROPERTY\n");
    decorator1();
    printf("Please Enter The Building Municipal Area\n\n\n\n\n");
    decorator1();
    printf("Area :");
    scanf("%s", building_municipal_area);
    fflush(stdin);

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   OFFICE PROPERTY\n");
        decorator1();
        printf("Please Enter The number of rooms\n\n\n\n\n");
        decorator1();
        printf("Rooms :");
        scanf("%s", rooms);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(building_municipal_area); i++) {
            if (isdigit(building_municipal_area[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;

    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   OFFICE PROPERTY\n");
        decorator1();
        printf("What Floor is The Property on?\n\n\n\n\n");
        decorator1();
        printf("Floor :");
        scanf("%s", floor);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(floor); i++) {
            if (isdigit(floor[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;
    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   OFFICE PROPERTY\n");
        decorator1();
        printf("Please Enter The Base Meterage\n\n\n\n\n");
        decorator1();
        printf("Meterage :");
        scanf("%s", base_meterage);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(base_meterage); i++) {
            if (isdigit(base_meterage[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        break;
    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   OFFICE PROPERTY\n");
        decorator1();
        printf("Please Enter The Owner's Phone Number \n\n\n\n\n");
        decorator1();
        printf("Phone Number :");
        scanf("%s", owner_phone_number);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(owner_phone_number); i++) {
            if (isdigit(owner_phone_number[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (strlen(owner_phone_number) < 10 || strlen(owner_phone_number) > 11) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if ((strlen(owner_phone_number) == 11) && (owner_phone_number[0] != '0')) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if ((strlen(owner_phone_number) == 10) && (owner_phone_number[0] == '0')) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (strlen(owner_phone_number) != 11) {
            for (i = strlen(owner_phone_number) - 1; i >= 0; i--) {
                owner_phone_number[i + 1] = owner_phone_number[i];
            }
            owner_phone_number[0] = '0';
        }


        break;
    }

    if (rent_or_sell == 2) { // sell
        while (1) {
            system("cls");
            decorator1();
            printf("\t\t\t\t   OFFICE PROPERTY\n");
            decorator1();
            printf("Please Enter The Property's Price\n\n\n\n\n");
            decorator1();
            printf("Price :");
            scanf("%s", price);
            fflush(stdin);

            for (i = 0, c = 0; i < strlen(price); i++) {
                if (isdigit(price[i]) == 0) {
                    c += 1;
                }
            }

            if (c != 0) {
                system("cls");
                printf("You can only enter number here\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }
            break;
        }

            struct sell_office_property {
                char address[100];
                char building_lifespan[10];
                char building_meterage[10];
                char building_municipal_area[5];
                char floor[10];
                char base_meterage[10];
                char owner_phone_number[40];
                char rooms[10];
                char type[20];
                char price[20];
            };
            struct sell_office_property info;

        strcpy(info.address, address);
        strcpy(info.building_lifespan, building_lifespan);
        strcpy(info.building_meterage, building_meterage);
        strcpy(info.building_municipal_area, building_municipal_area);
        strcpy(info.floor, floor);
        strcpy(info.base_meterage, base_meterage);
        strcpy(info.owner_phone_number, owner_phone_number);
        strcpy(info.rooms, rooms);
        strcpy(info.type, type);
        strcpy(info.price, price);

        fp = fopen("sell_office_properties.txt", "a+");

        fprintf(fp, "STATUS: ACTIVE\nADDRESS: %s\nBUILDING_LIFESPAN: %s\nBUILDING_METERAGE: %s\nBUILDING_MUNICIPAL_AREA: %s\nFLOOR: %s\n"
                    "BASE_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\nROOMS: %s\nTYPE: %s\nPRICE: %s\nADDED_BY: %s\n",
                info.address, info.building_lifespan, info.building_meterage, info.building_municipal_area, info.floor,
                info.base_meterage, info.owner_phone_number, info.rooms, info.type, info.price, log_username_ptr);
        time_fwriter(fp, 1);
        fdecorator1(fp);
        fclose(fp);
        system("cls");
        printf("***- ADDED SUCCESSFULLY -***\nPress any key to continue ...");
        getch();
        system("cls");
    }

    else {
        if (rent_or_sell == 1) { // rent
            while (1) {
                system("cls");
                decorator1();
                printf("\t\t\t\t   OFFICE PROPERTY\n");
                decorator1();
                printf("Please Enter The Property's Mortgage\n\n\n\n\n");
                decorator1();
                printf("Mortgage :");
                scanf("%s", mortgage);
                fflush(stdin);

                for (i = 0, c = 0; i < strlen(mortgage); i++) {
                    if (isdigit(mortgage[i]) == 0) {
                        c += 1;
                    }
                }

                if (c != 0) {
                    system("cls");
                    printf("You can only enter number here\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                break;
            }

            while (1) {
                system("cls");
                decorator1();
                printf("\t\t\t\t   OFFICE PROPERTY\n");
                decorator1();
                printf("Please Enter The Property Rental Price\n\n\n\n\n");
                decorator1();
                printf("Rental Price :");
                scanf("%s", rental_price);
                fflush(stdin);

                for (i = 0, c = 0; i < strlen(rental_price); i++) {
                    if (isdigit(rental_price[i]) == 0) {
                        c += 1;
                    }
                }

                if (c != 0) {
                    system("cls");
                    printf("You can only enter number here\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                break;
            }

            struct rent_office_property {
                char address[100];
                char building_lifespan[10];
                char building_meterage[10];
                char building_municipal_area[5];
                char floor[10];
                char base_meterage[10];
                char owner_phone_number[40];
                char rooms[10];
                char type[20];
                char rental_price[20];
                char mortgage[20];
            };
            struct rent_office_property info;

            strcpy(info.address, address);
            strcpy(info.building_lifespan, building_lifespan);
            strcpy(info.building_meterage, building_meterage);
            strcpy(info.building_municipal_area, building_municipal_area);
            strcpy(info.floor, floor);
            strcpy(info.base_meterage, base_meterage);
            strcpy(info.owner_phone_number, owner_phone_number);
            strcpy(info.rooms, rooms);
            strcpy(info.type, type);
            strcpy(info.rental_price, rental_price);
            strcpy(info.mortgage, mortgage);

            fp = fopen("rent_office_properties.txt", "a+");

            fprintf(fp, "STATUS: ACTIVE\nADDRESS: %s\nBUILDING_LIFESPAN: %s\nBUILDING_METERAGE: %s\nBUILDING_MUNICIPAL_AREA: %s\nFLOOR: %s\n"
                        "BASE_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\nROOMS: %s\nTYPE: %s\nMORTGAGE: %s\nRENTAL_PRICE: %s\nADDED_BY: %s\n",
                    info.address, info.building_lifespan, info.building_meterage, info.building_municipal_area, info.floor,
                    info.base_meterage, info.owner_phone_number, info.rooms, info.type, info.mortgage, info.rental_price, log_username_ptr);
            time_fwriter(fp, 1);
            fdecorator1(fp);
            fclose(fp);
            system("cls");
            printf("***- ADDED SUCCESSFULLY -***\nPress any key to continue ...");
            getch();
            system("cls");
        }
        else {
            printf("ADDING FAILED E2");
            return 0;
        }
    }
}


int land_property_fwriter(int rent_or_sell) {
    char address[100], type[20], land_meterage[20], owner_phone_number[40], land_municipal_area[10]; // similar
    char price[20]; // sell
    char mortgage[20], rental_price[20]; // rent
    int i, c;
    FILE *fp;


    system("cls");
    decorator1();
    printf("\t\t\t\t   LAND PROPERTY\n");
    decorator1();
    printf("Please Enter The Type Of The Land\n\n\n\n8) Back\n");
    decorator1();
    printf("Type :");
    scanf("%s", type);
    fflush(stdin);

    if (strcmp("back", type) == 0 || strcmp("8", type) == 0) {
        system("cls");
        return 0;
    }

    system("cls");
    decorator1();
    printf("\t\t\t\t   LAND PROPERTY\n");
    decorator1();
    printf("Please Enter The Address Of The Land\n\n\n\n\n");
    decorator1();
    printf("Address :");
    gets(address);
    strlwr(address);
    space_converter(address);

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   LAND PROPERTY\n");
        decorator1();
        printf("Please Enter The Building Municipal Area\n\n\n\n\n");
        decorator1();
        printf("Area :");
        scanf("%s", land_municipal_area);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(land_municipal_area); i++) {
            if (isdigit(land_municipal_area[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }
        break;
    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   LAND PROPERTY\n");
        decorator1();
        printf("Please Enter The Land's Meterage \n\n\n\n\n");
        decorator1();
        printf("Land Meterage :");
        scanf("%s", land_meterage);
        fflush(stdin);


        for (i = 0, c = 0; i < strlen(land_meterage); i++) {
            if (isdigit(land_meterage[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }
        break;
    }

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   LAND PROPERTY\n");
        decorator1();
        printf("Please Enter The Owner's Phone Number \n\n\n\n\n");
        decorator1();
        printf("Phone Number :");
        scanf("%s", owner_phone_number);
        fflush(stdin);

        for (i = 0, c = 0; i < strlen(owner_phone_number); i++) {
            if (isdigit(owner_phone_number[i]) == 0) {
                c += 1;
            }
        }

        if (c != 0) {
            system("cls");
            printf("You can only enter number here\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (strlen(owner_phone_number) < 10 || strlen(owner_phone_number) > 11) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if ((strlen(owner_phone_number) == 11) && (owner_phone_number[0] != '0')) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if ((strlen(owner_phone_number) == 10) && (owner_phone_number[0] == '0')) {
            printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (strlen(owner_phone_number) != 11) {
            for (i = strlen(owner_phone_number) - 1; i >= 0; i--) {
                owner_phone_number[i + 1] = owner_phone_number[i];
            }
            owner_phone_number[0] = '0';
        }


        break;
    }

    if (rent_or_sell == 2) { // sell
        while (1) {
            system("cls");
            decorator1();
            printf("\t\t\t\t   LAND PROPERTY\n");
            decorator1();
            printf("Please Enter The Property's Price\n\n\n\n\n");
            decorator1();
            printf("Price :");
            scanf("%s", price);
            fflush(stdin);

            for (i = 0, c = 0; i < strlen(price); i++) {
                if (isdigit(price[i]) == 0) {
                    c += 1;
                }
            }

            if (c != 0) {
                system("cls");
                printf("You can only enter number here\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }
            break;
        }

        struct sell_land_property {
            char address[100];
            char land_meterage[20];
            char land_municipal_area[10];
            char owner_phone_number[40];
            char type[20];
            char price[20];
        };
        struct sell_land_property info;

        strcpy(info.address, address);
        strcpy(info.land_meterage, land_meterage);
        strcpy(info.land_municipal_area, land_municipal_area);
        strcpy(info.owner_phone_number, owner_phone_number);
        strcpy(info.type, type);
        strcpy(info.price, price);

        fp = fopen("sell_land_properties.txt", "a+");

        fprintf(fp, "STATUS: ACTIVE\nADDRESS: %s\nLAND_MUNICIPAL_AREA: %s\nLAND_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\n"
                    "TYPE: %s\nPRICE: %s\nADDED_BY: %s\n",
                info.address, info.land_municipal_area,info.land_meterage, info.owner_phone_number, info.type,
                info.price, log_username_ptr);
        time_fwriter(fp, 1);
        fdecorator1(fp);
        fclose(fp);
        system("cls");
        printf("*** ADDED SUCCESSFULLY ***\nPress any key to continue ...");
        getch();
        system("cls");
    }

    else {
        if (rent_or_sell == 1) { // rent
            while (1) {
                system("cls");
                decorator1();
                printf("\t\t\t\t   LAND PROPERTY\n");
                decorator1();
                printf("Please Enter The Property Mortgage\n\n\n\n\n");
                decorator1();
                printf("Mortgage :");
                scanf("%s", mortgage);
                fflush(stdin);

                for (i = 0, c = 0; i < strlen(mortgage); i++) {
                    if (isdigit(mortgage[i]) == 0) {
                        c += 1;
                    }
                }

                if (c != 0) {
                    system("cls");
                    printf("You can only enter number here\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }
                break;
            }

            while (1) {
                system("cls");
                decorator1();
                printf("\t\t\t\t   LAND PROPERTY\n");
                decorator1();
                printf("Please Enter The Property's Rental Price\n\n\n\n\n");
                decorator1();
                printf("Rental Price :");
                scanf("%s", rental_price);
                fflush(stdin);

                for (i = 0, c = 0; i < strlen(rental_price); i++) {
                    if (isdigit(rental_price[i]) == 0) {
                        c += 1;
                    }
                }

                if (c != 0) {
                    system("cls");
                    printf("You can only enter number here\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                break;
            }

            struct rent_land_property {
                char address[100];
                char land_meterage[20];
                char owner_phone_number[40];
                char type[20];
                char rental_price[20];
                char mortgage[20];
                char land_municipal_area[10];
            };
            struct rent_land_property info;

            strcpy(info.address, address);
            strcpy(info.land_meterage, land_meterage);
            strcpy(info.owner_phone_number, owner_phone_number);
            strcpy(info.land_municipal_area, land_municipal_area);
            strcpy(info.type, type);
            strcpy(info.rental_price, rental_price);
            strcpy(info.mortgage, mortgage);

            fp = fopen("rent_land_properties.txt", "a+");

            fprintf(fp, "STATUS: ACTIVE\nADDRESS: %s\nLAND_MUNICIPAL_AREA: %s\nLAND_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\n"
                        "TYPE: %s\nRENTAL_PRICE: %s\nMORTGAGE: %s\nADDED_BY: %s\n",
                    info.address, info.land_municipal_area, info.land_meterage, info.owner_phone_number, info.type,
                    info.rental_price, info.mortgage, log_username_ptr);
            time_fwriter(fp, 1);
            fdecorator1(fp);
            fclose(fp);
            system("cls");
            printf("***- ADDED SUCCESSFULLY -***\nPress any key to continue ...");
            getch();
            system("cls");
        }
        else {
            printf("ADDING FAILED E3");
            return 0;
        }
    }
}


int searching_filter(int building_or_land) {
    int choice;

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   REPORTS\n");
        decorator1();
        printf("1) Total Value\n");
        printf("2) Number of Properties\n");
        printf("3) Search by Municipal Area\n");
        printf("4) Search by Base Meterage\n");
        printf("5) Search by Price\n");

        if (building_or_land == 1) {
            printf("6) Search by Building Lifespan\n");
        }

        if (building_or_land == 1) {
            printf("7) Search by Number of Rooms\n");
        }

        printf("\n8) Back\n");

        decorator1();
        printf("Your Choice :");
        scanf("%d", &choice);

        if (choice > 8 || choice < 1) {
            printf("WRONG INPUT!\nPress any key to continue ...");
            getch();
            continue;
        }

        break;
    }

    return choice;

}


int sell() {
    char choice [10];
    while (1) {
        decorator1();
        printf("\t\t\t\t   SELL\n");
        decorator1();
        printf("1) Residential Property\n");
        printf("2) Office Property\n");
        printf("3) Land Property\n");
        printf("\n\n8) Back\n");
        decorator1();
        printf("Your Choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);

        if (strcmp(choice, "residential") == 0 || strcmp(choice, "1") == 0) {
            residential_property_fwriter(2);
        }

        else {
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                office_property_fwriter(2);
            }

            else {
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    land_property_fwriter(2);
                }

                else {
                    if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                        system("cls");
                        return 0;
                    }

                    else {
                        printf("*** Wrong Input ***\nPress any key to continue ...");
                        getch();
                        system("cls");
                    }
                }
            }
        }
    }
}


int rent() { // this function is for give a property on rent
    char choice [10];

    while (1) {
        decorator1();
        printf("\t\t\t\t   RENT\n");
        decorator1();
        printf("1) Residential Property\n");
        printf("2) Office Property\n");
        printf("3) Land Property\n");
        printf("\n\n8) Back\n");
        decorator1();
        printf("Your Choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);

        if (strcmp(choice, "residential") == 0 || strcmp(choice, "1") == 0) {
            residential_property_fwriter(1);
            system("cls");

        }

        else {
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                office_property_fwriter(1);
                system("cls");
            }

            else {
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    land_property_fwriter(1);
                    system("cls");
                }

                else {
                    if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                        system("cls");
                        return 0;
                    }

                    else {
                        printf("*** Wrong Input ***\nPress any key to continue ...");
                        getch();
                        system("cls");
                    }
                }
            }
        }
    }
}


int sell_reports() {
    char choice[10], decorator_skip[30];
    char input_NO_rooms[10], input_municipal_area[10];
    int input_building_lifespan_max, input_base_meterage_max, input_price_max;
    int input_building_lifespan_min, input_base_meterage_min, input_price_min;
    int total_value = 0, results = 0, temp_int = 0;
    int searching_choice, loop_checker = 0, NO_properties = 0;
    FILE *fp;

    while (1) {
        decorator1();
        printf("\t\t\t\t   SELL REPORTS\n");
        decorator1();
        printf("1) Residential Property\n");
        printf("2) Office Property\n");
        printf("3) Land Property\n");
        printf("\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);


        if (strcmp(choice, "residential") == 0 || strcmp(choice, "1") == 0) { // residential
            searching_choice = searching_filter(1);
            system("cls");

            switch (searching_choice) {
                case 3:
                    decorator1();
                    printf("Enter The Municipal Area\n\n\n\n\n");
                    decorator1();
                    printf("Entered Municipal Area :");
                    scanf("%s", input_municipal_area);
                    fflush(stdin);
                    system("cls");
                    break;

                case 6:
                    decorator1();
                    printf("Enter The Building Lifespan Range\n\n\n\n\n");
                    decorator1();

                    printf("Entered Building Lifespan :");
                    scanf("%d", &input_building_lifespan_max);

                    printf("\nEntered building lifespan :");
                    scanf("%d", &input_building_lifespan_min);

                    // max and min returner
                    if (input_building_lifespan_min > input_building_lifespan_max) {
                        temp_int = input_building_lifespan_max;
                        input_building_lifespan_max = input_building_lifespan_min;
                        input_building_lifespan_min = temp_int;
                    }

                    fflush(stdin);
                    system("cls");
                    getch();
                    break;

                case 4:
                    decorator1();
                    printf("Enter The Base Meterage Range\n\n\n\n\n");
                    decorator1();
                    printf("Entered base meterage :");
                    scanf("%d", &input_base_meterage_max);

                    printf("\nEntered Base Meterage :");
                    scanf("%d", &input_base_meterage_min);

                    // max and min returner
                    if (input_base_meterage_min > input_base_meterage_max) {
                        temp_int = input_base_meterage_max;
                        input_base_meterage_max = input_base_meterage_min;
                        input_base_meterage_min = temp_int;
                    }

                    fflush(stdin);
                    system("cls");
                    break;

                case 5:
                    decorator1();
                    printf("Enter The Price Range\n\n\n\n\n");
                    decorator1();
                    printf("Entered Price :");
                    scanf("%d", &input_price_max);

                    printf("\nEntered Price :");
                    scanf("%d", &input_price_min);

                    // max and min returner
                    if (input_price_min > input_price_max) {
                        temp_int = input_price_max;
                        input_price_max = input_price_min;
                        input_price_min = temp_int;
                    }

                    system("cls");
                    break;

                case 7:
                    decorator1();
                    printf("Enter The Number of Rooms\n\n\n\n\n");
                    decorator1();
                    printf("Entered Number :");
                    scanf("%s", input_NO_rooms);
                    fflush(stdin);
                    system("cls");
                    break;

                case 8:
                    system("cls");
                    return 0;
                    break;
            }

            struct buy_residential_property {
                char status[20];
                char address[100];
                int building_lifespan;
                int building_meterage;
                char building_municipal_area[5];
                char floor[10];
                int base_meterage;
                char owner_phone_number[40];
                char rooms[10];
                char type[20];
                int price;
                char creator_username[50];
                int date[3];
                int time[2];
                struct buy_residential_property *link;
            };
            struct buy_residential_property *head = NULL, *tail = NULL, *temp = NULL;

            fp = fopen("sell_residential_properties.txt", "r");

            results = 0;
            NO_properties = 0;

            while (feof(fp) == 0) {
                temp = malloc(sizeof(struct buy_residential_property));
                fscanf(fp, "%*s %s\n", temp->status);
                fscanf(fp, "%*s %s\n", temp->address);
                space_returner(temp->address);
                fscanf(fp, "%*s %d\n", &temp->building_lifespan);
                fscanf(fp, "%*s %d\n", &temp->building_meterage);
                fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                fscanf(fp, "%*s %s\n", temp->floor);
                fscanf(fp, "%*s %d\n", &temp->base_meterage);
                fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                fscanf(fp, "%*s %s\n", temp->rooms);
                fscanf(fp, "%*s %s\n", temp->type);
                fscanf(fp, "%*s %d\n", &temp->price);
                fscanf(fp, "%*s %s\n", temp->creator_username);
                fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                       &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                fscanf(fp, "%s\n", decorator_skip);

                if (strcmp(temp->status, "ACTIVE") == 0) {
                    NO_properties += 1;
                    total_value += temp->price;
                }

                if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                    strcmp(temp->status, "ACTIVE") == 0) {
                    results += 1;
                    printf("ADDRESS : %s\n", temp->address);
                    printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                    printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                    printf("FLOOR : %s\n", temp->floor);
                    printf("BASE METERAGE : %d\n", temp->base_meterage);
                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                    printf("ROOMS : %s\n", temp->rooms);
                    printf("TYPE : %s\n", temp->type);
                    printf("PRICE : %d\n", temp->price);
                    decorator1();
                } else {
                    if (searching_choice == 6 &&
                        (temp->building_lifespan >= input_building_lifespan_min && temp->building_lifespan <= input_building_lifespan_max) &&
                        strcmp(temp->status, "ACTIVE") == 0) {
                        results += 1;
                        printf("ADDRESS : %s\n", temp->address);
                        printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                        printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                        printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                        printf("FLOOR : %s\n", temp->floor);
                        printf("BASE METERAGE : %d\n", temp->base_meterage);
                        printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                        printf("ROOMS : %s\n", temp->rooms);
                        printf("TYPE : %s\n", temp->type);
                        printf("PRICE : %d\n", temp->price);
                        decorator1();
                    } else {
                        if (searching_choice == 4 &&
                            (temp->base_meterage >= input_base_meterage_min && temp->base_meterage <= input_base_meterage_max) &&
                            strcmp(temp->status, "ACTIVE") == 0) {
                            results += 1;
                            printf("ADDRESS : %s\n", temp->address);
                            printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                            printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("FLOOR : %s\n", temp->floor);
                            printf("BASE METERAGE : %d\n", temp->base_meterage);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("ROOMS : %s\n", temp->rooms);
                            printf("TYPE : %s\n", temp->type);
                            printf("PRICE : %d\n", temp->price);
                            decorator1();
                        } else {
                            if (searching_choice == 5 &&
                                (temp->price >= input_price_min && temp->price <= input_price_max) &&
                                strcmp(temp->status, "ACTIVE") == 0) {
                                results += 1;
                                printf("ADDRESS : %s\n", temp->address);
                                printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                printf("FLOOR : %s\n", temp->floor);
                                printf("BASE METERAGE : %d\n", temp->base_meterage);
                                printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                printf("ROOMS : %s\n", temp->rooms);
                                printf("TYPE : %s\n", temp->type);
                                printf("PRICE : %d\n", temp->price);
                                decorator1();
                            } else {
                                if (searching_choice == 7 && strcmp(temp->rooms, input_NO_rooms) == 0 &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
                                    results += 1;
                                    printf("ADDRESS : %s\n", temp->address);
                                    printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                    printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                    printf("FLOOR : %s\n", temp->floor);
                                    printf("BASE METERAGE : %d\n", temp->base_meterage);
                                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                    printf("ROOMS : %s\n", temp->rooms);
                                    printf("TYPE : %s\n", temp->type);
                                    printf("PRICE : %d\n", temp->price);
                                    decorator1();
                                }

                            }
                        }
                    }
                }

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

            if (results == 0 && searching_choice > 2) {
                printf("\nNo Results Found\nPress any key to return ...");
                getch();
                system("cls");
                continue;
            }

            if (searching_choice == 2) {
                system("cls");
                decorator1();
                printf("There are %d active residential properties in the system ...\n", NO_properties);
                decorator1();
                printf("\n\n\n\n\nPress any key to continue ...");
            } else {
                if (searching_choice == 1) {
                    system("cls");
                    decorator1();
                    printf("Total value of active residential properties in the system is : %d\n", total_value);
                    decorator1();
                    printf("\n\n\n\n\nPress any key to continue ...");
                }
            }
            getch();
            system("cls");
            break;
        } else { // office
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                searching_choice = searching_filter(1);
                system("cls");

                switch (searching_choice) {
                    case 3:
                        decorator1();
                        printf("Enter The Municipal Area\n\n\n\n\n");
                        decorator1();
                        printf("Entered Municipal Area :");
                        scanf("%s", input_municipal_area);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 6:
                        decorator1();
                        printf("Enter The Building Lifespan Range\n\n\n\n\n");
                        decorator1();

                        printf("Entered Building Lifespan :");
                        scanf("%d", &input_building_lifespan_max);

                        printf("\nEntered Building Lifespan :");
                        scanf("%d", &input_building_lifespan_min);

                        // max and min returner
                        if (input_building_lifespan_min > input_building_lifespan_max) {
                            temp_int = input_building_lifespan_max;
                            input_building_lifespan_max = input_building_lifespan_min;
                            input_building_lifespan_min = temp_int;
                        }

                        fflush(stdin);
                        system("cls");
                        break;

                    case 4:
                        decorator1();
                        printf("Enter The Base Meterage Range\n\n\n\n\n");
                        decorator1();
                        printf("Entered Base Meterage :");
                        scanf("%d", &input_base_meterage_max);

                        printf("\nEntered Base Meterage :");
                        scanf("%d", &input_base_meterage_min);

                        // max and min returner
                        if (input_base_meterage_min > input_base_meterage_max) {
                            temp_int = input_base_meterage_max;
                            input_base_meterage_max = input_base_meterage_min;
                            input_base_meterage_min = temp_int;
                        }

                        fflush(stdin);
                        system("cls");
                        break;

                    case 5:
                        decorator1();
                        printf("Enter The Price Range\n\n\n\n\n");
                        decorator1();
                        printf("Entered Price :");
                        scanf("%d", &input_price_max);

                        printf("\nEntered Price :");
                        scanf("%d", &input_price_min);

                        // max and min returner
                        if (input_price_min > input_price_max) {
                            temp_int = input_price_max;
                            input_price_max = input_price_min;
                            input_price_min = temp_int;
                        }

                        system("cls");
                        break;

                    case 7:
                        decorator1();
                        printf("Enter The Number Of Rooms\n\n\n\n\n");
                        decorator1();
                        printf("Entered Number :");
                        scanf("%s", input_NO_rooms);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 8:
                        system("cls");
                        return 0;
                }

                struct buy_office_property {
                    char status[20];
                    char address[100];
                    int building_lifespan;
                    int building_meterage;
                    char building_municipal_area[5];
                    char floor[10];
                    int base_meterage;
                    char owner_phone_number[40];
                    char rooms[10];
                    char type[20];
                    int price;
                    char creator_username[50];
                    int date[3];
                    int time[2];
                    struct buy_office_property *link;
                };
                struct buy_office_property *head = NULL, *tail = NULL, *temp = NULL;

                fp = fopen("sell_office_properties.txt", "r");

                NO_properties = 0;
                results = 0;

                while (feof(fp) == 0) {
                    temp = malloc(sizeof(struct buy_office_property));

                    fscanf(fp, "%*s %s\n", temp->status);
                    fscanf(fp, "%*s %s\n", temp->address);
                    space_returner(temp->address);
                    fscanf(fp, "%*s %d\n", &temp->building_lifespan);
                    fscanf(fp, "%*s %d\n", &temp->building_meterage);
                    fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                    fscanf(fp, "%*s %s\n", temp->floor);
                    fscanf(fp, "%*s %d\n", &temp->base_meterage);
                    fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                    fscanf(fp, "%*s %s\n", temp->rooms);
                    fscanf(fp, "%*s %s\n", temp->type);
                    fscanf(fp, "%*s %d\n", &temp->price);
                    fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                           &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                    fscanf(fp, "%s\n", decorator_skip);

                    if (strcmp(temp->status, "ACTIVE") == 0) {
                        NO_properties += 1;
                        total_value += temp->price;
                    }

                    if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                        strcmp(temp->status, "ACTIVE") == 0) {
                        results += 1;
                        printf("ADDRESS : %s\n", temp->address);
                        printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                        printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                        printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                        printf("FLOOR : %s\n", temp->floor);
                        printf("BASE METERAGE : %d\n", temp->base_meterage);
                        printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                        printf("ROOMS : %s\n", temp->rooms);
                        printf("TYPE : %s\n", temp->type);
                        printf("PRICE : %d\n", temp->price);
                        decorator1();
                    } else {
                        if (searching_choice == 4 &&
                            (temp->building_lifespan >= input_building_lifespan_min && temp->building_lifespan <= input_building_lifespan_max) &&
                            strcmp(temp->status, "ACTIVE") == 0) {
                            results += 1;
                            printf("ADDRESS : %s\n", temp->address);
                            printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                            printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("FLOOR : %s\n", temp->floor);
                            printf("BASE METERAGE : %d\n", temp->base_meterage);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("ROOMS : %s\n", temp->rooms);
                            printf("TYPE : %s\n", temp->type);
                            printf("PRICE : %d\n", temp->price);
                            decorator1();
                        } else {
                            if (searching_choice == 5 &&
                                (temp->base_meterage >= input_base_meterage_min && temp->base_meterage <= input_base_meterage_max) &&
                                strcmp(temp->status, "ACTIVE") == 0) {
                                results += 1;
                                printf("ADDRESS : %s\n", temp->address);
                                printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                printf("FLOOR : %s\n", temp->floor);
                                printf("BASE METERAGE : %d\n", temp->base_meterage);
                                printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                printf("ROOMS : %s\n", temp->rooms);
                                printf("TYPE : %s\n", temp->type);
                                printf("PRICE : %d\n", temp->price);
                                decorator1();
                            } else {
                                if (searching_choice == 6 &&
                                    (temp->price >= input_price_min && temp->price <= input_price_max) &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
                                    results += 1;
                                    printf("ADDRESS : %s\n", temp->address);
                                    printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                    printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                    printf("FLOOR : %s\n", temp->floor);
                                    printf("BASE METERAGE : %d\n", temp->base_meterage);
                                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                    printf("ROOMS : %s\n", temp->rooms);
                                    printf("TYPE : %s\n", temp->type);
                                    printf("PRICE : %d\n", temp->price);
                                    decorator1();
                                } else {
                                    if (searching_choice == 7 && strcmp(temp->rooms, input_NO_rooms) == 0 &&
                                        strcmp(temp->status, "ACTIVE") == 0) {
                                        results += 1;
                                        printf("ADDRESS : %s\n", temp->address);
                                        printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                        printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                        printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                        printf("FLOOR : %s\n", temp->floor);
                                        printf("BASE METERAGE : %d\n", temp->base_meterage);
                                        printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                        printf("ROOMS : %s\n", temp->rooms);
                                        printf("TYPE : %s\n", temp->type);
                                        printf("PRICE : %d\n", temp->price);
                                        decorator1();
                                    }
                                }
                            }
                        }
                    }

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

                if (results == 0 && searching_choice > 2) {
                    printf("\nNo Results Found\nPress any key to return ...");
                    getch();
                    system("cls");
                    continue;
                }

                if (searching_choice == 2) {
                    system("cls");
                    decorator1();
                    printf("There are %d active office properties in the system ...\n", NO_properties);
                    decorator1();
                    printf("\n\n\n\n\nPress any key to continue ...");
                } else {
                    if (searching_choice == 1) {
                        system("cls");
                        decorator1();
                        printf("Total value of active office properties in the system is : %d\n", total_value);
                        decorator1();
                        printf("\n\n\n\n\nPress any key to continue ...");
                    }
                }
                getch();
                system("cls");
                break;
            } else { // land
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    searching_choice = searching_filter(2);
                    system("cls");

                    switch (searching_choice) {
                        case 3:
                            decorator1();
                            printf("Enter The Municipal Area\n\n\n\n\n");
                            decorator1();
                            printf("Entered Municipal Area :");
                            scanf("%s", input_municipal_area);
                            fflush(stdin);
                            system("cls");
                            break;

                        case 4:
                            decorator1();
                            printf("Enter The Land Meterage Range\n\n\n\n\n");
                            decorator1();
                            printf("Entered Land Meterage :");
                            scanf("%d", &input_base_meterage_max);

                            printf("\nEntered Land Meterage :");
                            scanf("%d", &input_base_meterage_min);

                            // max and min returner
                            if (input_base_meterage_min > input_base_meterage_max) {
                                temp_int = input_base_meterage_max;
                                input_base_meterage_max = input_base_meterage_min;
                                input_base_meterage_min = temp_int;
                            }

                            system("cls");
                            break;

                        case 5:
                            decorator1();
                            printf("Enter The Price Range\n\n\n\n\n");
                            decorator1();
                            printf("Entered Price :");
                            scanf("%d", &input_price_max);

                            printf("\nEntered Price :");
                            scanf("%d", &input_price_min);

                            // max and min returner
                            if (input_price_min > input_price_max) {
                                temp_int = input_price_max;
                                input_price_max = input_price_min;
                                input_price_min = temp_int;
                            }

                            system("cls");
                            break;

                        case 8:
                            system("cls");
                            return 0;
                    }

                    struct buy_land_property {
                        char status[20];
                        char address[100];
                        char building_municipal_area[5];
                        int land_meterage;
                        char owner_phone_number[40];
                        char type[20];
                        int price;
                        char creator_username[50];
                        int date[3];
                        int time[2];
                        struct buy_land_property *link;
                    };
                    struct buy_land_property *head = NULL, *tail = NULL, *temp = NULL;

                    fp = fopen("sell_land_properties.txt", "r");

                    NO_properties = 0;
                    results = 0;

                    while (feof(fp) == 0) {

                        temp = malloc(sizeof(struct buy_land_property));

                        fscanf(fp, "%*s %s\n", temp->status);
                        fscanf(fp, "%*s %s\n", temp->address);
                        space_returner(temp->address);
                        fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                        fscanf(fp, "%*s %d\n", &temp->land_meterage);
                        fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                        fscanf(fp, "%*s %s\n", temp->type);
                        fscanf(fp, "%*s %d\n", &temp->price);
                        fscanf(fp, "%*s %s\n", temp->creator_username);
                        fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                               &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                        fscanf(fp, "%s\n", decorator_skip);


                        if (strcmp(temp->status, "ACTIVE") == 0) {
                            NO_properties += 1;
                            total_value += temp->price;
                        }

                        if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                            strcmp(temp->status, "ACTIVE") == 0) {
                            results += 1;
                            printf("ADDRESS : %s\n", temp->address);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("LAND METERAGE : %d\n", temp->land_meterage);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("TYPE : %s\n", temp->type);
                            printf("PRICE : %d\n", temp->price);
                            decorator1();
                        } else {
                            if (searching_choice == 4 &&
                                (temp->land_meterage >= input_base_meterage_min && temp->land_meterage <= input_base_meterage_max) &&
                                strcmp(temp->status, "ACTIVE") == 0) {
                                results += 1;
                                printf("ADDRESS : %s\n", temp->address);
                                printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                printf("BASE METERAGE : %d\n", temp->land_meterage);
                                printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                printf("TYPE : %s\n", temp->type);
                                printf("PRICE : %d\n", temp->price);
                                decorator1();
                            } else {
                                if (searching_choice == 5 &&
                                    (temp->price >= input_price_min && temp->price <= input_price_max)&&
                                    strcmp(temp->status, "ACTIVE") == 0) {
                                    results += 1;
                                    printf("ADDRESS : %s\n", temp->address);
                                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                    printf("BASE METERAGE : %d\n", temp->land_meterage);
                                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                    printf("TYPE : %s\n", temp->type);
                                    printf("PRICE : %d\n", temp->price);
                                    decorator1();
                                }
                            }
                        }
                    }

                    if (head == NULL) {
                        head = temp;
                        head->link = NULL;
                        tail = head;
                    } else {
                        tail->link = temp;
                        tail = temp;
                        tail->link = NULL;
                    }


                    if (results == 0 && searching_choice > 2) {
                        printf("\nNo Results Found\nPress any key to return ...");
                        getch();
                        system("cls");
                        continue;
                    }

                    if (searching_choice == 2) {
                        system("cls");
                        decorator1();
                        printf("There are %d active land properties in the system ...\n", NO_properties);
                        decorator1();
                        printf("\n\n\n\n\nPress any key to continue ...");
                    } else {
                        if (searching_choice == 1) {
                            system("cls");
                            decorator1();
                            printf("Total value of active land properties in the system is : %d\n", total_value);
                            decorator1();
                            printf("\n\n\n\n\nPress any key to continue ...");
                        }
                    }
                    getch();
                    system("cls");
                    fclose(fp);
                    free(temp);
                    break;
                }

                else {
                    if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                        system("cls");
                        return 0;
                    }

                    else {
                        printf("*** Wrong Input ***\nPress any key to continue ...");
                        getch();
                        system("cls");
                    }
                }
            }
        }
    }
}


int rent_reports() {
    char choice[10], decorator_skip[30];
    char input_NO_rooms[10], input_municipal_area[10];
    int input_building_lifespan_max, input_base_meterage_max, input_mortgage_max, input_rental_price_max;
    int input_building_lifespan_min, input_base_meterage_min, input_mortgage_min, input_rental_price_min;
    int total_value = 0, results = 0, temp_int = 0;
    int searching_choice, loop_checker = 0, NO_properties = 0;
    FILE *fp;

    while (1) {
        decorator1();
        printf("\t\t\t\t   RENT REPORTS\n");
        decorator1();
        printf("1) Residential Property\n");
        printf("2) Office Property\n");
        printf("3) Land Property\n");
        printf("\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);


        if (strcmp(choice, "residential") == 0 || strcmp(choice, "1") == 0) { // residential
            searching_choice = searching_filter(1);
            system("cls");

            switch (searching_choice) {
                case 3:
                    decorator1();
                    printf("Enter The Municipal Area\n\n\n\n\n");
                    decorator1();
                    printf("Entered Municipal Area :");
                    scanf("%s", input_municipal_area);
                    fflush(stdin);
                    system("cls");
                    break;

                case 6:
                    decorator1();
                    printf("Enter The Building Lifespan Range\n\n\n\n\n");
                    decorator1();

                    printf("Entered Building Lifespan :");
                    scanf("%d", &input_building_lifespan_max);

                    printf("\nEntered Building Lifespan :");
                    scanf("%d", &input_building_lifespan_min);

                    // max and min returner
                    if (input_building_lifespan_min > input_building_lifespan_max) {
                        temp_int = input_building_lifespan_max;
                        input_building_lifespan_max = input_building_lifespan_min;
                        input_building_lifespan_min = temp_int;
                    }

                    fflush(stdin);
                    system("cls");
                    getch();
                    break;

                case 4:
                    decorator1();
                    printf("Enter The Base Meterage Range\n\n\n\n\n");
                    decorator1();
                    printf("Entered Base Meterage :");
                    scanf("%d", &input_base_meterage_max);

                    printf("\nEntered Base Meterage :");
                    scanf("%d", &input_base_meterage_min);

                    // max and min returner
                    if (input_base_meterage_min > input_base_meterage_max) {
                        temp_int = input_base_meterage_max;
                        input_base_meterage_max = input_base_meterage_min;
                        input_base_meterage_min = temp_int;
                    }

                    fflush(stdin);
                    system("cls");
                    break;

                case 5:
                    decorator1();
                    printf("Enter The Mortgage Range\n\n\n\n\n");
                    decorator1();
                    printf("Entered Mortgage :");
                    scanf("%d", &input_mortgage_max);

                    printf("\nEntered Mortgage :");
                    scanf("%d", &input_mortgage_min);

                    system("cls");

                    decorator1();
                    printf("Enter The Rental Price Range\n\n\n\n\n");
                    decorator1();
                    printf("Entered Rental Price :");
                    scanf("%d", &input_rental_price_max);

                    printf("\nEntered Rental Price :");
                    scanf("%d", &input_rental_price_min);

                    // max and min returner
                    if (input_mortgage_min > input_mortgage_max) {
                        temp_int = input_mortgage_max;
                        input_mortgage_max = input_mortgage_min;
                        input_mortgage_min = temp_int;
                    }

                    if (input_rental_price_min > input_rental_price_max) {
                        temp_int = input_rental_price_max;
                        input_rental_price_max = input_rental_price_min;
                        input_rental_price_min = temp_int;
                    }

                    system("cls");
                    break;

                case 7:
                    decorator1();
                    printf("Enter The Number of Rooms\n\n\n\n\n");
                    decorator1();
                    printf("Entered Number :");
                    scanf("%s", input_NO_rooms);
                    fflush(stdin);
                    system("cls");
                    break;

                case 8:
                    system("cls");
                    return 0;
                    break;
            }

            struct rent_residential_property {
                char status[20];
                char address[100];
                int building_lifespan;
                int building_meterage;
                char building_municipal_area[5];
                char floor[10];
                int base_meterage;
                char owner_phone_number[40];
                char rooms[10];
                char type[20];
                int rental_price;
                int mortgage;
                char creator_username[50];
                int date[3];
                int time[2];
                struct rent_residential_property *link;
            };
            struct rent_residential_property *head = NULL, *tail = NULL, *temp = NULL;

            fp = fopen("rent_residential_properties.txt", "r");

            results = 0;
            NO_properties = 0;

            while (feof(fp) == 0) {
                temp = malloc(sizeof(struct rent_residential_property));
                fscanf(fp, "%*s %s\n", temp->status);
                fscanf(fp, "%*s %s\n", temp->address);
                space_returner(temp->address);
                fscanf(fp, "%*s %d\n", &temp->building_lifespan);
                fscanf(fp, "%*s %d\n", &temp->building_meterage);
                fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                fscanf(fp, "%*s %s\n", temp->floor);
                fscanf(fp, "%*s %d\n", &temp->base_meterage);
                fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                fscanf(fp, "%*s %s\n", temp->rooms);
                fscanf(fp, "%*s %s\n", temp->type);
                fscanf(fp, "%*s %d\n", &temp->mortgage);
                fscanf(fp, "%*s %d\n", &temp->rental_price);
                fscanf(fp, "%*s %s\n", temp->creator_username);
                fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                       &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                fscanf(fp, "%s\n", decorator_skip);

                if (strcmp(temp->status, "ACTIVE") == 0) {
                    NO_properties += 1;
                    total_value += temp->mortgage;
                }

                if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                    strcmp(temp->status, "ACTIVE") == 0) {
                    results += 1;
                    printf("ADDRESS : %s\n", temp->address);
                    printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                    printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                    printf("FLOOR : %s\n", temp->floor);
                    printf("BASE METERAGE : %d\n", temp->base_meterage);
                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                    printf("ROOMS : %s\n", temp->rooms);
                    printf("TYPE : %s\n", temp->type);
                    printf("MORTGAGE : %d\n", temp->mortgage);
                    printf("RENTAL PRICE : %d\n", temp->rental_price);
                    decorator1();
                } else {
                    if (searching_choice == 6 &&
                        (temp->building_lifespan >= input_building_lifespan_min && temp->building_lifespan <= input_building_lifespan_max) &&
                        strcmp(temp->status, "ACTIVE") == 0) {
                        results += 1;
                        printf("ADDRESS : %s\n", temp->address);
                        printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                        printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                        printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                        printf("FLOOR : %s\n", temp->floor);
                        printf("BASE METERAGE : %d\n", temp->base_meterage);
                        printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                        printf("ROOMS : %s\n", temp->rooms);
                        printf("TYPE : %s\n", temp->type);
                        printf("MORTGAGE : %d\n", temp->mortgage);
                        printf("RENTAL PRICE : %d\n", temp->rental_price);
                        decorator1();
                    } else {
                        if (searching_choice == 4 &&
                            (temp->base_meterage >= input_base_meterage_min && temp->base_meterage <= input_base_meterage_max) &&
                            strcmp(temp->status, "ACTIVE") == 0) {
                            results += 1;
                            printf("ADDRESS : %s\n", temp->address);
                            printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                            printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("FLOOR : %s\n", temp->floor);
                            printf("BASE METERAGE : %d\n", temp->base_meterage);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("ROOMS : %s\n", temp->rooms);
                            printf("TYPE : %s\n", temp->type);
                            printf("MORTGAGE : %d\n", temp->mortgage);
                            printf("RENTAL PRICE : %d\n", temp->rental_price);
                            decorator1();
                        } else {
                            if (searching_choice == 5 &&
                                (temp->mortgage >= input_mortgage_min && temp->mortgage <= input_mortgage_max) &&
                                (temp->rental_price >= input_rental_price_min && temp->rental_price <= input_rental_price_max) &&
                                strcmp(temp->status, "ACTIVE") == 0) {
                                results += 1;
                                printf("ADDRESS : %s\n", temp->address);
                                printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                printf("FLOOR : %s\n", temp->floor);
                                printf("BASE METERAGE : %d\n", temp->base_meterage);
                                printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                printf("ROOMS : %s\n", temp->rooms);
                                printf("TYPE : %s\n", temp->type);
                                printf("MORTGAGE : %d\n", temp->mortgage);
                                printf("RENTAL PRICE : %d\n", temp->rental_price);
                                decorator1();
                            } else {
                                if (searching_choice == 7 && strcmp(temp->rooms, input_NO_rooms) == 0 &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
                                    results += 1;
                                    printf("ADDRESS : %s\n", temp->address);
                                    printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                    printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                    printf("FLOOR : %s\n", temp->floor);
                                    printf("BASE METERAGE : %d\n", temp->base_meterage);
                                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                    printf("ROOMS : %s\n", temp->rooms);
                                    printf("TYPE : %s\n", temp->type);
                                    printf("MORTGAGE : %d\n", temp->mortgage);
                                    printf("PRICE : %d\n", temp->rental_price);
                                    decorator1();
                                }

                            }
                        }
                    }
                }

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

            if (results == 0 && searching_choice > 2) {
                printf("\nNo Results Found\nPress any key to return ...");
                getch();
                system("cls");
                continue;
            }

            if (searching_choice == 2) {
                system("cls");
                decorator1();
                printf("There are %d active rental residential properties in the system ...\n", NO_properties);
                decorator1();
                printf("\n\n\n\n\nPress any key to continue ...");
            } else {
                if (searching_choice == 1) {
                    system("cls");
                    decorator1();
                    printf("Total value of active rental residential properties in the system is : %d (based on mortgages)\n", total_value);
                    decorator1();
                    printf("\n\n\n\n\nPress any key to continue ...");
                }
            }
            getch();
            system("cls");
            break;
        } else { // office
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                searching_choice = searching_filter(1);
                system("cls");

                switch (searching_choice) {
                    case 3:
                        decorator1();
                        printf("Enter The Municipal Area\n\n\n\n\n");
                        decorator1();
                        printf("Entered Municipal Area :");
                        scanf("%s", input_municipal_area);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 6:
                        decorator1();
                        printf("Enter The Building Lifespan Range\n\n\n\n\n");
                        decorator1();

                        printf("Entered Building Lifespan :");
                        scanf("%d", &input_building_lifespan_max);

                        printf("\nEntered Building Lifespan :");
                        scanf("%d", &input_building_lifespan_min);

                        // max and min returner
                        if (input_building_lifespan_min > input_building_lifespan_max) {
                            temp_int = input_building_lifespan_max;
                            input_building_lifespan_max = input_building_lifespan_min;
                            input_building_lifespan_min = temp_int;
                        }

                        fflush(stdin);
                        system("cls");
                        break;

                    case 4:
                        decorator1();
                        printf("Enter The Base Meterage Range\n\n\n\n\n");
                        decorator1();
                        printf("Entered Base Meterage :");
                        scanf("%d", &input_base_meterage_max);

                        printf("\nEntered Base Meterage :");
                        scanf("%d", &input_base_meterage_min);

                        // max and min returner
                        if (input_base_meterage_min > input_base_meterage_max) {
                            temp_int = input_base_meterage_max;
                            input_base_meterage_max = input_base_meterage_min;
                            input_base_meterage_min = temp_int;
                        }

                        fflush(stdin);
                        system("cls");
                        break;

                    case 5:
                        decorator1();
                        printf("Enter The Rental Price Range\n\n\n\n\n");
                        decorator1();
                        printf("Entered Rental Price :");
                        scanf("%d", &input_rental_price_max);

                        printf("\nEntered Rental Price :");
                        scanf("%d", &input_rental_price_min);

                        system("cls");
                        decorator1();
                        printf("Enter The Mortgage Range\n\n\n\n\n");
                        decorator1();
                        printf("Entered Mortgage :");
                        scanf("%d", &input_mortgage_max);

                        printf("\nEntered Mortgage :");
                        scanf("%d", &input_mortgage_min);

                        // max and min returner
                        if (input_mortgage_min > input_mortgage_max) {
                            temp_int = input_mortgage_max;
                            input_mortgage_max = input_mortgage_min;
                            input_mortgage_min = temp_int;
                        }

                        if (input_rental_price_min > input_rental_price_max) {
                            temp_int = input_rental_price_max;
                            input_rental_price_max = input_rental_price_min;
                            input_rental_price_min = temp_int;
                        }

                        system("cls");
                        break;

                    case 7:
                        decorator1();
                        printf("Enter The Number of Rooms\n\n\n\n\n");
                        decorator1();
                        printf("Entered Number :");
                        scanf("%s", input_NO_rooms);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 8:
                        system("cls");
                        return 0;
                }

                struct rent_office_property {
                    char status[20];
                    char address[100];
                    int building_lifespan;
                    int building_meterage;
                    char building_municipal_area[5];
                    char floor[10];
                    int base_meterage;
                    char owner_phone_number[40];
                    char rooms[10];
                    char type[20];
                    int mortgage;
                    int rental_price;
                    char creator_username[50];
                    int date[3];
                    int time[2];
                    struct rent_office_property *link;
                };
                struct rent_office_property *head = NULL, *tail = NULL, *temp = NULL;

                fp = fopen("rent_office_properties.txt", "r");

                NO_properties = 0;
                results = 0;

                while (feof(fp) == 0) {
                    temp = malloc(sizeof(struct rent_office_property));

                    fscanf(fp, "%*s %s\n", temp->status);
                    fscanf(fp, "%*s %s\n", temp->address);
                    space_returner(temp->address);
                    fscanf(fp, "%*s %d\n", &temp->building_lifespan);
                    fscanf(fp, "%*s %d\n", &temp->building_meterage);
                    fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                    fscanf(fp, "%*s %s\n", temp->floor);
                    fscanf(fp, "%*s %d\n", &temp->base_meterage);
                    fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                    fscanf(fp, "%*s %s\n", temp->rooms);
                    fscanf(fp, "%*s %s\n", temp->type);
                    fscanf(fp, "%*s %d\n", &temp->mortgage);
                    fscanf(fp, "%*s %d\n", &temp->rental_price);
                    fscanf(fp, "%*s %s\n", temp->creator_username);
                    fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                           &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                    fscanf(fp, "%s\n", decorator_skip);

                    if (strcmp(temp->status, "ACTIVE") == 0) {
                        NO_properties += 1;
                        total_value += temp->mortgage;
                    }

                    if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                        strcmp(temp->status, "ACTIVE") == 0) {
                        results += 1;
                        printf("ADDRESS : %s\n", temp->address);
                        printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                        printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                        printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                        printf("FLOOR : %s\n", temp->floor);
                        printf("BASE METERAGE : %d\n", temp->base_meterage);
                        printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                        printf("ROOMS : %s\n", temp->rooms);
                        printf("TYPE : %s\n", temp->type);
                        printf("MORTGAGE : %s\n", temp->type);
                        printf("RENTAL PRICE : %d\n", temp->rental_price);
                        decorator1();
                    } else {
                        if (searching_choice == 4 &&
                            (temp->building_lifespan >= input_building_lifespan_min && temp->building_lifespan <= input_building_lifespan_max) &&
                            strcmp(temp->status, "ACTIVE") == 0) {
                            results += 1;
                            printf("ADDRESS : %s\n", temp->address);
                            printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                            printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("FLOOR : %s\n", temp->floor);
                            printf("BASE METERAGE : %d\n", temp->base_meterage);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("ROOMS : %s\n", temp->rooms);
                            printf("TYPE : %s\n", temp->type);
                            printf("MORTGAGE : %d\n", temp->mortgage);
                            printf("RENTAL PRICE : %d\n", temp->rental_price);
                            decorator1();
                        } else {
                            if (searching_choice == 5 &&
                                (temp->base_meterage >= input_base_meterage_min && temp->base_meterage <= input_base_meterage_max) &&
                                strcmp(temp->status, "ACTIVE") == 0) {
                                results += 1;
                                printf("ADDRESS : %s\n", temp->address);
                                printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                printf("FLOOR : %s\n", temp->floor);
                                printf("BASE METERAGE : %d\n", temp->base_meterage);
                                printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                printf("ROOMS : %s\n", temp->rooms);
                                printf("TYPE : %s\n", temp->type);
                                printf("MORTGAGE : %d\n", temp->mortgage);
                                printf("RENTAL PRICE : %d\n", temp->rental_price);
                                decorator1();
                            } else {
                                if (searching_choice == 6 &&
                                    (temp->rental_price >= input_rental_price_min && temp->rental_price <= input_rental_price_max) &&
                                    (temp->mortgage >= input_mortgage_min && temp->mortgage <= input_mortgage_max) &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
                                    results += 1;
                                    printf("ADDRESS : %s\n", temp->address);
                                    printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                    printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                    printf("FLOOR : %s\n", temp->floor);
                                    printf("BASE METERAGE : %d\n", temp->base_meterage);
                                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                    printf("ROOMS : %s\n", temp->rooms);
                                    printf("TYPE : %s\n", temp->type);
                                    printf("MORTGAGE : %d\n", temp->mortgage);
                                    printf("RENTAL PRICE : %d\n", temp->rental_price);
                                    decorator1();
                                } else {
                                    if (searching_choice == 7 && strcmp(temp->rooms, input_NO_rooms) == 0 &&
                                        strcmp(temp->status, "ACTIVE") == 0) {
                                        results += 1;
                                        printf("ADDRESS : %s\n", temp->address);
                                        printf("BUILDING LIFESPAN : %d\n", temp->building_lifespan);
                                        printf("BUILDING METERAGE : %d\n", temp->building_meterage);
                                        printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                        printf("FLOOR : %s\n", temp->floor);
                                        printf("BASE METERAGE : %d\n", temp->base_meterage);
                                        printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                        printf("ROOMS : %s\n", temp->rooms);
                                        printf("TYPE : %s\n", temp->type);
                                        printf("MORTGAGE : %d\n", temp->mortgage);
                                        printf("RENTAL PRICE : %d\n", temp->rental_price);
                                        decorator1();
                                    }
                                }
                            }
                        }
                    }

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

                if (results == 0 && searching_choice > 2) {
                    printf("\nNo Results Found\nPress any key to return ...");
                    getch();
                    system("cls");
                    continue;
                }

                if (searching_choice == 2) {
                    system("cls");
                    decorator1();
                    printf("There are %d active rental office properties in the system ...\n", NO_properties);
                    decorator1();
                    printf("\n\n\n\n\nPress any key to continue ...");
                } else {
                    if (searching_choice == 1) {
                        system("cls");
                        decorator1();
                        printf("Total value of active rental office properties in the system is : %d (based on mortgages)\n", total_value);
                        decorator1();
                        printf("\n\n\n\n\nPress any key to continue ...");
                    }
                }
                getch();
                system("cls");
                break;
            } else { // land
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    searching_choice = searching_filter(2);
                    system("cls");

                    switch (searching_choice) {
                        case 3:
                            decorator1();
                            printf("Enter The Municipal Area\n\n\n\n\n");
                            decorator1();
                            printf("Entered Municipal Area :");
                            scanf("%s", input_municipal_area);
                            fflush(stdin);
                            system("cls");
                            break;

                        case 4:
                            decorator1();
                            printf("Enter The Land Meterage Range\n\n\n\n\n");
                            decorator1();
                            printf("Entered Land Meterage :");
                            scanf("%d", &input_base_meterage_max);

                            printf("\nEntered Land Meterage :");
                            scanf("%d", &input_base_meterage_min);

                            // max and min returner
                            if (input_base_meterage_min > input_base_meterage_max) {
                                temp_int = input_base_meterage_max;
                                input_base_meterage_max = input_base_meterage_min;
                                input_base_meterage_min = temp_int;
                            }

                            system("cls");
                            break;

                        case 5:
                            decorator1();
                            printf("Enter The Rental Price Range\n\n\n\n\n");
                            decorator1();
                            printf("Entered Rental Price :");
                            scanf("%d", &input_rental_price_max);

                            printf("\nEntered Rental Price :");
                            scanf("%d", &input_rental_price_min);

                            system("cls");

                            decorator1();
                            printf("Enter The Mortgage Range\n\n\n\n\n");
                            decorator1();
                            printf("Entered Mortgage :");
                            scanf("%d", &input_mortgage_max);

                            printf("\nEntered Mortgage :");
                            scanf("%d", &input_mortgage_min);

                            // max and min returner
                            if (input_mortgage_min > input_mortgage_max) {
                                temp_int = input_mortgage_max;
                                input_mortgage_max = input_mortgage_min;
                                input_mortgage_min = temp_int;
                            }
                            if (input_rental_price_min > input_rental_price_max) {
                                temp_int = input_rental_price_max;
                                input_rental_price_max = input_rental_price_min;
                                input_rental_price_min = temp_int;
                            }

                            system("cls");
                            break;

                        case 8:
                            system("cls");
                            return 0;
                    }

                    struct rent_land_property {
                        char status[20];
                        char address[100];
                        char building_municipal_area[5];
                        int land_meterage;
                        char owner_phone_number[40];
                        char type[20];
                        int mortgage;
                        int rental_price;
                        char creator_username[50];
                        int date[3];
                        int time[2];
                        struct rent_land_property *link;
                    };
                    struct rent_land_property *head = NULL, *tail = NULL, *temp = NULL;

                    fp = fopen("rent_land_properties.txt", "r");

                    NO_properties = 0;
                    results = 0;

                    while (feof(fp) == 0) {

                        temp = malloc(sizeof(struct rent_land_property));

                        fscanf(fp, "%*s %s\n", temp->status);
                        fscanf(fp, "%*s %s\n", temp->address);
                        space_returner(temp->address);
                        fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                        fscanf(fp, "%*s %d\n", &temp->land_meterage);
                        fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                        fscanf(fp, "%*s %d\n", &temp->rental_price);
                        fscanf(fp, "%*s %d\n", &temp->mortgage);
                        fscanf(fp, "%*s %s\n", temp->creator_username);
                        fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                               &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                        fscanf(fp, "%s\n", decorator_skip);


                        if (strcmp(temp->status, "ACTIVE") == 0) {
                            NO_properties += 1;
                            total_value += temp->mortgage;
                        }

                        if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                            strcmp(temp->status, "ACTIVE") == 0) {
                            results += 1;
                            printf("ADDRESS : %s\n", temp->address);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("LAND METERAGE : %d\n", temp->land_meterage);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("TYPE : %s\n", temp->type);
                            printf("RENTAL PRICE : %d\n", temp->rental_price);
                            printf("MORTGAGE : %d\n", temp->mortgage);
                            decorator1();
                        } else {
                            if (searching_choice == 4 &&
                                (temp->land_meterage >= input_base_meterage_min && temp->land_meterage <= input_base_meterage_max) &&
                                strcmp(temp->status, "ACTIVE") == 0) {
                                results += 1;
                                printf("ADDRESS : %s\n", temp->address);
                                printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                printf("BASE METERAGE : %d\n", temp->land_meterage);
                                printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                printf("TYPE : %s\n", temp->type);
                                printf("RENTAL PRICE : %d\n", temp->rental_price);
                                printf("MORTGAGE : %d\n", temp->mortgage);
                                decorator1();
                            } else {
                                if (searching_choice == 5 &&
                                    (temp->mortgage >= input_mortgage_min && temp->mortgage <= input_mortgage_max) &&
                                    (temp->rental_price >= input_rental_price_min && temp->rental_price <= input_rental_price_max) &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
                                    results += 1;
                                    printf("ADDRESS : %s\n", temp->address);
                                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                    printf("BASE METERAGE : %d\n", temp->land_meterage);
                                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                    printf("TYPE : %s\n", temp->type);
                                    printf("RENTAL PRICE : %d\n", temp->rental_price);
                                    printf("MORTGAGE : %d\n", temp->mortgage);
                                    decorator1();
                                }
                            }
                        }
                    }

                    if (head == NULL) {
                        head = temp;
                        head->link = NULL;
                        tail = head;
                    } else {
                        tail->link = temp;
                        tail = temp;
                        tail->link = NULL;
                    }


                    if (results == 0 && searching_choice > 2) {
                        printf("\nNo Results Found\nPress any key to return ...");
                        getch();
                        system("cls");
                        continue;
                    }

                    if (searching_choice == 2) {
                        system("cls");
                        decorator1();
                        printf("There are %d active rental land properties in the system ...\n", NO_properties);
                        decorator1();
                        printf("\n\n\n\n\nPress any key to continue ...");
                    } else {
                        if (searching_choice == 1) {
                            system("cls");
                            decorator1();
                            printf("Total value of active rental land properties in the system is : %d (based on mortgages)\n", total_value);
                            decorator1();
                            printf("\n\n\n\n\nPress any key to continue ...");
                        }
                    }
                    getch();
                    system("cls");
                    fclose(fp);
                    free(temp);
                    break;
                }

                else {
                    if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                        system("cls");
                        return 0;
                    }

                    else {
                        printf("*** Wrong Input ***\nPress any key to continue ...");
                        getch();
                        system("cls");
                    }
                }
            }
        }
    }
}


int admin_menu() {
    char choice[20];
    char userlist[100][50] = {0};



    decorator2();
    printf("\t\t\t\t   ADMIN MENU\n");
    decorator2();
    printf("\t\t\t   Please Select Your Choice\n");
    decorator2();
    printf("\n1) The MOST active user and The LEAST active user\n\n");
    printf("2) Removed Properties on a specific Time Range\n\n");
    printf("3) Show The most recent activities of users\n\n");
    printf("4) Total value of all the on sell properties\n\n");
    printf("5) Total value of all the rental properties\n\n");
    printf("6) Number of archived on sell properties\n\n");
    printf("7) Number of archived rental properties\n\n\n\n");
    printf("8) Back\n");
    decorator2();
    printf(">> Your Choice :");
    scanf("%s", choice);
    fflush(stdin);
    strlwr(choice);
    system("cls");

    if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
        return 0;
    }

    else {
        if (strcmp(choice, "1") == 0) {

        }

        else {
            if (strcmp(choice, "2") == 0) {

            }

            else {
                if (strcmp(choice, "3") == 0) {

                }

                else {
                    if (strcmp(choice, "4") == 0) {

                    }

                    else {
                        if (strcmp(choice, "5") == 0) {

                        }

                        else {
                            if (strcmp(choice, "6") == 0) {

                            }

                            if (strcmp(choice, "7") == 0) {

                            }

                        }
                    }
                }
            }
        }
    }
}


int add_item() {
    char choice[10];

    while (1) {
        decorator1();
        printf("\t\t\t\t   ADD AN ITEM\n");
        decorator1();
        printf("1) Add A Property For Sell\n");
        printf("2) Add A Property For Rent\n");
        printf("\n\n\n8) Back\n");
        decorator1();
        printf("Your Choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);
        system("cls");

        if (strcmp(choice, "sell") == 0 || strcmp(choice, "1") == 0) {
            sell();
            continue;
        }

        else {
            if (strcmp(choice, "rent") == 0 || strcmp(choice, "2") == 0) {
                rent();
                continue;
            }

            else {
                if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                    system("cls");
                    return 0;
                }

                else {
                    printf("*** Wrong Input ***\nPress any key to continue ...");
                    getch();
                    system("cls");
                }
            }
        }
    }
}


int remove_sell_property() {
    char choice[10], decorator_skip[30];
    int input_price, total_value = 0;
    int searching_choice, loop_checker = 0, input_NO_property;
    int NO_property[3] = {0}; // 1st index : all properties, 2nd : active properties, 3rd : deactive  properties
    char username[50] = "REMOVED_BY: ", date[50] = "REMOVED_ON: ", time_str[100];
    FILE *fp;

    while (1) {
        system("cls");
        decorator1();
        printf("REMOVE A PROPERTY FROM THE SELL LIST\n");
        decorator1();
        printf("1) Residential Property\n");
        printf("2) Office Property\n");
        printf("3) Land Property\n");
        printf("\n\n8) Back\n");
        decorator1();
        printf("Your Choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);


        if (strcmp(choice, "residential") == 0 || strcmp(choice, "1") == 0) { // residential
            system("cls");

            struct remove_sell_residential_property {
                char status[20];
                char address[100];
                char building_lifespan[10];
                char building_meterage[10];
                char building_municipal_area[5];
                char floor[10];
                char base_meterage[10];
                char owner_phone_number[40];
                char rooms[10];
                char type[20];
                int price;
                char creator_username[50];
                int date[3];
                int time[2];
                struct remove_sell_residential_property *link;
            };
            struct remove_sell_residential_property *head = NULL, *tail = NULL, *temp = NULL;

            fp = fopen("sell_residential_properties.txt", "r");

            NO_property[0] = 0;
            NO_property[1] = 0;
            NO_property[2] = 0;

            while (feof(fp) == 0) {
                temp = malloc(sizeof(struct remove_sell_residential_property));

                fscanf(fp, "%*s %s\n", temp->status);
                fscanf(fp, "%*s %s\n", temp->address);
                space_returner(temp->address);
                fscanf(fp, "%*s %s\n", temp->building_lifespan);
                fscanf(fp, "%*s %s\n", temp->building_meterage);
                fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                fscanf(fp, "%*s %s\n", temp->floor);
                fscanf(fp, "%*s %s\n", temp->base_meterage);
                fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                fscanf(fp, "%*s %s\n", temp->rooms);
                fscanf(fp, "%*s %s\n", temp->type);
                fscanf(fp, "%*s %d\n", &temp->price);
                fscanf(fp, "%*s %s\n", temp->creator_username);
                fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                       &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                fscanf(fp, "%s\n", decorator_skip);

                if (strcmp(temp->status, "ACTIVE") == 0) {
                    NO_property[1] += 1;
                    total_value += temp->price;
                }

                if (strcmp(temp->status, "DEACTIVE") == 0) {
                    NO_property[2] += 1;
                }

                NO_property[0] += 1;

                if (strcmp(temp->status, "ACTIVE") == 0) {
                    printf("PROPERTY NUMBER #%d\n", NO_property[0]);
                    printf("ADDRESS : %s\n", temp->address);
                    printf("BUILDING LIFESPAN : %s\n", temp->building_lifespan);
                    printf("BUILDING METERAGE : %s\n", temp->building_meterage);
                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                    printf("FLOOR : %s\n", temp->floor);
                    printf("BASE METERAGE : %s\n", temp->base_meterage);
                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                    printf("ROOMS : %s\n", temp->rooms);
                    printf("TYPE : %s\n", temp->type);
                    printf("PRICE : %d\n", temp->price);
                    decorator2();
                }

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
            fclose(fp);

            if (NO_property[1] == 0) {
                printf("\nNo Results Found\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            printf("Enter The Number of The Property You Want To Remove :");
            scanf("%d", &input_NO_property);

            if (input_NO_property <= NO_property[0] && input_NO_property > 0) {
                strcat(username, log_username_ptr);
                time_string_converter(time_str);
                strcat(date, time_str);
                file_updater("sell_residential_properties.txt", 1 + (input_NO_property - 1) * 14, "STATUS: DEACTIVE");
                file_updater("sell_residential_properties.txt", 12 + (input_NO_property - 1) * 14, username);
                file_updater("sell_residential_properties.txt", 13 + (input_NO_property - 1) * 14, date);
                system("cls");
                decorator2();
                printf("Property Removed Successfully\nPress any key to return ...\n");
                decorator2();
                getch();
                continue;
            }
            else {
                printf("WRONG INPUT!\nPress any key to return ...");
                getch();
                continue;
            }


            getch();
            system("cls");
            free(temp);
            break;

        } else { // office
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                system("cls");

                struct remove_sell_office_property {
                    char status[20];
                    char address[100];
                    char building_lifespan[10];
                    char building_meterage[10];
                    char building_municipal_area[5];
                    char floor[10];
                    char base_meterage[10];
                    char owner_phone_number[40];
                    char rooms[10];
                    char type[20];
                    int price;
                    char creator_username[50];
                    int date[3];
                    int time[2];
                    struct remove_sell_office_property *link;
                };
                struct remove_sell_office_property *head = NULL, *tail = NULL, *temp = NULL;

                fp = fopen("sell_office_properties.txt", "r");

                NO_property[0] = 0;
                NO_property[1] = 0;
                NO_property[2] = 0;

                while (feof(fp) == 0) {
                    temp = malloc(sizeof(struct remove_sell_office_property));

                    fscanf(fp, "%*s %s\n", temp->status);
                    fscanf(fp, "%*s %s\n", temp->address);
                    space_returner(temp->address);
                    fscanf(fp, "%*s %s\n", temp->building_lifespan);
                    fscanf(fp, "%*s %s\n", temp->building_meterage);
                    fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                    fscanf(fp, "%*s %s\n", temp->floor);
                    fscanf(fp, "%*s %s\n", temp->base_meterage);
                    fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                    fscanf(fp, "%*s %s\n", temp->rooms);
                    fscanf(fp, "%*s %s\n", temp->type);
                    fscanf(fp, "%*s %d\n", &temp->price);
                    fscanf(fp, "%*s %s\n", temp->creator_username);
                    fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                           &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                    fscanf(fp, "%s\n", decorator_skip);

                    if (strcmp(temp->status, "ACTIVE") == 0) {
                        NO_property[1] += 1;
                        total_value += temp->price;
                    }

                    if (strcmp(temp->status, "DEACTIVE") == 0) {
                        NO_property[2] += 1;
                    }

                    NO_property[0] += 1;

                    if (strcmp(temp->status, "ACTIVE") == 0) {
                        printf("PROPERTY NUMBER #%d\n", NO_property[0]);
                        printf("ADDRESS : %s\n", temp->address);
                        printf("BUILDING LIFESPAN : %s\n", temp->building_lifespan);
                        printf("BUILDING METERAGE : %s\n", temp->building_meterage);
                        printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                        printf("FLOOR : %s\n", temp->floor);
                        printf("BASE METERAGE : %s\n", temp->base_meterage);
                        printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                        printf("ROOMS : %s\n", temp->rooms);
                        printf("TYPE : %s\n", temp->type);
                        printf("PRICE : %d\n", temp->price);
                        decorator2();
                    }

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
                fclose(fp);

                if (NO_property[1] == 0) {
                    printf("\nNo Results Found\nPress any key to return ...");
                    getch();
                    system("cls");
                    continue;
                }

                printf("Enter The Number of The Property You Want To Remove :");
                scanf("%d", &input_NO_property);


                if (input_NO_property <= NO_property[0] && input_NO_property > 0) {
                    strcat(username, log_username_ptr);
                    time_string_converter(time_str);
                    strcat(date, time_str);
                    file_updater("sell_office_properties.txt", 1 + (input_NO_property - 1) * 14, "STATUS: DEACTIVE");
                    file_updater("sell_office_properties.txt", 12 + (input_NO_property - 1) * 14, username);
                    file_updater("sell_office_properties.txt", 13 + (input_NO_property - 1) * 14, date);
                    system("cls");
                    decorator2();
                    printf("Property Removed Successfully\nPress any key to return ...\n");
                    decorator2();
                    getch();
                    continue;
                }
                else {
                    printf("WRONG INPUT!\nPress any key to go back ...");
                    getch();
                    continue;
                }

                system("cls");
                free(temp);
                break;
            } else { // land
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    system("cls");


                    struct remove_sell_land_property {
                        char status[20];
                        char address[100];
                        char building_municipal_area[5];
                        char land_meterage[10];
                        char owner_phone_number[40];
                        char type[20];
                        int price;
                        char creator_username[50];
                        int date[3];
                        int time[2];
                        struct remove_sell_land_property *link;
                    };
                    struct remove_sell_land_property *head = NULL, *tail = NULL, *temp = NULL;

                    fp = fopen("sell_land_properties.txt", "r");

                    NO_property[0] = 0;
                    NO_property[1] = 0;
                    NO_property[2] = 0;

                    while (feof(fp) == 0) {

                        temp = malloc(sizeof(struct remove_sell_land_property));

                        fscanf(fp, "%*s %s\n", temp->status);
                        fscanf(fp, "%*s %s\n", temp->address);
                        space_returner(temp->address);
                        fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                        fscanf(fp, "%*s %s\n", temp->land_meterage);
                        fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                        fscanf(fp, "%*s %s\n", temp->type);
                        fscanf(fp, "%*s %d\n", &temp->price);
                        fscanf(fp, "%*s %s\n", temp->creator_username);
                        fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                               &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                        fscanf(fp, "%s\n", decorator_skip);

                        if (strcmp(temp->status, "ACTIVE") == 0) {
                            NO_property[1] += 1;
                            total_value += temp->price;
                        }

                        if (strcmp(temp->status, "DEACTIVE") == 0) {
                            NO_property[2] += 1;
                        }

                        NO_property[0] += 1;

                        if (strcmp(temp->status, "ACTIVE") == 0) {
                            printf("PROPERTY NUMBER #%d\n", NO_property[0]);
                            printf("ADDRESS : %s\n", temp->address);
                            printf("LAND METERAGE : %s\n", temp->land_meterage);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("TYPE : %s\n", temp->type);
                            printf("PRICE : %d\n", temp->price);
                            decorator2();
                        }

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
                    fclose(fp);

                    if (NO_property[1] == 0) {
                        printf("\nNo Results Found\nPress any key to return ...");
                        getch();
                        system("cls");
                        continue;
                    }


                    printf("Enter The Number of The Property You Want To Remove :");
                    scanf("%d", &input_NO_property);


                    if (input_NO_property <= NO_property[0] && input_NO_property > 0) {
                        strcat(username, log_username_ptr);
                        time_string_converter(time_str);
                        strcat(date, time_str);
                        file_updater("sell_land_properties.txt", 1 + (input_NO_property - 1) * 10, "STATUS: DEACTIVE");
                        file_updater("sell_land_properties.txt", 8 + (input_NO_property - 1) * 10, username);
                        file_updater("sell_land_properties.txt", 9 + (input_NO_property - 1) * 10, date);
                        system("cls");
                        decorator2();
                        printf("Property Removed Successfully\nPress any key to go back ...\n");
                        decorator2();
                        getch();
                        continue;
                    }
                    else {
                        printf("WRONG INPUT!\nPress any key to go back ...");
                        getch();
                        continue;
                    }


                    getch();
                    system("cls");
                    free(temp);
                    break;
                }

                else {
                    if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                        system("cls");
                        return 0;
                    }

                    else {
                        printf("*** WRONG INPUT ***\nPress any key to continue ...");
                        getch();
                        system("cls");
                    }
                }
            }
        }
    }
}


int remove_rent_property() {
    char choice[10], decorator_skip[30];
    int input_price, total_value = 0;
    int searching_choice, loop_checker = 0, input_NO_property;
    int NO_property[3] = {0}; // 1st index : all properties, 2nd : active properties, 3rd : deactive  properties
    char username[50], date[50], time_str[100];
    FILE *fp;

    while (1) {
        system("cls");
        decorator1();
        printf("REMOVE A PROPERTY FROM THE RENTAL PROPERTIES LIST\n");
        decorator1();
        printf("1) Residential Property\n");
        printf("2) Office Property\n");
        printf("3) Land Property\n");
        printf("\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);


        if (strcmp(choice, "residential") == 0 || strcmp(choice, "1") == 0) { // residential
            system("cls");

            struct remove_rent_residential_property {
                char status[20];
                char address[100];
                char building_lifespan[10];
                char building_meterage[10];
                char building_municipal_area[5];
                char floor[10];
                char base_meterage[10];
                char owner_phone_number[40];
                char rooms[10];
                char type[20];
                int mortgage;
                int rental_price;
                char creator_username[50];
                int date[3];
                int time[2];
                struct remove_rent_residential_property *link;
            };
            struct remove_rent_residential_property *head = NULL, *tail = NULL, *temp = NULL;

            fp = fopen("rent_residential_properties.txt", "r");

            NO_property[0] = 0;
            NO_property[1] = 0;
            NO_property[2] = 0;

            while (feof(fp) == 0) {

                temp = malloc(sizeof(struct remove_rent_residential_property));

                fscanf(fp, "%*s %s\n", temp->status);
                fscanf(fp, "%*s %s\n", temp->address);
                space_returner(temp->address);
                fscanf(fp, "%*s %s\n", temp->building_lifespan);
                fscanf(fp, "%*s %s\n", temp->building_meterage);
                fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                fscanf(fp, "%*s %s\n", temp->floor);
                fscanf(fp, "%*s %s\n", temp->base_meterage);
                fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                fscanf(fp, "%*s %s\n", temp->rooms);
                fscanf(fp, "%*s %s\n", temp->type);
                fscanf(fp, "%*s %d\n", &temp->mortgage);
                fscanf(fp, "%*s %d\n", &temp->rental_price);
                fscanf(fp, "%*s %s\n", temp->creator_username);
                fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                       &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                fscanf(fp, "%s\n", decorator_skip);

                if (strcmp(temp->status, "ACTIVE") == 0) {
                    NO_property[1] += 1;
                    total_value += temp->mortgage;
                }

                if (strcmp(temp->status, "DEACTIVE") == 0) {
                    NO_property[2] += 1;
                }

                NO_property[0] += 1;

                if (strcmp(temp->status, "ACTIVE") == 0) {
                    printf("PROPERTY NUMBER #%d\n", NO_property[0]);
                    printf("ADDRESS : %s\n", temp->address);
                    printf("BUILDING LIFESPAN : %s\n", temp->building_lifespan);
                    printf("BUILDING METERAGE : %s\n", temp->building_meterage);
                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                    printf("FLOOR : %s\n", temp->floor);
                    printf("BASE METERAGE : %s\n", temp->base_meterage);
                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                    printf("ROOMS : %s\n", temp->rooms);
                    printf("TYPE : %s\n", temp->type);
                    printf("MORTGAGE : %d\n", temp->mortgage);
                    printf("RENTAL PRICE : %d\n", temp->rental_price);
                    decorator2();
                }

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
            fclose(fp);

            if (NO_property[1] == 0) {
                printf("\nNo Results Found\nPress any key to go back ...");
                getch();
                system("cls");
                continue;
            }

            printf("Enter The Number of The Property You Want To Remove :");
            scanf("%d", &input_NO_property);


            if (input_NO_property <= NO_property[0] && input_NO_property > 0) {
                strcpy(username, "REMOVED_BY: ");
                strcpy(date, "REMOVED_ON: ");
                strcat(username, log_username_ptr);
                time_string_converter(time_str);
                strcat(date, time_str);
                file_updater("rent_residential_properties.txt", 1 + (input_NO_property - 1) * 15, "STATUS: DEACTIVE");
                file_updater("rent_residential_properties.txt", 13 + (input_NO_property - 1) * 15, username);
                file_updater("rent_residential_properties.txt", 14 + (input_NO_property - 1) * 15, date);
                system("cls");
                decorator2();
                printf("Property Removed Successfully\nPress any key to go back ...\n");
                decorator2();
                getch();
                continue;
            }
            else {
                printf("WRONG INPUT!\nPress any key to go back ...");
                getch();
                continue;
            }

            getch();
            system("cls");
            free(temp);
            break;
        } else { // office
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                system("cls");

                struct remove_rent_office_property {
                    char status[20];
                    char address[100];
                    char building_lifespan[10];
                    char building_meterage[10];
                    char building_municipal_area[5];
                    char floor[10];
                    char base_meterage[10];
                    char owner_phone_number[40];
                    char rooms[10];
                    char type[20];
                    int mortgage;
                    int rental_price;
                    char creator_username[50];
                    int date[3];
                    int time[2];
                    struct remove_rent_office_property *link;
                };
                struct remove_rent_office_property *head = NULL, *tail = NULL, *temp = NULL;

                fp = fopen("rent_office_properties.txt", "r");

                NO_property[0] = 0;
                NO_property[1] = 0;
                NO_property[2] = 0;

                while (feof(fp) == 0) {
                    temp = malloc(sizeof(struct remove_rent_office_property));

                    fscanf(fp, "%*s %s\n", temp->status);
                    fscanf(fp, "%*s %s\n", temp->address);
                    space_returner(temp->address);
                    fscanf(fp, "%*s %s\n", temp->building_lifespan);
                    fscanf(fp, "%*s %s\n", temp->building_meterage);
                    fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                    fscanf(fp, "%*s %s\n", temp->floor);
                    fscanf(fp, "%*s %s\n", temp->base_meterage);
                    fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                    fscanf(fp, "%*s %s\n", temp->rooms);
                    fscanf(fp, "%*s %s\n", temp->type);
                    fscanf(fp, "%*s %d\n", &temp->mortgage);
                    fscanf(fp, "%*s %d\n", &temp->rental_price);
                    fscanf(fp, "%*s %s\n", temp->creator_username);
                    fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                           &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                    fscanf(fp, "%s\n", decorator_skip);

                    if (strcmp(temp->status, "ACTIVE") == 0) {
                        NO_property[1] += 1;
                        total_value += temp->mortgage;
                    }

                    if (strcmp(temp->status, "DEACTIVE") == 0) {
                        NO_property[2] += 1;
                    }

                    NO_property[0] += 1;

                    if (strcmp(temp->status, "ACTIVE") == 0) {
                        printf("PROPERTY NUMBER #%d\n", NO_property[0]);
                        printf("ADDRESS : %s\n", temp->address);
                        printf("BUILDING LIFESPAN : %s\n", temp->building_lifespan);
                        printf("BUILDING METERAGE : %s\n", temp->building_meterage);
                        printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                        printf("FLOOR : %s\n", temp->floor);
                        printf("BASE METERAGE : %s\n", temp->base_meterage);
                        printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                        printf("ROOMS : %s\n", temp->rooms);
                        printf("TYPE : %s\n", temp->type);
                        printf("TYPE : %s\n", temp->type);
                        printf("MORTGAGE : %d\n", temp->mortgage);
                        printf("RENTAL PRICE : %d\n", temp->rental_price);
                        decorator2();
                    }

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
                fclose(fp);

                if (NO_property[1] == 0) {
                    printf("\nNo Results Found\nPress any key to go back ...");
                    getch();
                    system("cls");
                    continue;
                }

                printf("Enter The Number of The Property You Want To Remove :");
                scanf("%d", &input_NO_property);


                if (input_NO_property <= NO_property[0] && input_NO_property > 0) {
                    strcpy(username, "REMOVED_BY: ");
                    strcpy(date, "REMOVED_ON: ");
                    strcat(username, log_username_ptr);
                    time_string_converter(time_str);
                    strcat(date, time_str);
                    file_updater("rent_office_properties.txt", 1 + (input_NO_property - 1) * 15, "STATUS: DEACTIVE");
                    file_updater("rent_office_properties.txt", 13 + (input_NO_property - 1) * 15, username);
                    file_updater("rent_office_properties.txt", 14 + (input_NO_property - 1) * 15, date);
                    system("cls");
                    decorator2();
                    printf("Property Removed Successfully\nPress any key to go back ...\n");
                    decorator2();
                    getch();
                    continue;
                }
                else {
                    printf("Wrong input !\nPress any key to return ...");
                    getch();
                    continue;
                }

                system("cls");
                free(temp);
                break;
            } else { // land
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    system("cls");


                    struct remove_rent_land_property {
                        char status[20];
                        char address[100];
                        char building_municipal_area[5];
                        char land_meterage[10];
                        char owner_phone_number[40];
                        char type[20];
                        int mortgage;
                        int rental_price;
                        char creator_username[50];
                        int date[3];
                        int time[2];
                        struct remove_rent_land_property *link;
                    };
                    struct remove_rent_land_property *head = NULL, *tail = NULL, *temp = NULL;

                    fp = fopen("rent_land_properties.txt", "r");

                    NO_property[0] = 0;
                    NO_property[1] = 0;
                    NO_property[2] = 0;

                    while (feof(fp) == 0) {

                        temp = malloc(sizeof(struct remove_rent_land_property));

                        fscanf(fp, "%*s %s\n", temp->status);
                        fscanf(fp, "%*s %s\n", temp->address);
                        space_returner(temp->address);
                        fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                        fscanf(fp, "%*s %s\n", temp->land_meterage);
                        fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                        fscanf(fp, "%*s %s\n", temp->type);
                        fscanf(fp, "%*s %d\n", &temp->mortgage);
                        fscanf(fp, "%*s %d\n", &temp->rental_price);
                        fscanf(fp, "%*s %s\n", temp->creator_username);
                        fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                               &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
                        fscanf(fp, "%s\n", decorator_skip);

                        if (strcmp(temp->status, "ACTIVE") == 0) {
                            NO_property[1] += 1;
                            total_value += temp->mortgage;
                        }


                        if (strcmp(temp->status, "DEACTIVE") == 0) {
                            NO_property[2] += 1;
                        }

                        NO_property[0] += 1;


                        if (strcmp(temp->status, "ACTIVE") == 0) {
                            printf("PROPERTY NUMBER #%d\n", NO_property[0]);
                            printf("ADDRESS : %s\n", temp->address);
                            printf("LAND METERAGE : %s\n", temp->land_meterage);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("TYPE : %s\n", temp->type);
                            printf("MORTGAGE : %d\n", temp->mortgage);
                            printf("RENTAL PRICE : %d\n", temp->rental_price);
                            decorator2();
                        }

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
                    fclose(fp);

                    if (NO_property[1] == 0) {
                        printf("\nNo Results Found\nPress any key to go back ...");
                        getch();
                        system("cls");
                        continue;
                    }


                    printf("Enter The Number of The Property You Want To Remove :");
                    scanf("%d", &input_NO_property);


                    if (input_NO_property <= NO_property[0] && input_NO_property > 0) {
                        strcpy(username, "REMOVED_BY: ");
                        strcpy(date, "REMOVED_ON: ");
                        strcat(username, log_username_ptr);
                        time_string_converter(time_str);
                        strcat(date, time_str);
                        file_updater("rent_land_properties.txt", 1 + (input_NO_property - 1) * 11, "STATUS: DEACTIVE");
                        file_updater("rent_land_properties.txt", 9 + (input_NO_property - 1) * 11, username);
                        file_updater("rent_land_properties.txt", 10 + (input_NO_property - 1) * 11, date);
                        system("cls");
                        decorator2();
                        printf("Property Removed Successfully\nPress any key to go back ...\n");
                        decorator2();
                        getch();
                        continue;
                    }
                    else {
                        printf("WRONG INPUT!\nPress any key to go back ...");
                        getch();
                        continue;
                    }


                    getch();
                    system("cls");
                    free(temp);
                    break;
                }

                else {
                    if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                        system("cls");
                        return 0;
                    }

                    else {
                        printf("*** WRONG INPUT ***\nPress any key to continue ...");
                        getch();
                        system("cls");
                    }
                }
            }
        }
    }
}


int remove_item() {
    char choice[10];

    while (1) {
        decorator1();
        printf("\t\t\t\t   REMOVE AN ITEM\n");
        decorator1();
        printf("1) Remove An Available Property For Sell\n");
        printf("2) Remove An Available Property For Rent\n");
        printf("\n\n\n8) Back\n");
        decorator1();
        printf("Your Choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);
        system("cls");

        if (strcmp(choice, "sell") == 0 || strcmp(choice, "1") == 0) {
            remove_sell_property();
        }

        else {
            if (strcmp(choice, "rent") == 0 || strcmp(choice, "2") == 0) {
                remove_rent_property();
            }

            else {
                if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                    system("cls");
                    return 0;
                }

                else {
                    printf("*** WRONG INPUT ***\nPress any key to continue ...");
                    getch();
                    system("cls");
                }
            }
        }
    }
}


int reports() {
    char choice[10];

    while (1) {
        decorator1();
        printf("\t\t\t\t   REPORTS\n");
        decorator1();
        printf("1) Available Properties For Sell\n");
        printf("2) Available Properties For Rent\n");
        if (strcmp(log_role_ptr, "admin") == 0) {
            printf("3) ADMIN MENU\n");
        }
        printf("\n\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);
        system("cls");

        if (strcmp(choice, "sell") == 0 || strcmp(choice, "1") == 0) {
            sell_reports();
        }

        else {
            if (strcmp(choice, "rent") == 0 || strcmp(choice, "2") == 0) {
                rent_reports();
            }

            else {
                if ((strcmp(choice, "admin menu") == 0 && strcmp(log_role_ptr, "admin") == 0 ) || (strcmp(choice, "3") == 0 && strcmp(log_role_ptr, "admin") == 0)) {
                    admin_menu();
                }
                else {
                    if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                        system("cls");
                        return 0;
                    }
                    else {
                        printf("*** Wrong Input ***\nPress any key to continue ...");
                        getch();
                        system("cls");
                    }
                }



            }
        }
    }
}


int profile() {
    char choice[20], newline1[128] = {0}, newline2[128] = {0};
    char domain[5], pw_1[80], pw_2[80];
    int line, NO_user = 0;
    int i, j, z, err_count1 = 0, err_count2 = 0, err_count3 = 0;
    FILE *fp;

    while (1) {
        system("cls");
        decorator1();
        printf("\t\t\t\t   PROFILE\n");
        decorator1();
        printf("1) Change Your Name/Lastname\n");
        printf("2) Change Your Email\n");
        printf("3) Change Your Phone Number\n");
        printf("4) Change Your Password\n\n");
        printf("8) Back\n");
        decorator1();
        printf("Your choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);

        if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
            system("cls");
            return 0;
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
            int date[3];
            int time[2];
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
            fscanf(fp, "%*s %d %*c %d %*c %d %d %*c %d\n",
                   &temp->date[0], &temp->date[1], &temp->date[2], &temp->time[0], &temp->time[1]);
            fscanf(fp, "%*s\n"); // skipping decorator

            NO_user += 1;

            if (strcmp(temp->username, log_username_ptr) == 0) {
                fclose(fp);
                break;
            }

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


        if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
            continue;
        }

        else {
            if (strcmp(choice, "1") == 0) { // name-lastname changer
                line = (NO_user - 1) * 11 + 3; // this line refers to the field of name

                while (1) {
                    system("cls");
                    decorator1();
                    printf("Enter Your New Name\n\n\n\n8) Back\n");
                    decorator1();
                    printf("Entered Name :");
                    gets(temp->name);
                    strlwr(temp->name);

                    if (strcmp(temp->name, "back") == 0 || strcmp(temp->name, "8") == 0) {
                        system("cls");
                        return 0;
                    }

                    for (i = 0, err_count1 = 0; i < strlen(temp->name); i++) {
                        if (isdigit(temp->name[i]) != 0) {
                            err_count1 += 1;
                        }
                    }

                    if (err_count1 != 0) {
                        printf("Your name can not contain digits !\nPress any key to return ...");
                        continue;
                    }

                    break;
                }

                space_converter(temp->name);
                strcat(newline1, "NAME: ");
                strcat(newline1, temp->name);
                file_updater("user_info.txt", line, newline1);

                system("cls");
                decorator1();
                printf("CHANGED SUCCESSFULLY !\nPress any key to continue ...\n");
                decorator1();

                line = (NO_user - 1) * 11 + 4; // this line refers to the field of last name
                while (1) {
                    system("cls");
                    decorator1();
                    printf("Enter Your New Last Name\n\n\n\n8) return to the Profile menu\n");
                    decorator1();
                    printf("Entered Last Name :");
                    gets(temp->last_name);
                    strlwr(temp->last_name);

                    if (strcmp(temp->last_name, "return") == 0 || strcmp(temp->last_name, "8") == 0) {
                        system("cls");
                        return 0;
                    }

                    for (i = 0, err_count1 = 0; i < strlen(temp->last_name); i++) {
                        if (isdigit(temp->last_name[i]) != 0) {
                            err_count1 += 1;
                        }
                    }

                    if (err_count1 != 0) {
                        printf("Your Last Name can NOT contain digits !\nPress any key to return ...");
                        continue;
                    }

                    break;
                }

                space_converter(temp->last_name);
                strcat(newline2, "LAST_NAME: ");
                strcat(newline2, temp->last_name);
                file_updater("user_info.txt", line, newline2);
            }

            else {
                if (strcmp(choice, "2") == 0) {// email changer
                    line = (NO_user - 1) * 11 + 6;

                    while (1) {
                        system("cls");
                        decorator1();
                        printf("Enter Your New Email\n\n\n\n8) Back");
                        decorator1();
                        printf("Entered Email :");
                        gets(temp->email);
                        strlwr(temp->email);

                        if (strcmp(temp->email, "back") == 0 || strcmp(temp->email, "8") == 0) {
                            system("cls");
                            return 0;
                        }

                        //*
                        for (i = strlen(temp->email) - 1, err_count1 = 0; i >= 0; i--) { // @ finder
                            if (temp->email[i] == '@') {
                                err_count1 += 1;
                                j = i;
                            }
                        }

                        if (err_count1 == 0) { // email checker 1
                            printf("(EC1) WRONG EMAIL\nPress any key to go back ...");
                            getch();
                            system("cls");
                            continue;
                        }

                        for (i = strlen(temp->email) - 1, err_count1 = 0; i >= j; i--) {
                            if (temp->email[i] == '.') {
                                z = i;
                                err_count1 += 1;
                            }
                        }

                        if (err_count1 == 0) { // email checker 2
                            printf("(EC2) WRONG EMAIL\nPress any key to go back ...");
                            getch();
                            system("cls");
                            continue;
                        }

                        for (i = z, j = 0, err_count1 = 0; i < strlen(temp->email); i++, j++) {
                            domain[j] = temp->email[i];
                            err_count1 += 1;
                        }

                        for (i = err_count1; i <= 10; i++) {
                            domain[i] = (char) NULL;
                        }

                        if (strcmp(domain, ".net") == 0 || strcmp(domain, ".com") == 0 || strcmp(domain, ".org") == 0 ||
                            strcmp(domain, ".co") == 0 || strcmp(domain, ".uk") == 0 || strcmp(domain, ".ir") == 0) {
                        } else { // email checker 3
                            printf("(EC3) WRONG EMAIL\nPress any key to go back ...");
                            getch();
                            system("cls");
                            continue;
                        }
                    }
                    //*

                    strcat(newline1, "EMAIL: ");
                    strcat(newline1, temp->email);
                    file_updater("user_info.txt", line, newline1);
                }

                else {
                    if (strcmp(choice, "3") == 0) { // phone number changer
                        line = (NO_user - 1) * 11 + 8; // this line refers to the phone number field in the file

                        while (1) {
                            system("cls");
                            decorator1();
                            printf("Enter Your New Phone Number\n\n\n\n8) Back\n");
                            decorator1();
                            printf("Entered Phone Number :");
                            gets(temp->phone_number);
                            strlwr(temp->phone_number);

                            if (strcmp(temp->phone_number, "back") == 0 || strcmp(temp->phone_number, "8") == 0) {
                                system("cls");
                                return 0;
                            }

                            //*
                            for (i = 0, err_count3 = 0; i < strlen(temp->phone_number); i++) {
                                if (isdigit(temp->phone_number[i]) == 0) {
                                    err_count3 += 1;
                                }
                            }

                            if (err_count3 != 0) {
                                system("cls");
                                printf("You can only enter number here\nPress any key to go back ...");
                                getch();
                                system("cls");
                                continue;
                            }

                            if (strlen(temp->phone_number) < 10 || strlen(temp->phone_number) > 11) {
                                printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
                                getch();
                                system("cls");
                                continue;
                            }

                            if ((strlen(temp->phone_number) == 11) && (temp->phone_number[0] != '0')) {
                                printf("\nWRONG PHONE NUMBER !!!\nPress any key to go back ...");
                                getch();
                                system("cls");
                                continue;
                            }

                            if ((strlen(temp->phone_number) == 10) && (temp->phone_number[0] == '0')) {
                                printf("\nWRONG PHONE NUMBER !!!\nPress any key to return ...");
                                getch();
                                system("cls");
                                continue;
                            }

                            if (strlen(temp->phone_number) != 11) {
                                for (i = strlen(temp->phone_number) - 1; i >= 0; i--) {
                                    temp->phone_number[i + 1] = temp->phone_number[i];
                                }
                                temp->phone_number[0] = '0';
                            }
                            //*
                        }

                        encrypter(temp->phone_number);
                        strcat(newline1, "PHONE_NUMBER: ");
                        strcat(newline1, temp->phone_number);
                        file_updater("user_info.txt", line, newline1);
                    }

                    else {
                        if (strcmp(choice, "4") == 0) { // pw changer
                            line = (NO_user - 1) * 11 + 9; // this line refers to the file of pw in the file

                            while (1) {
                                system("cls");
                                decorator1();
                                printf("Enter Your New Password\n\n\n\n8) Back\n");
                                decorator1();
                                printf("Entered Password :");
                                gets(pw_1);

                                if (strcmp(pw_1, "8") == 0 || strcmp(pw_1, "back") == 0) {
                                    system("cls");
                                    return 0;
                                }

                                //*
                                if (strlen(pw_1) < 6) { // pw len checker
                                    printf("(P1) Your password is too short !\nPress any key to go back ...");
                                    getch();
                                    system("cls");
                                    continue;
                                }


                                for (i = 0, err_count1 = 0; i < strlen(pw_1); i++) { // pw num checker
                                    if (isdigit(pw_1[i]) == 1) {
                                        err_count1 += 1;
                                    }
                                }

                                for (i = 0, err_count2 = 0; i < strlen(pw_1); i++) { // pw special character checker
                                    if (pw_1[i] == '!' || pw_1[i] == '@' || pw_1[i] == '#' || pw_1[i] == '%' ||
                                        pw_1[i] == '^' || pw_1[i] == '&' || pw_1[i] == '*' || pw_1[i] == '(' ||
                                        pw_1[i] == ')' || pw_1[i] == '+' || pw_1[i] == '=' || pw_1[i] == '+' ||
                                        pw_1[i] == '`' || pw_1[i] == '~' || pw_1[i] == '{' || pw_1[i] == '}' ||
                                        pw_1[i] == '[' || pw_1[i] == ']' || pw_1[i] == '"' || pw_1[i] == '\''||
                                        pw_1[i] == ':' || pw_1[i] == ';' || pw_1[i] == '<' || pw_1[i] == '>' ||
                                        pw_1[i] == ',' || pw_1[i] == '.' || pw_1[i] == '?' || pw_1[i] == '/' ||
                                        pw_1[i] == '|' || pw_1[i] == '$' || pw_1[i] == '\\') {
                                        err_count2 += 1;
                                    }
                                }

                                for (i = 0, err_count3 = 0; i < strlen(pw_1); i++) { // pw alphabet checker
                                    if ((pw_1[i] >= 65 && pw_1[i] <= 90) || (pw_1[i] >= 97 && pw_1[i] <= 122)) {
                                        err_count3 += 1;
                                    }
                                }

                                if (err_count1 == 0 || err_count2 == 0 || err_count3 == 0) {
                                    printf("(P2) Your password must contain characters, numbers and special characters !\n"
                                           "Press any key to go back ...");
                                    getch();
                                    system("cls");

                                    continue;
                                }
                                system("cls");
                                decorator1();
                                printf("Please Enter Again Your Password :\n\n\n\n8) Back\n");
                                decorator1();
                                printf("Entered Password :");
                                gets(pw_2);

                                if (strcmp(pw_2, "back") == 0 || strcmp(pw_2, "8") == 0) {
                                    system("cls");
                                    return 0;
                                }

                                if (strcmp(pw_1, pw_2) != 0) {
                                    system("cls");
                                    printf("(P3) The entered passwords are not the same !\n"
                                           "Press any key to go back ...");
                                    getch();
                                    system("cls");
                                    continue;
                                }

                                break;
                                //*
                            }
                            strcpy(temp->pw, pw_1);
                            encrypter(temp->pw);
                            strcat(newline1, "PASSWORD: ");
                            strcat(newline1, temp->pw);
                            file_updater("user_info.txt", line, newline1);
                        }

                        else {
                            printf("WRONG INPUT!\nPress any key to return ...");
                            getch();
                            system("cls");
                            continue;
                        }
                    }
                }
            }
        }

        system("cls");
        fclose(fp);
        free(temp);
        printf("CHANGED SUCCESSFULLY !\nPress any key to return ...");
        getch();
        system("cls");
        break;
    }

}


int main() {
    char choice[10];
    char log_username[50], log_pw[80], log_role[20], ch;
    int loop_checker1 = 0, loop_checker2 = 0, loop_checker3 = 0, i, log_checker = 0;
    FILE *fp;

    while (1) {
        system("cls");
        printf("\t\t\t\t   WELCOME !\n");
        decorator1();
        printf("\t\t\t  Please Select Your Choice\n");
        decorator1();
        printf("1) SIGN UP\n2) SIGN IN\n\n\n9) Exit\n");

        decorator1();

        printf(">> Your Choice :");
        scanf("%s", choice);
        system("cls");

        if ((strcmp(choice, "1") == 0) || (strcmp(strlwr(choice), "sign up") == 0)) {
            sign_up();
            system("cls");
            continue;

        } else if ((strcmp(choice, "2") == 0) || (strcmp(strlwr(choice), "sign in") == 0)) {
            //*- sign in *-
            while (1) {
                decorator1();
                printf("\t\t\t\t   SIGN IN\n");
                decorator1();
                printf("Enter Your Username\n\n\n\n8) Back\n");
                decorator1();
                printf(">> Entered Username :");
                scanf("%s", log_username);
                fflush(stdin);
                strlwr(log_username);
                system("cls");
                if (strcmp(log_username, "8") == 0 || strcmp(log_username, "back") == 0) {
                    loop_checker2 += 1;
                    break;
                }

                decorator1();
                printf("\t\t\t\t   SIGN IN\n");
                decorator1();
                printf("Enter Your Password\n\n\n\n\n");
                decorator1();
                printf(">> Entered Password :");

                for (i = 0, loop_checker1 = 0; (ch = _getch()) != 13; i++) {
                    if (ch == 8) {
                        loop_checker1 += 1;
                        break;
                    }
                    log_pw[i] = ch;
                    printf("*");
                }
                log_pw[i] = '\0';
                fflush(stdin);

                if (loop_checker1 != 0) {
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
                    fscanf(fp, "%*s %*s %*s\n"); // date and time skipper
                    fscanf(fp, "%*s\n"); // decorator skipper

                    if (strcmp(temp->pw, log_pw) == 0 && strcmp(temp->username, log_username) == 0) {
                        loop_checker1 += 1;
                        strcpy(log_role, temp->role);

                        fclose(fp);
                        break;
                    }

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

                if (loop_checker1 == 0) {
                    printf("\nNo Results Found\nPress any key to return ...");
                    getch();
                    system("cls");
                    continue;
                } else {
                    system("cls");
                    decorator1();
                    printf("LOGIN SUCCESSFULLY !\nPress any key to continue ...\n");
                    decorator1();

                    // we save these addresses in order to use it globally
                    log_username_ptr = (char *) malloc(sizeof(log_username));
                    log_pw_ptr = (char *) malloc(sizeof(log_pw));
                    log_role_ptr = (char *) malloc(sizeof(log_role));
                    strcpy(log_username_ptr, log_username);
                    strcpy(log_pw_ptr, log_pw);
                    strcpy(log_role_ptr, log_role);

                    getch();
                    printf("\n\n\n\n\nPress any key to continue ...");
                    system("cls");
                    fclose(fp);
                    free(temp);
                    log_checker += 1;
                    break;
                }
            } //*- sign in *-

            if (loop_checker2 != 0) {
                continue;
            }

        } else if ((strcmp(choice, "9") == 0) || (strcmp(strlwr(choice), "exit") == 0)) {
            printf("Thanks for using <3\nGoodbye !");
            getch();
            break;

        } else {
            printf("\n*** WRONG INPUT! ***\nPress any key to continue ...");
            getch();
            system("cls");
            continue;
        }


        while (1) {
            decorator1();
            printf("\t\t\t\t   MAIN MENU\n");
            decorator1();
            printf("1) Add Item\n");
            printf("2) Remove Item\n");
            printf("3) Reports\n");
            printf("4) Profile\n\n\n\n");
            printf("8) Exit From The Account\n");
            printf("9) Exit From The Program\n");
            decorator1();

            printf(">> Your Choice :");
            scanf("%s", choice);
            fflush(stdin);
            strlwr(choice);
            system("cls");

            if (strcmp(choice, "add item") == 0 || strcmp(choice, "1") == 0) {
                add_item();

            } else {
                if (strcmp(choice, "delete item") == 0 || strcmp(choice, "2") == 0) {
                    remove_item();

                } else {
                    if (strcmp(choice, "reports") == 0 || strcmp(choice, "3") == 0) {
                        reports();

                    } else {
                        if (strcmp(choice, "profile") == 0 || strcmp(choice, "4") == 0) {
                            profile();

                        } else {
                            if (strcmp(choice, "exit") == 0 || strcmp(choice, "9") == 0) {
                                system("cls");
                                decorator1();
                                printf("Thanks for using <3\nGoodbye !\n");
                                decorator1();
                                getch();
                                return 0;

                            } else {
                                if (strcmp(choice, "back") == 0 || strcmp(choice, "8") == 0) {
                                    loop_checker3 += 1;
                                    break;
                                } else {
                                    printf("*** WRONG INPUT! ***\nPress any key to continue ...");
                                    getch();
                                    system("cls");
                                }
                            }
                        }
                    }
                }
            }
        }

        if (loop_checker3 != 0) {
            continue;
        }
        break;
    }
}
