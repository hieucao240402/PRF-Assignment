#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_LENGTH 100

int n;

void createDataArray(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int n);
void displayDataArray(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int n);
void search(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int n, char searchName[]);
void addSubject(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int *n);
void deleteSubject(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int *n);

int main() {
    char name[MAX_ENTRIES][MAX_LENGTH];
    char description[MAX_ENTRIES][MAX_LENGTH];
    char nameSearch[MAX_LENGTH];

    printf("Enter number of entries: ");
    scanf("%d", &n);

    createDataArray(name, description, n);
    displayDataArray(name, description, n);

    printf("Enter search name: ");
    scanf("%s", nameSearch);

    search(name, description, n, nameSearch);

    addSubject(name, description, &n);
    displayDataArray(name, description, n);

    deleteSubject(name, description, &n);

    displayDataArray(name, description, n);

    return 0;
}
//  Câu 1: Tạo mảng dữ liệu
void createDataArray(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%s", name[i]);
        printf("Enter description: ");
        scanf("%s", description[i]);
    }
}
//  Câu 3: Hiển thị mảng dữ liệu
void displayDataArray(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", name[i]);
        printf("Description: %s\n", description[i]);
    }
}
//  Câu 6: Tìm kiếm
void search(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int n, char searchName[]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(name[i], searchName) == 0) {
            printf("Name: %s\n", name[i]);
            printf("Description: %s\n", description[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Name not found\n");
    }
}
//  Câu 4: Thêm subject
void addSubject(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int *n) {
    if (*n < MAX_ENTRIES) {
        printf("Enter name you wanna add: ");
        scanf("%s", name[*n]);
        printf("Enter description you wanna add: ");
        scanf("%s", description[*n]);
        (*n)++;
    } else {
        printf("Cannot add more subjects. Maximum entries reached.\n");
    }
}

//  Câu 8: Xóa subject ở mảng theo tên cần tìm
void deleteSubject(char name[][MAX_LENGTH], char description[][MAX_LENGTH], int *n) {
    char nameDelete[MAX_LENGTH];
    int found = -1;
    printf("Enter name to deleteL ");
    scanf("%s", nameDelete);
    // if (nameDelete == name[*n]){
        for(int i = 0; i < *n; i++){
            if(strcmp(name[i], nameDelete) == 0){
                found = i;
                break;
            }
        }
        if (found != -1) {
        for (int i = found; i < *n - 1; i++) {
            strcpy(name[i], name[i + 1]);
            strcpy(description[i], description[i + 1]); 
        }  
        (*n)--;
            }
        }   
        


        
    
    


