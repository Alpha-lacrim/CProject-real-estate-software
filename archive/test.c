#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    printf("Enter a string: ");
    gets(str);
    char *word = strtok(str, " .,\n");
    char *words[100];
    int frequency[100] = {0};
    int count = 0;

    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], word) == 0) {
                frequency[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[count] = strdup(word);
            frequency[count] = 1;
            count++;
        }
        word = strtok(NULL, " .,\n");
    }

    int maxFreqIndex = 0;
    for (int i = 1; i < count; i++) {
        if (frequency[i] > frequency[maxFreqIndex]) {
            maxFreqIndex = i;
        }
    }

    printf("The word with the most frequency is: %s (appeared %d times)\n", words[maxFreqIndex], frequency[maxFreqIndex]);

    return 0;
}


//void main() {
//    char li[100][50];
//
//    char choice[20];
//    char userlist[100][50] = {0};
//    int userindex[100] = {0};
//    int NO_users = 0, i = 1, j, list_checker = 0;
//    FILE *fp_user;
//
//    struct users {
//        char role[30];
//        char username[50];
//        char name[50];
//        char last_name[100];
//        char birthdate[100];
//        char citizen_id[20];
//        char email[200];
//        char phone_number[120];
//        char pw[80];
//        char date[30];
//        char time[30];
//        struct users *link;
//    };
//    struct users *head = NULL, *tail = NULL, *temp = NULL;
//
//    fp_user = fopen("user_info.txt", "r");
//    while (feof(fp_user) == 0) {
//        list_checker = 0;
//        temp = malloc(sizeof(struct users));
//
//        fscanf(fp_user, "%*s %s\n", temp->role);
//        fscanf(fp_user, "%*s %s\n", temp->username);
//        fscanf(fp_user, "%*s %s\n", temp->name);
//        fscanf(fp_user, "%*s %s\n", temp->last_name);
//        fscanf(fp_user, "%*s %s\n", temp->citizen_id);
//        fscanf(fp_user, "%*s %s\n", temp->email);
//        fscanf(fp_user, "%*s %s\n", temp->birthdate);
//        fscanf(fp_user, "%*s %s\n", temp->phone_number);
//        fscanf(fp_user, "%*s %s\n", temp->pw);
//        fscanf(fp_user, "%*s %s %s\n", temp->date, temp->time);
//        fscanf(fp_user, "%*s\n"); // decorator skipper
//
//        if (NO_users == 0) {
//            strcpy(userlist[0], temp->username);
//        }
//
//        else {
//            for (i = 99; i >= 0; i++) {
//                if (strcmp(temp->username, userlist[i]) == 0) {
//                    list_checker += 1;
//                }
//            }
//            if (list_checker == 0) {
//                strcpy(userlist[j], temp->username);
//                j++;
//            }
//        }
//
//        NO_users++;
//
//        if (head == NULL) {
//            head = temp;
//            head->link = NULL;
//            tail = head;
//        } else {
//            tail->link = temp;
//            tail = temp;
//            tail->link = NULL;
//        }
//    }
//
//    for (i = 0; i < 100; i++) {
//        puts(userlist[i]);
//    }
//    // sa
//
//
//    if (NO_users == 0) {
//        strcpy(userlist[0], temp->username);
//    }
//
//    else {
//        for (i = 99; i >= 0; i--) {
//            if (strcmp(temp->username, userlist[i]) == 0) {
//                list_checker += 1;
//                userindex[j]++;
//            }
//        }
//        if (list_checker == 0) {
//            strcpy(userlist[j], temp->username);
//            j++;
//        }
//    }
//}