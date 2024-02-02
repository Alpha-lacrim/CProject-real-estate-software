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


// void sign_up();


//int residential_property_freader(int renting_or_buying) {
//    FILE *fp;
//    int i,
//    if (renting_or_buying == 2) {
//        struct buying_residential_property {
//            char address[100];
//            char building_lifespan[10];
//            char building_meterage[10];
//            char building_municipal_area[5];
//            char floor[10];
//            char base_meterage[10];
//            char owner_phone_number[40];
//            char rooms[10];
//            char type[20];
//            char price[20];
//        };
//        struct buying_residential_property info;
//    }
//
//    else {
//        if (renting_or_buying == 1) {
//            struct renting_residential_property {
//                char address[100];
//                char building_lifespan[10];
//                char building_meterage[10];
//                char building_municipal_area[5];
//                char floor[10];
//                char base_meterage[10];
//                char owner_phone_number[40];
//                char rooms[10];
//                char type[20];
//                char rental_price[20];
//                char mortgage[20];
//            };
//            struct renting_residential_property info;
//        }
//    }
//}


int residential_property_fwriter(int rent_or_sell) {
    char address[100], building_lifespan[10], building_meterage[10], building_municipal_area[5]; // similar
    char floor[10], base_meterage[10], owner_phone_number[40], rooms[10], type[20]; // similar
    char price[20]; // sell
    char mortgage[20], rental_price[20]; // rent
    int i, c;
    FILE *fp;

    system("cls");
    decorator1();
    printf("RESIDENTIAL PROPERTY\n");
    decorator1();
    printf("Please enter the type of the building\n\n\n\n8) Back\n");
    decorator1();
    printf("type :");
    scanf("%s", type);
    fflush(stdin);
    strlwr(type);

    if (strcmp("back", type) == 0 || strcmp("8", type) == 0) {
        system("cls");
        return 0;
    }

    system("cls");
    decorator1();
    printf("RESIDENTIAL PROPERTY\n");
    decorator1();
    printf("Please enter the address of the apartment\n\n\n\n\n");
    decorator1();
    printf("address :");
    gets(address);
    strlwr(address);
    space_converter(address);

    while (1) {
        system("cls");
        decorator1();
        printf("RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please enter the building's lifespan\n\n\n\n\n");
        decorator1();
        printf("lifespan :");
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
        printf("RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please enter building's meterage\n\n\n\n\n");
        decorator1();
        printf("building meterage :");
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
    printf("RESIDENTIAL PROPERTY\n");
    decorator1();
    printf("Please enter the building municipal area\n\n\n\n\n");
    decorator1();
    printf("area :");
    scanf("%s", building_municipal_area);
    fflush(stdin);

    while (1) {
        system("cls");
        decorator1();
        printf("RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please enter the quantity of rooms\n\n\n\n\n");
        decorator1();
        printf("rooms :");
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
        printf("RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("What floor is the property on?\n\n\n\n\n");
        decorator1();
        printf("floor :");
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
        printf("RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please enter the base meterage\n\n\n\n\n");
        decorator1();
        printf("base meterage :");
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
        printf("RESIDENTIAL PROPERTY\n");
        decorator1();
        printf("Please enter the owner's phone number \n\n\n\n\n");
        decorator1();
        printf("phone number :");
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

        for (i = strlen(owner_phone_number) - 1; i >= 0; i--) {
            owner_phone_number[i + 1] = owner_phone_number[i];
        }
        owner_phone_number[0] = '0';

        for(i = 11; i < 40; i++) {
            owner_phone_number[i] = (char)NULL;
        }

        break;
    }

    if (rent_or_sell == 2) {
        while (1) {
            system("cls");
            decorator1();
            printf("RESIDENTIAL PROPERTY\n");
            decorator1();
            printf("Please enter the property price\n\n\n\n\n");
            decorator1();
            printf("price :");
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
                    "\nFLOOR: %s\nBASE_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\nROOMS: %s\nTYPE: %s\nPRICE: %s\n",
                info.address, info.building_lifespan, info.building_meterage, info.building_municipal_area, info.floor,
                info.base_meterage, info.owner_phone_number, info.rooms, info.type, info.price);

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
                printf("RESIDENTIAL PROPERTY\n");
                decorator1();
                printf("Please enter the property mortgage\n\n\n\n\n");
                decorator1();
                printf("mortgage :");
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
                printf("RESIDENTIAL PROPERTY\n");
                decorator1();
                printf("Please enter the property rental price\n\n\n\n\n");
                decorator1();
                printf("rental price :");
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
                        "BASE_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\nROOMS: %s\nTYPE: %s\nMORTGAGE: %s\nRENTAL_PRICE: %s\n",
                    info.address, info.building_lifespan, info.building_meterage, info.building_municipal_area, info.floor,
                    info.base_meterage, info.owner_phone_number, info.rooms, info.type, info.mortgage, info.rental_price);

            fdecorator1(fp);
            fclose(fp);
            system("cls");
            printf("***- ADDED SUCCESSFULLY -***\nPress any key to continue ...");
            getch();
            system("cls");

        }
        else {
            printf("NULL");
            return 0;
        }
    }
}


