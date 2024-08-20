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

int residential_property(int rent_or_sell) {
    char address[100], building_lifespan[3], building_meterage[5], building_municipal_area[3];
    char floor[3], base_meterage[7], owner_phone_number[11], rooms[3], type[20];
    int i, c, count1;

    system("cls");
    decorator1();
    printf("RESIDENTIAL PROPERTY\n");
    decorator1();
    printf("Please enter the type of the building\n\n\n\n\n");
    decorator1();
    printf("type :");
    scanf("%s", type);
    fflush(stdin);
    strlwr(type);

    system("cls");
    decorator1();
    printf("RESIDENTIAL PROPERTY\n");
    decorator1();
    printf("Please enter the address of the apartment\n\n\n\n\n");
    decorator1();
    printf("address :");
    scanf("%s", address);
    fflush(stdin);
    strlwr(address);

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

        else {
            break;
        }
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

        if (strlen(owner_phone_number) < 10 || strlen(owner_phone_number) > 11) { // number checker 1
            printf("\nERROR (PN1): WRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (count1 == 0) {
            printf("\nERROR (PN2): WRONG PHONE NUMBER2 !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (owner_phone_number[0] != '0' &&
            strlen(owner_phone_number) == 10) { // adds 0 to the phone number if the user didn't
            for (i = 9; i >= 0; i--) {
                owner_phone_number[i + 1] = owner_phone_number[i];
            }
            owner_phone_number[0] = '0';
        }

        break;
    }

    if (rent_or_sell == 1) {
        char price[20];

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

        struct office_property {
            char address[101];
            char building_lifespan[4];
            char building_meterage[6];
            char building_municipal_area[4];
            char floor[4];
            char base_meterage[8];
            char owner_phone_number[12];
            char rooms[4];
            char type[21];
            char price[21];
        };
        struct office_property info;

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

    }

    else {
        if (rent_or_sell == 2) {
            char mortgage[20], rental_price[20];
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
            struct residential_property {
                char address[101];
                char building_lifespan[4];
                char building_meterage[6];
                char building_municipal_area[4];
                char floor[4];
                char base_meterage[8];
                char owner_phone_number[12];
                char rooms[4];
                char type[21];
                char rental_price[21];
                char mortgage[21];
            };
            struct residential_property info;

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

        }
        else {
            printf("NULL");
            return 0;
        }
    }
}


int office_property(int rent_or_sell) {
    char address[100], building_lifespan[3], building_meterage[5], building_municipal_area[3];
    char floor[3], base_meterage[7], owner_phone_number[11], rooms[3], type[20];
    int i, c, count1;

    system("cls");
    decorator1();
    printf("OFFICE PROPERTY\n");
    decorator1();
    printf("Please enter the type of the building\n\n\n\n\n");
    decorator1();
    printf("type :");
    scanf("%s", type);
    fflush(stdin);
    strlwr(type);

    system("cls");
    decorator1();
    printf("OFFICE PROPERTY\n");
    decorator1();
    printf("Please enter the address of the apartment\n\n\n\n\n");
    decorator1();
    printf("address :");
    scanf("%s", address);
    fflush(stdin);
    strlwr(address);

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

        if (strlen(owner_phone_number) < 10 || strlen(owner_phone_number) > 11) { // number checker 1
            printf("\nERROR (PN1): WRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (count1 == 0) {
            printf("\nERROR (PN2): WRONG PHONE NUMBER2 !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (owner_phone_number[0] != '0' &&
            strlen(owner_phone_number) == 10) { // adds 0 to the phone number if the user didn't
            for (i = 9; i >= 0; i--) {
                owner_phone_number[i + 1] = owner_phone_number[i];
            }
            owner_phone_number[0] = '0';
        }

        break;
    }

    if (rent_or_sell == 1) { // sell
        char price[20];

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
            struct office_property {
                char address[101];
                char building_lifespan[4];
                char building_meterage[6];
                char building_municipal_area[4];
                char floor[4];
                char base_meterage[8];
                char owner_phone_number[12];
                char rooms[4];
                char type[21];
                char price[21];
            };
            struct office_property info;

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

    }

    else {
        if (rent_or_sell == 2) { // rent
            char mortgage[20], rental_price[20];
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

            struct office_property {
                char address[101];
                char building_lifespan[4];
                char building_meterage[6];
                char building_municipal_area[4];
                char floor[4];
                char base_meterage[8];
                char owner_phone_number[12];
                char rooms[4];
                char type[21];
                char rental_price[21];
                char mortgage[21];
            };
            struct office_property info;

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

        }
        else {
            printf("NULL");
            return 0;
        }
    }
}

int land_property(int rent_or_sell) {
    char address[100], type[20], land_meterage[10], owner_phone_number[14], land_municipal_area[4];
    int i, c, count1;

    system("cls");
    decorator1();
    printf("LAND PROPERTY\n");
    decorator1();
    printf("Please enter the address of the land\n\n\n\n\n");
    decorator1();
    printf("address :");
    scanf("%s", address);
    fflush(stdin);

    system("cls");
    decorator1();
    printf("LAND PROPERTY\n");
    decorator1();
    printf("Please enter the type of the land\n\n\n\n\n");
    decorator1();
    printf("type :");
    scanf("%s", type);
    fflush(stdin);

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

    system("cls");
    decorator1();
    printf("LAND PROPERTY\n");
    decorator1();
    printf("Please enter the building municipal area\n\n\n\n\n");
    decorator1();
    printf("area :");
    scanf("%s", land_municipal_area);
    fflush(stdin);

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

        if (strlen(owner_phone_number) < 10 || strlen(owner_phone_number) > 11) { // number checker 1
            printf("\nERROR (PN1): WRONG PHONE NUMBER !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (count1 == 0) {
            printf("\nERROR (PN2): WRONG PHONE NUMBER2 !!!\nPress any key to go back ...");
            getch();
            system("cls");
            continue;
        }

        if (owner_phone_number[0] != '0' &&
            strlen(owner_phone_number) == 10) { // adds 0 to the phone number if the user didn't
            for (i = 9; i >= 0; i--) {
                owner_phone_number[i + 1] = owner_phone_number[i];
            }
            owner_phone_number[0] = '0';
        }

        break;
    }

    if (rent_or_sell == 1) {
        char price[20];

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

        struct land_property {
            char address[101];
            char land_meterage[8];
            char land_municipal_area[3];
            char owner_phone_number[12];
            char type[21];
            char price[21];
        };
        struct land_property info;

        strcpy(info.address, address);
        strcpy(info.land_meterage, land_meterage);
        strcpy(info.land_municipal_area, land_municipal_area);
        strcpy(info.owner_phone_number, owner_phone_number);
        strcpy(info.type, type);
        strcpy(info.price, price);
    }

    else {
        if (rent_or_sell == 2) {
            char mortgage[20], rental_price[20];
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

                else {
                    break;
                }
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

            struct land_property {
                char address[101];
                char land_meterage[8];
                char owner_phone_number[12];
                char type[21];
                char rental_price[21];
                char mortgage[21];
                char land_municipal_area[3];
            };
            struct land_property info;

            strcpy(info.address, address);
            strcpy(info.land_meterage, land_meterage);
            strcpy(info.owner_phone_number, owner_phone_number);
            strcpy(info.land_municipal_area, land_municipal_area);
            strcpy(info.type, type);
            strcpy(info.rental_price, rental_price);
            strcpy(info.mortgage, mortgage);

        }
        else {
            printf("NULL");
            return 0;
        }
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
            residential_property(2);
        }

        else {
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                office_property(2);
            }

            else {
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    land_property(2);
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


int rent() {
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
            residential_property(1);
        }

        else {
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                office_property(1);
            }

            else {
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    land_property(1);
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
    char choice [10];
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

        if (strcmp(choice, "residential") == 0 || strcmp(choice, "1") == 0) {
            //residential_property();
        }

        else {
            if (strcmp(choice, "office") == 0 || strcmp(choice, "2") == 0) {
                //office_property();
            }

            else {
                if (strcmp(choice, "land") == 0 || strcmp(choice, "3") == 0) {
                    //land_property();
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
        printf("2) Rent a property\n");
        printf("\n\n\n8) Back\n");
        decorator1();
        printf("Your choice :");
        scanf("%s", choice);
        fflush(stdin);
        strlwr(choice);
        system("cls");

        if (strcmp(choice, "sell") == 0 || strcmp(choice, "1") == 0) {
            sell();
            // result
            continue;
        }

        else {
            if (strcmp(choice, "rent") == 0 || strcmp(choice, "2") == 0) {
                rent();
                // result
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
                rent();
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
