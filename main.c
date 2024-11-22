#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef struct {
    char UID[20];
    char name[50];
    char roomNumber[10];
    char licensePlate[50];
} Member;

void addMember(const char* filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Khong the mo file!!!");
        return;
    }

    Member member;

    printf("Nhap UID: ");
    scanf("%s", member.UID);
    printf("Nhap ten: ");
    scanf("%[^\n]", member.name);
    printf("Nhap so phong: ");
    scanf("%s", member.roomNumber);
    printf("Nhap bien so xe: ");
    scanf("%s", member.licensePlate);
    
    fprintf(file, "%s,%s,%s,%s\n", member.UID, member.name, member.roomNumber, member.licensePlate);

    fclose(file);
    printf("Da them cu dan thanh cong!\n");
    Sleep(1000);
    system("cls");
}

void deleteMember(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    Member member[100];
    int count = 0;
    char idToDelete[20];

    printf("Nhap ID cu dan can xoa: ");
    scanf("%s", idToDelete);

    while (fscanf(file, "%19[^,],%49[^,],%9[^,],%49[^\n]\n", member[count].UID, member[count].name, member[count].roomNumber, member[count].licensePlate) != EOF) {
        count++;
    }
    fclose(file);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    int deleted = 0;
    for (int i = 0; i < count; i++) {
        int result = strcmp(member[i].UID, idToDelete);
        if (result != 0) {
            fprintf(file, "%s,%s,%s,%s\n", member[i].UID, member[i].name, member[i].roomNumber, member[i].licensePlate);
        } else {
            deleted = 1;
        }
    }
    fclose(file);

    if (deleted) {
        printf("Da xoa cu dan voi ID %s thanh cong!\n", idToDelete);
    } else {
        printf("Khong tim thay cu dan voi ID %s.\n", idToDelete);
    }
    Sleep(1000);
    system("cls");
}

void editMember(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    Member member[100];
    int count = 0;
    char idToEdit[20];

    printf("Nhap ID cu dan can thay doi: ");
    scanf("%s", idToEdit);

    while (fscanf(file, "%19[^,],%49[^,],%9[^,],%49[^\n]\n", member[count].UID, member[count].name, member[count].roomNumber, member[count].licensePlate) != EOF) {
        count++;
    }
    fclose(file);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    int edited = 0;
    for (int i = 0; i < count; i++) {
        int result = strcmp(member[i].UID, idToEdit);
        if (result != 0) {
            fprintf(file, "%s,%s,%s,%s\n", member[i].UID, member[i].name, member[i].roomNumber, member[i].licensePlate);
        } else {
            printf("Nhap ten: ");
            scanf(" %[^\n]", member[i].name);
            printf("Nhap so phong: ");
            scanf("%s", member[i].roomNumber);
            printf("Nhap bien so xe: ");
            scanf("%s", member[i].licensePlate);
    
            fprintf(file, "%s,%s,%s,%s\n", member[i].UID, member[i].name, member[i].roomNumber, member[i].licensePlate);
            edited = 1;
        }
    }
    fclose(file);

    if (edited) {
        printf("Da cap nhat thong tin cu dan voi ID %s thanh cong!\n", idToEdit);
    } else {
        printf("Khong tim thay cu dan voi ID %s.\n", idToEdit);
    }
    Sleep(1000);
    system("cls");
}

void searchByUID(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    Member member[100];
    int count = 0;
    char idToDisplay[20];

    printf("Nhap ID cu dan can hien thi thong tin: ");
    scanf("%s", idToDisplay);

    while (fscanf(file, "%19[^,],%49[^,],%9[^,],%49[^\n]\n", member[count].UID, member[count].name, member[count].roomNumber, member[count].licensePlate) != EOF) {
        count++;
    }
    fclose(file);

    int display = 0;
    for (int i = 0; i < count; i++) {
        int result = strcmp(member[i].UID, idToDisplay);
        if (result == 0) {
            printf("ID: %s, Ten: %s, So phong: %s, Bien so xe: %s\n", member[i].UID, member[i].name, member[i].roomNumber, member[i].licensePlate);
            getch();
            display = 1;
        }
    }

    fclose(file);

    if (display == 0) {
        printf("Khong tim thay cu dan voi ID %s", idToDisplay);
    }
    Sleep(1000);
    system("cls");
}

void searchByPlate(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }

    Member member[100];
    int count = 0;
    char plateToDisplay[20];

    printf("Nhap bien so xe cu dan can hien thi thong tin: ");
    scanf("%s", plateToDisplay);

    while (fscanf(file, "%19[^,],%49[^,],%9[^,],%49[^\n]\n", member[count].UID, member[count].name, member[count].roomNumber, member[count].licensePlate) != EOF) {
        count++;
    }
    fclose(file);

    int display = 0;
    for (int i = 0; i < count; i++) {
        int result = strcmp(member[i].licensePlate, plateToDisplay);
        if (result == 0) {
            printf("ID: %s, Ten: %s, So phong: %s, Bien so xe: %s\n", member[i].UID, member[i].name, member[i].roomNumber, member[i].licensePlate);
            getch();
            display = 1;
        }
    }

    fclose(file);

    if (display == 0) {
        printf("Khong tim thay cu dan voi bien so xe %s", plateToDisplay);
    }
    Sleep(3000);
    system("cls");
}

void menu() {
    printf("---QUAN LY CU DAN---\n");
    printf("--------------------\n");
    printf("1. Them thong tin cu dan\n");
    printf("2. Xoa thong tin cu dan\n");
    printf("3. Chinh sua thong tin cu dan\n");
    printf("4. Tim kiem thong tin cu dan bang UID\n");
    printf("5. Tim kiem thong tin cu dan bang bien so xe\n");
    printf("0. Thoat chuong trinh\n");
}


int main() {
    int option;
    char* file_name = "residentData.csv";
    
    do {
        menu();
        printf("Chon chuc nang: ");
        scanf("%d", &option);
        system("cls");

        switch (option) {
        case 1:
            addMember(file_name);
            break;
        case 2:
            deleteMember(file_name);
            break;
        case 3:
            editMember(file_name);
            break;
        case 4:
            searchByUID(file_name);
            break;
        case 5:
            searchByPlate(file_name);
            break;
        case 0:
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Chon sai chuc nang!!!\n");
            break;
        }
    } while(option != 0);

    return 0;
}