int office_property_fwriter(int rent_or_sell) {
    char address[100], building_lifespan[10], building_meterage[10], building_municipal_area[5]; // similar
    char floor[10], base_meterage[10], owner_phone_number[40], rooms[10], type[20]; // similar
    char price[20]; // sell
    char mortgage[20], rental_price[20]; // rent
    int i, c;
    FILE *fp;

    system("cls");
    decorator1();
    printf("OFFICE PROPERTY\n");
    decorator1();
    printf("Please enter the type of the building\n\n\n\n8) Back\n");
    decorator1();
    printf("type :");
    scanf("%s", type);
    fflush(stdin);
    strlwr(type);

    if (strcmp("back", type) == 0 || strcmp("8", type) == 0) {
        system("cls");
        return 0;
    }

    system("cls");
    decorator1();
    printf("OFFICE PROPERTY\n");
    decorator1();
    printf("Please enter the address of the apartment\n\n\n\n\n");
    decorator1();
    printf("address :");
    gets(address);
    strlwr(address);
    space_converter(address);

    while (1) {
        system("cls");
        decorator1();
        printf("OFFICE PROPERTY\n");
        decorator1();
        printf("Please enter the building's lifespan\n\n\n\n\n");
        decorator1();
        printf("lifespan :");
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
        printf("OFFICE PROPERTY\n");
        decorator1();
        printf("Please enter building's meterage\n\n\n\n\n");
        decorator1();
        printf("meterage :");
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
    printf("OFFICE PROPERTY\n");
    decorator1();
    printf("Please enter the building municipal area\n\n\n\n\n");
    decorator1();
    printf("area :");
    scanf("%s", building_municipal_area);
    fflush(stdin);

    while (1) {
        system("cls");
        decorator1();
        printf("OFFICE PROPERTY\n");
        decorator1();
        printf("Please enter the quantity of rooms\n\n\n\n\n");
        decorator1();
        printf("rooms :");
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
        printf("OFFICE PROPERTY\n");
        decorator1();
        printf("What floor is the property on?\n\n\n\n\n");
        decorator1();
        printf("floor :");
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
        printf("OFFICE PROPERTY\n");
        decorator1();
        printf("Please enter the base meterage\n\n\n\n\n");
        decorator1();
        printf("meterage :");
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
        printf("OFFICE PROPERTY\n");
        decorator1();
        printf("Please enter the owner's phone number \n\n\n\n\n");
        decorator1();
        printf("phone number :");
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

        for (i = strlen(owner_phone_number) - 1; i >= 0; i--) {
            owner_phone_number[i + 1] = owner_phone_number[i];
        }
        owner_phone_number[0] = '0';

        for(i = 11; i < 40; i++) {
            owner_phone_number[i] = (char)NULL;
        }

        break;
    }

    if (rent_or_sell == 2) { // sell
        while (1) {
            system("cls");
            decorator1();
            printf("OFFICE PROPERTY\n");
            decorator1();
            printf("Please enter the property price\n\n\n\n\n");
            decorator1();
            printf("price :");
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
                    "BASE_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\nROOMS: %s\nTYPE: %s\nPRICE: %s\n",
                info.address, info.building_lifespan, info.building_meterage, info.building_municipal_area, info.floor,
                info.base_meterage, info.owner_phone_number, info.rooms, info.type, info.price);

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
                printf("OFFICE PROPERTY\n");
                decorator1();
                printf("Please enter the property mortgage\n\n\n\n\n");
                decorator1();
                printf("mortgage :");
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
                printf("OFFICE PROPERTY\n");
                decorator1();
                printf("Please enter the property rental price\n\n\n\n\n");
                decorator1();
                printf("rental price :");
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
                        "BASE_METERAGE: %s\nOWNER_PHONE_NUMBER: %s\nROOMS: %s\nTYPE: %s\nMORTGAGE: %s\nRENTAL_PRICE: %s\n",
                    info.address, info.building_lifespan, info.building_meterage, info.building_municipal_area, info.floor,
                    info.base_meterage, info.owner_phone_number, info.rooms, info.type, info.mortgage, info.rental_price);

            fdecorator1(fp);
            fclose(fp);
            system("cls");
            printf("***- ADDED SUCCESSFULLY -***\nPress any key to continue ...");
            getch();
            system("cls");
        }
        else {
            printf("NULL");
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
    printf("LAND PROPERTY\n");
    decorator1();
    printf("Please enter the type of the land\n\n\n\n8) Back\n");
    decorator1();
    printf("type :");
    scanf("%s", type);
    fflush(stdin);

    if (strcmp("back", type) == 0 || strcmp("8", type) == 0) {
        system("cls");
        return 0;
    }

    system("cls");
    decorator1();
    printf("LAND PROPERTY\n");
    decorator1();
    printf("Please enter the address of the land\n\n\n\n\n");
    decorator1();
    printf("address :");
    gets(address);
    strlwr(address);
    space_converter(address);

    while (1) {
        system("cls");
        decorator1();
        printf("LAND PROPERTY\n");
        decorator1();
        printf("Please enter the building municipal area\n\n\n\n\n");
        decorator1();
        printf("area :");
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
        printf("LAND PROPERTY\n");
        decorator1();
        printf("Please enter the land's meterage \n\n\n\n\n");
        decorator1();
        printf("meterage :");
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
        printf("LAND PROPERTY\n");
        decorator1();
        printf("Please enter the owner's phone number \n\n\n\n\n");
        decorator1();
        printf("phone number :");
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

        for (i = strlen(owner_phone_number) - 1; i >= 0; i--) {
            owner_phone_number[i + 1] = owner_phone_number[i];
        }
        owner_phone_number[0] = '0';

        for(i = 11; i < 40; i++) {
            owner_phone_number[i] = (char)NULL;
        }

        break;
    }

    if (rent_or_sell == 2) { // sell
        while (1) {
            system("cls");
            decorator1();
            printf("LAND PROPERTY\n");
            decorator1();
            printf("Please enter the property price\n\n\n\n\n");
            decorator1();
            printf("price :");
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
                    "TYPE: %s\nPRICE: %s\n",
                info.address, info.land_municipal_area,info.land_meterage, info.owner_phone_number, info.type,
                info.price);

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
                printf("LAND PROPERTY\n");
                decorator1();
                printf("Please enter the property mortgage\n\n\n\n\n");
                decorator1();
                printf("mortgage :");
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
                printf("LAND PROPERTY\n");
                decorator1();
                printf("Please enter the property rental price\n\n\n\n\n");
                decorator1();
                printf("rental price :");
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
                        "TYPE: %s\nRENTAL_PRICE: %s\nMORTGAGE: %s\n",
                    info.address, info.land_municipal_area, info.land_meterage, info.owner_phone_number, info.type,
                    info.rental_price, info.mortgage);

            fdecorator1(fp);
            fclose(fp);
            system("cls");
            printf("***- ADDED SUCCESSFULLY -***\nPress any key to continue ...");
            getch();
            system("cls");
        }
        else {
            printf("NULL");
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
        printf("1) Total value\n");
        printf("2) Number of properties\n");
        printf("3) Search by municipal area\n");
        printf("4) Search by building lifespan\n");
        printf("5) Search by base meterage\n");
        printf("6) Search by price\n");
        if (building_or_land == 1) {
            printf("7) Search by number of rooms\n");
        }
        printf("\n8) Back\n");

        decorator1();
        printf("Your choice :");
        scanf("%d", &choice);
        break;
    }

    if (choice == 8) {
        return 0;
    }

    else {
        return choice;
    }
}


int sell() {
    char choice [10];
    while (1) {
        decorator1();
        printf("\t\t\t\t   SELL\n");
        decorator1();
        printf("1) Residential property\n");
        printf("2) Office property\n");
        printf("3) Land property\n");
        printf("\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
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
        printf("1) Residential property\n");
        printf("2) Office property\n");
        printf("3) Land property\n");
        printf("\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
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


int buy() {
    char choice[10], decorator_skip[30], input_municipal_area[10], input_building_lifespan[10], input_base_meterage[10];
    char input_NO_rooms[10];
    int input_price, total_value = 0;
    int searching_choice, loop_checker = 0, NO_properties = 0;
    FILE *fp;

    while (1) {
        decorator1();
        printf("\t\t\t\t   BUY\n");
        decorator1();
        printf("1) Residential property\n");
        printf("2) Office property\n");
        printf("3) Land property\n");
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
                    printf("Enter the municipal area\n\n\n\n\n");
                    decorator1();
                    printf("Entered municipal area :");
                    scanf("%s", input_municipal_area);
                    fflush(stdin);
                    system("cls");
                    break;

                case 4:
                    decorator1();
                    printf("Enter the building lifespan\n\n\n\n\n");
                    decorator1();
                    printf("Entered building lifespan :");
                    scanf("%s", input_building_lifespan);
                    fflush(stdin);
                    system("cls");
                    break;

                case 5:
                    decorator1();
                    printf("Enter the base meterage\n\n\n\n\n");
                    decorator1();
                    printf("Entered base meterage :");
                    scanf("%s", input_base_meterage);
                    fflush(stdin);
                    system("cls");
                    break;

                case 6:
                    decorator1();
                    printf("Enter the price\n\n\n\n\n");
                    decorator1();
                    printf("Entered price :");
                    scanf("%d", &input_price);
                    system("cls");
                    break;

                case 7:
                    decorator1();
                    printf("Enter the number of rooms\n\n\n\n\n");
                    decorator1();
                    printf("Entered number :");
                    scanf("%s", input_NO_rooms);
                    fflush(stdin);
                    system("cls");
                    break;
            }

            struct buy_residential_property {
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
                struct buy_residential_property *link;
            };
            struct buy_residential_property *head = NULL, *tail = NULL, *temp = NULL;

            fp = fopen("sell_residential_properties.txt", "r");

            while (feof(fp) == 0) {

                temp = malloc(sizeof(struct buy_residential_property));

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
                fscanf(fp, "%s\n", decorator_skip);

                if (strcmp(temp->status, "ACTIVE") == 0) {
                    NO_properties += 1;
                    total_value += temp->price;
                }

                if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                    strcmp(temp->status, "ACTIVE") == 0) {
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
                    decorator1();
                } else {
                    if (searching_choice == 4 && strcmp(temp->building_lifespan, input_building_lifespan) == 0 &&
                        strcmp(temp->status, "ACTIVE") == 0) {
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
                        decorator1();
                    } else {
                        if (searching_choice == 5 && strcmp(temp->base_meterage, input_base_meterage) == 0 &&
                            strcmp(temp->status, "ACTIVE") == 0) {
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
                            decorator1();
                        } else {
                            if (searching_choice == 6 && temp->price == input_price &&
                                strcmp(temp->status, "ACTIVE") == 0) {
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
                                decorator1();
                            } else {
                                if (searching_choice == 7 && strcmp(temp->rooms, input_NO_rooms) == 0 &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
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

            if (NO_properties == 0) {
                printf("\nNo results found\nPress any key to go back ...");
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
                        printf("Enter the municipal area\n\n\n\n\n");
                        decorator1();
                        printf("Entered municipal area :");
                        scanf("%s", input_municipal_area);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 4:
                        decorator1();
                        printf("Enter the building lifespan\n\n\n\n\n");
                        decorator1();
                        printf("Entered building lifespan :");
                        scanf("%s", input_building_lifespan);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 5:
                        decorator1();
                        printf("Enter the base meterage\n\n\n\n\n");
                        decorator1();
                        printf("Entered base meterage :");
                        scanf("%s", input_base_meterage);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 6:
                        decorator1();
                        printf("Enter the price\n\n\n\n\n");
                        decorator1();
                        printf("Entered price :");
                        scanf("%d", &input_price);
                        system("cls");
                        break;

                    case 7:
                        decorator1();
                        printf("Enter the number of rooms\n\n\n\n\n");
                        decorator1();
                        printf("Entered number :");
                        scanf("%s", input_NO_rooms);
                        fflush(stdin);
                        system("cls");
                        break;
                }

                struct buy_office_property {
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
                    struct buy_office_property *link;
                };
                struct buy_office_property *head = NULL, *tail = NULL, *temp = NULL;

                fp = fopen("sell_office_properties.txt", "r");

                while (feof(fp) == 0) {
                    temp = malloc(sizeof(struct buy_office_property));

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
                    fscanf(fp, "%s\n", decorator_skip);

                    if (strcmp(temp->status, "ACTIVE") == 0) {
                        NO_properties += 1;
                        total_value += temp->price;
                    }

                    if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                        strcmp(temp->status, "ACTIVE") == 0) {
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
                        decorator1();
                    } else {
                        if (searching_choice == 4 && strcmp(temp->building_lifespan, input_building_lifespan) == 0 &&
                            strcmp(temp->status, "ACTIVE") == 0) {
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
                            decorator1();
                        } else {
                            if (searching_choice == 5 && strcmp(temp->base_meterage, input_base_meterage) == 0 &&
                                strcmp(temp->status, "ACTIVE") == 0) {
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
                                decorator1();
                            } else {
                                if (searching_choice == 6 && temp->price == input_price &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
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
                                    decorator1();
                                } else {
                                    if (searching_choice == 7 && strcmp(temp->rooms, input_NO_rooms) == 0 &&
                                        strcmp(temp->status, "ACTIVE") == 0) {
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

                if (NO_properties == 0) {
                    printf("\nNo results found\nPress any key to go back ...");
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
            } else { // land
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    searching_choice = searching_filter(2);
                    system("cls");

                    switch (searching_choice) {
                        case 3:
                            decorator1();
                            printf("Enter the municipal area\n\n\n\n\n");
                            decorator1();
                            printf("Entered municipal area :");
                            scanf("%s", input_municipal_area);
                            fflush(stdin);
                            system("cls");
                            break;

                        case 4:
                            decorator1();
                            printf("Enter the building lifespan\n\n\n\n\n");
                            decorator1();
                            printf("Entered building lifespan :");
                            scanf("%s", input_building_lifespan);
                            fflush(stdin);
                            system("cls");
                            break;

                        case 5:
                            decorator1();
                            printf("Enter the base meterage\n\n\n\n\n");
                            decorator1();
                            printf("Entered base meterage :");
                            scanf("%s", input_base_meterage);
                            fflush(stdin);
                            system("cls");
                            break;

                        case 6:
                            decorator1();
                            printf("Enter the price\n\n\n\n\n");
                            decorator1();
                            printf("Entered price :");
                            scanf("%d", &input_price);
                            system("cls");
                            break;
                    }

                    struct buy_land_property {
                        char status[20];
                        char address[100];
                        char building_municipal_area[5];
                        char land_meterage[10];
                        char owner_phone_number[40];
                        char type[20];
                        int price;
                        struct buy_land_property *link;
                    };
                    struct buy_land_property *head = NULL, *tail = NULL, *temp = NULL;

                    fp = fopen("sell_land_properties.txt", "r");

                    while (feof(fp) == 0) {

                        temp = malloc(sizeof(struct buy_land_property));

                        fscanf(fp, "%*s %s\n", temp->status);
                        fscanf(fp, "%*s %s\n", temp->address);
                        space_returner(temp->address);
                        fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                        fscanf(fp, "%*s %s\n", temp->land_meterage);
                        fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                        fscanf(fp, "%*s %s\n", temp->type);
                        fscanf(fp, "%*s %d\n", &temp->price);
                        fscanf(fp, "%s\n", decorator_skip);

                        if (strcmp(temp->status, "ACTIVE") == 0) {
                            NO_properties += 1;
                            total_value += temp->price;
                        }

                        if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                            strcmp(temp->status, "ACTIVE") == 0) {
                            printf("ADDRESS : %s\n", temp->address);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("LAND METERAGE : %s\n", temp->land_meterage);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("TYPE : %s\n", temp->type);
                            printf("PRICE : %d\n", temp->price);
                            decorator1();
                        } else {
                            if (searching_choice == 5 && strcmp(temp->land_meterage, input_base_meterage) == 0 &&
                                strcmp(temp->status, "ACTIVE") == 0) {
                                printf("ADDRESS : %s\n", temp->address);
                                printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                printf("BASE METERAGE : %s\n", temp->land_meterage);
                                printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                printf("TYPE : %s\n", temp->type);
                                printf("PRICE : %d\n", temp->price);
                                decorator1();
                            } else {
                                if (searching_choice == 6 && temp->price == input_price &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
                                    printf("ADDRESS : %s\n", temp->address);
                                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                    printf("BASE METERAGE : %s\n", temp->land_meterage);
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


                    if (NO_properties == 0) {
                        printf("\nNo results found\nPress any key to go back ...");
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


int renting() { // this function is for showing available rental properties reports
    char choice[10], decorator_skip[30], input_municipal_area[10], input_building_lifespan[10], input_base_meterage[10];
    char input_NO_rooms[10];
    int input_rental_price, total_value = 0, input_mortgage;
    int searching_choice, loop_checker = 0, NO_properties = 0;
    FILE *fp;

    while (1) {
        decorator1();
        printf("\t\t\t\t   RENTING\n");
        decorator1();
        printf("1) Residential property\n");
        printf("2) Office property\n");
        printf("3) Land property\n");
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
                    printf("Enter the municipal area\n\n\n\n\n");
                    decorator1();
                    printf("Entered municipal area :");
                    scanf("%s", input_municipal_area);
                    fflush(stdin);
                    system("cls");
                    break;

                case 4:
                    decorator1();
                    printf("Enter the building lifespan\n\n\n\n\n");
                    decorator1();
                    printf("Entered building lifespan :");
                    scanf("%s", input_building_lifespan);
                    fflush(stdin);
                    system("cls");
                    break;

                case 5:
                    decorator1();
                    printf("Enter the base meterage\n\n\n\n\n");
                    decorator1();
                    printf("Entered base meterage :");
                    scanf("%s", input_base_meterage);
                    fflush(stdin);
                    system("cls");
                    break;

                case 6:
                    decorator1();
                    printf("Enter the mortgage\n\n\n\n\n");
                    decorator1();
                    printf("Entered mortgage :");
                    scanf("%d", &input_mortgage);
                    system("cls");
                    break;

                case 7:
                    decorator1();
                    printf("Enter the number of rooms\n\n\n\n\n");
                    decorator1();
                    printf("Entered number :");
                    scanf("%s", input_NO_rooms);
                    fflush(stdin);
                    system("cls");
                    break;
            }

            struct rent_residential_property {
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
                struct rent_residential_property *link;
            };
            struct rent_residential_property *head = NULL, *tail = NULL, *temp = NULL;

            fp = fopen("rent_residential_properties.txt", "r");

            while (feof(fp) == 0) {

                temp = malloc(sizeof(struct rent_residential_property));

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
                fscanf(fp, "%s\n", decorator_skip);

                if (strcmp(temp->status, "ACTIVE") == 0) {
                    NO_properties += 1;
                    total_value += temp->mortgage;
                }

                if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                    strcmp(temp->status, "ACTIVE") == 0) {
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
                    decorator1();
                } else {
                    if (searching_choice == 4 && strcmp(temp->building_lifespan, input_building_lifespan) == 0 &&
                        strcmp(temp->status, "ACTIVE") == 0) {
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
                        decorator1();
                    } else {
                        if (searching_choice == 5 && strcmp(temp->base_meterage, input_base_meterage) == 0 &&
                            strcmp(temp->status, "ACTIVE") == 0) {
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
                            decorator1();
                        } else {
                            if (searching_choice == 6 && temp->mortgage == input_mortgage &&
                                strcmp(temp->status, "ACTIVE") == 0) {
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
                                decorator1();
                            } else {
                                if (searching_choice == 7 && strcmp(temp->rooms, input_NO_rooms) == 0 &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
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

            if (NO_properties == 0) {
                printf("\nNo results found\nPress any key to go back ...");
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
                        printf("Enter the municipal area\n\n\n\n\n");
                        decorator1();
                        printf("Entered municipal area :");
                        scanf("%s", input_municipal_area);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 4:
                        decorator1();
                        printf("Enter the building lifespan\n\n\n\n\n");
                        decorator1();
                        printf("Entered building lifespan :");
                        scanf("%s", input_building_lifespan);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 5:
                        decorator1();
                        printf("Enter the base meterage\n\n\n\n\n");
                        decorator1();
                        printf("Entered base meterage :");
                        scanf("%s", input_base_meterage);
                        fflush(stdin);
                        system("cls");
                        break;

                    case 6:
                        decorator1();
                        printf("Enter the price\n\n\n\n\n");
                        decorator1();
                        printf("Entered price :");
                        scanf("%d", &input_mortgage);
                        system("cls");
                        break;

                    case 7:
                        decorator1();
                        printf("Enter the number of rooms\n\n\n\n\n");
                        decorator1();
                        printf("Entered number :");
                        scanf("%s", input_NO_rooms);
                        fflush(stdin);
                        system("cls");
                        break;
                }

                struct rent_office_property {
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
                    struct rent_office_property *link;
                };
                struct rent_office_property *head = NULL, *tail = NULL, *temp = NULL;

                fp = fopen("sell_office_properties.txt", "r");

                while (feof(fp) == 0) {
                    temp = malloc(sizeof(struct rent_office_property));

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
                    fscanf(fp, "%s\n", decorator_skip);

                    if (strcmp(temp->status, "ACTIVE") == 0) {
                        NO_properties += 1;
                        total_value += temp->mortgage;
                    }

                    if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                        strcmp(temp->status, "ACTIVE") == 0) {
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
                        decorator1();
                    } else {
                        if (searching_choice == 4 && strcmp(temp->building_lifespan, input_building_lifespan) == 0 &&
                            strcmp(temp->status, "ACTIVE") == 0) {
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
                            decorator1();
                        } else {
                            if (searching_choice == 5 && strcmp(temp->base_meterage, input_base_meterage) == 0 &&
                                strcmp(temp->status, "ACTIVE") == 0) {
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
                                decorator1();
                            } else {
                                if (searching_choice == 6 && temp->mortgage == input_mortgage &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
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
                                    decorator1();
                                } else {
                                    if (searching_choice == 7 && strcmp(temp->rooms, input_NO_rooms) == 0 &&
                                        strcmp(temp->status, "ACTIVE") == 0) {
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

                if (NO_properties == 0) {
                    printf("\nNo results found\nPress any key to go back ...");
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
            } else { // land
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    searching_choice = searching_filter(2);
                    system("cls");

                    switch (searching_choice) {
                        case 3:
                            decorator1();
                            printf("Enter the municipal area\n\n\n\n\n");
                            decorator1();
                            printf("Entered municipal area :");
                            scanf("%s", input_municipal_area);
                            fflush(stdin);
                            system("cls");
                            break;

                        case 4:
                            decorator1();
                            printf("Enter the building lifespan\n\n\n\n\n");
                            decorator1();
                            printf("Entered building lifespan :");
                            scanf("%s", input_building_lifespan);
                            fflush(stdin);
                            system("cls");
                            break;

                        case 5:
                            decorator1();
                            printf("Enter the base meterage\n\n\n\n\n");
                            decorator1();
                            printf("Entered base meterage :");
                            scanf("%s", input_base_meterage);
                            fflush(stdin);
                            system("cls");
                            break;

                        case 6:
                            decorator1();
                            printf("Enter the mortgage\n\n\n\n\n");
                            decorator1();
                            printf("Entered mortgage :");
                            scanf("%d", &input_mortgage);
                            system("cls");
                            break;
                    }

                    struct rent_land_property {
                        char status[20];
                        char address[100];
                        char building_municipal_area[5];
                        char land_meterage[10];
                        char owner_phone_number[40];
                        char type[20];
                        int mortgage;
                        int rental_price;
                        struct rent_land_property *link;
                    };
                    struct rent_land_property *head = NULL, *tail = NULL, *temp = NULL;

                    fp = fopen("rent_land_properties.txt", "r");

                    while (feof(fp) == 0) {

                        temp = malloc(sizeof(struct rent_land_property));

                        fscanf(fp, "%*s %s\n", temp->status);
                        fscanf(fp, "%*s %s\n", temp->address);
                        space_returner(temp->address);
                        fscanf(fp, "%*s %s\n", temp->building_municipal_area);
                        fscanf(fp, "%*s %s\n", temp->land_meterage);
                        fscanf(fp, "%*s %s\n", temp->owner_phone_number);
                        fscanf(fp, "%*s %s\n", temp->type);
                        fscanf(fp, "%*s %d\n", &temp->rental_price);
                        fscanf(fp, "%*s %d\n", &temp->mortgage);
                        fscanf(fp, "%s\n", decorator_skip);

                        if (strcmp(temp->status, "ACTIVE") == 0) {
                            NO_properties += 1;
                            total_value += temp->mortgage;
                        }

                        if (searching_choice == 3 && strcmp(temp->building_municipal_area, input_municipal_area) == 0 &&
                            strcmp(temp->status, "ACTIVE") == 0) {
                            printf("ADDRESS : %s\n", temp->address);
                            printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                            printf("LAND METERAGE : %s\n", temp->land_meterage);
                            printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                            printf("TYPE : %s\n", temp->type);
                            printf("MORTGAGE : %d\n", temp->mortgage);
                            printf("RENTAL PRICE : %d\n", temp->rental_price);
                            decorator1();
                        } else {
                            if (searching_choice == 5 && strcmp(temp->land_meterage, input_base_meterage) == 0 &&
                                strcmp(temp->status, "ACTIVE") == 0) {
                                printf("ADDRESS : %s\n", temp->address);
                                printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                printf("BASE METERAGE : %s\n", temp->land_meterage);
                                printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                printf("TYPE : %s\n", temp->type);
                                printf("MORTGAGE : %d\n", temp->mortgage);
                                printf("RENTAL PRICE : %d\n", temp->rental_price);
                                decorator1();
                            } else {
                                if (searching_choice == 6 && temp->mortgage == input_mortgage &&
                                    strcmp(temp->status, "ACTIVE") == 0) {
                                    printf("ADDRESS : %s\n", temp->address);
                                    printf("BUILDING MUNICIPAL AREA : %s\n", temp->building_municipal_area);
                                    printf("BASE METERAGE : %s\n", temp->land_meterage);
                                    printf("OWNER PHONE NUMBER : %s\n", temp->owner_phone_number);
                                    printf("TYPE : %s\n", temp->type);
                                    printf("MORTGAGE : %d\n", temp->mortgage);
                                    printf("RENTAL PRICE : %d\n", temp->rental_price);
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


                    if (NO_properties == 0) {
                        printf("\nNo results found\nPress any key to go back ...");
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


int add_item() {
    char choice[10];

    while (1) {
        decorator1();
        printf("\t\t\t\t   ADD ITEM\n");
        decorator1();
        printf("1) Sell a property\n");
        printf("2) Give a property on rent\n");
        printf("\n\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
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


int reports() {
    char choice[10];

    while (1) {
        decorator1();
        printf("\t\t\t\t   REPORTS\n");
        decorator1();
        printf("1) Buy a property\n");
        printf("2) Rent a property\n");
        printf("\n\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);
        system("cls");

        if (strcmp(choice, "buy") == 0 || strcmp(choice, "1") == 0) {
            buy();
        }

        else {
            if (strcmp(choice, "rent") == 0 || strcmp(choice, "2") == 0) {
                renting();
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


int main() {
    char choice[10];
    while (1) {
        decorator1();
        printf("\t\t\t\t   MAIN MENU\n");
        decorator1();
        printf("1) Add item\n");
        printf("2) Delete item\n");
        printf("3) Reports\n");
        printf("4) Profile\n\n");
        printf("8) back\n");
        decorator1();
        printf("Your choice :");

        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);
        system("cls");

        if (strcmp(choice, "add item") == 0 || strcmp(choice, "1") == 0) {
            add_item();

        }
        else {
            if (strcmp(choice, "delete item") == 0 || strcmp(choice, "2") == 0) {
                //remove_item();

            }
            else {
                if (strcmp(choice, "reports") == 0 || strcmp(choice, "3") == 0) {
                    reports();

                }
                else {
                    if (strcmp(choice, "profile") == 0 || strcmp(choice, "4") == 0) {
                        // prof

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
}
